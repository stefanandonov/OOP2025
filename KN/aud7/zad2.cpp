//
// Created by Stefan Andonov on 23.4.25.
//


#include<iostream>
#include<cstring>
using namespace std;

class DebitCard {
protected:
    string owner;
    string number;
    double balance;
public:
    DebitCard(const string &owner = "Stefan", const string &number = "123123123123123", double balance = 0) : owner(owner), number(number),
                                                                           balance(balance) {}

    void print () {
        cout << "Card for user " << owner << " with account number " << number << " has balance of " << balance;
    }

    bool deposit (double amount){
        balance += amount;
        return true;
    }

    bool withdraw (double amount) {
        if (amount <= balance){
            balance-=amount;
            return true;
        } else {
            return false;
        }
    }

};

class StudentMealCard : public DebitCard {
private:
    static int WEEKLY_ALLOWANCE;
    static int DAILY_ALLOWANCE;
public:
    StudentMealCard(const string &owner = "Stefan", const string &number = "123123123123123", double balance = 0) : DebitCard(owner, number, balance) {

    }

    void print() {
        cout << "Student Meal ";
        DebitCard::print();
    }

    bool deposit(double amount) {
        if (amount>WEEKLY_ALLOWANCE){
            return false;
        } else {
            if ((int)amount%DAILY_ALLOWANCE!=0){
                return false;
            }
            balance = amount;
            return true;
        }
    }
};

int StudentMealCard::WEEKLY_ALLOWANCE = 840;
int StudentMealCard::DAILY_ALLOWANCE = 140;


class CreditCard : public DebitCard {
    double limit;
    double minus;
    double interest; //0.01 == 1%
public:
    CreditCard(const string &owner = "Stefan", const string &number = "123123123123123", double balance = 0, double limit = 5000, double minus = 0, double interest = 0.01) : DebitCard(owner, number, balance) {
        this->limit = limit;
        this->minus = minus;
        this->interest = interest;
    }

    void print() {
        cout << "Credit ";
        DebitCard::print();
        cout << "Limit: " << limit << " Minus: " << minus << " Interest rate: " << interest*100;
    }

    bool withdraw (double amount){
        if (balance>=amount){
            balance-=amount;
            return true;
        } else if (amount - balance + minus < limit){
            double advance = amount - balance;
            advance*=(1+interest);
            minus+=advance;
            balance = 0;
            return true;
        } else {
            return false;
        }
    }

    bool deposit (double amount){
        if (balance>0){
            balance+=amount;
        } else if (balance==0){
            if (amount<=minus){
                minus-=amount;
            } else {
                balance+=(amount- minus);
                minus=0;
            }
        }
        return true;
    }

};



int main () {

//    DebitCard dc;
//    dc.print();

    CreditCard cc;

    char op;
    double amount;

    while (cin >> op >> amount){
        if (op=='+'){
            cc.deposit(amount);
        } else {
            cc.withdraw(amount);
        }
        cc.print();
        cout << endl;
    }


    return 0;
}