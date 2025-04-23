//
// Created by Stefan Andonov on 23.4.25.
//

#include<iostream>
#include<cstring>

using namespace std;

class DebitAccount {
protected:
    char *owner;
    string number;
    double balance;
public:
    DebitAccount(char *owner = "Stefan", const string &number = "123123123123123", double balance = 0) : number(number),
                                                                                                         balance(balance) {
        this->owner = new char[strlen(owner) + 1];
        strcpy(this->owner, owner);
    }

    virtual void print() {
        cout << owner << " [" << number << "] " << balance << endl;
    }

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }
};

class StudentMealAccount : public DebitAccount {
private:
    static int WEEKLY_AMOUNT;
public:
    StudentMealAccount(char *owner = "Stefan", const string &number = "123123123123123", double balance = 0)
            : DebitAccount(owner, number, balance) {

    }

    void print() override {
        cout << "Student Meal Card ";
        DebitAccount::print();
    }

    void deposit(double amount) override {
        if (amount > WEEKLY_AMOUNT) {
            return;
        }

        this->balance = amount;
    }

    bool withdraw(double amount) override {
        return DebitAccount::withdraw(amount);
    }


};

int StudentMealAccount::WEEKLY_AMOUNT = 840;


class CreditCard : public DebitAccount {
private:
    double limit;
    double minus;
    double interest; //0.01
public:
    CreditCard(char *owner = "Stefan", const string &number = "123123123123123", double balance = 0,
               double limit = 10000, double minus = 0, double interest = 0.01) : DebitAccount(owner, number, balance) {
        this->limit = limit;
        this->minus = minus;
        this->interest = interest;
    }

    void print() override {
        cout << "Credit card ";
        DebitAccount::print();
        cout << "Limit: " << limit << " Minus: " << minus << " Interest rate: " << interest << endl;
    }


    bool withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            return true;
        } else if (amount - balance + minus < limit){
            minus+=((amount-balance)*(1+interest));
            balance = 0;
            return true;
        } else {
            return false;
        }
    }

};


int main() {
    DebitAccount da;

    da.deposit(5000);
    da.print();
    cout << da.withdraw(1000) << endl;
    da.print();

    StudentMealAccount sma("Petko", "111111", 840);
    sma.print();
    sma.withdraw(500);
    sma.print();
    sma.deposit(700);
    sma.print();
    sma.withdraw(900);
    sma.print();


    CreditCard cc;
    cc.print();
    cc.deposit(1000);
    cc.print();
    cc.withdraw(9000);
    cc.print();
    return 0;
}
