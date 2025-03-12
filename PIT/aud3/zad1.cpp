//
// Created by Stefan Andonov on 12.3.25.
//

#include<iostream>
#include<cstring>
using namespace std;

class Boy {
private:
    char name [100];
    int age;
public:
    Boy (char * _name = "Stefan", int _age = 28){ //2in1 nescafe
        strcpy(name, _name);
        age = _age;
    }

    void print (){
        cout << "Boy: " << name << " Age: " << age << endl;
    }

    const char *getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

};


class Girl {
private:
    char name [100];
    int age;
public:
    Girl (char * _name = "Stefanija", int _age = 19){ //2in1 nescafe
        strcpy(name, _name);
        age = _age;
    }

    void print (){
        cout << "Girl: " << name << " Age: " << age << endl;
    }

    const char *getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

};


class Date {
private:
    Boy boy;
    Girl girl;
public:
    Date(Boy _boy = Boy(), Girl _girl = Girl()) { //2in1
        boy = _boy;
        girl = _girl;
    }

    void print () {
        cout << "Date between:" << endl;
        boy.print();
        cout << " & " << endl;
        girl.print();
        if (isMatch()){
            cout << "They are a match" << endl;
        } else {
            cout << "They are not a match" << endl;
        }
    }

    bool isMatch (){
        int diff = abs(boy.getAge() - girl.getAge());
        return diff <= 5;
    }

};

int main (){

    Boy boy;
    boy.print();

    Boy boy2("Petko");
    boy2.print();

    Boy boy3 ("Trajce", 22);
    boy3.print();

    Girl girl;
    girl.print();

    Girl girl2 ("Ana", 30);
    girl2.print();

    Girl girl3 ("Tijana", 23);
    girl3.print();


    Date date;
    date.print();

    Date date2 (boy3);
    date2.print();

    Date date3 (boy2, girl2);
    date3.print();

    return 0;
}