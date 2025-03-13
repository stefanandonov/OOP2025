//
// Created by Stefan Andonov on 13.3.25.
//

#include<iostream>

using namespace std;

class Boy {
private:
    char fullName[50];
    int age;
public:
    Boy(char _fullName[] = "No name", int _age = 18) {  //2in1 nescafe
        strcpy(fullName, _fullName);
        age = _age;
    }

    void print (){
        cout << "Boy: " << fullName << " Age: " << age << endl;
    }

    const char *getFullName() const {
        return fullName;
    }

    int getAge() const {
        return age;
    }
};


class Girl {
private:
    char fullName[50];
    int age;
public:
    Girl(char _fullName[] = "No name", int _age = 18) {  //2in1 nescafe
        strcpy(fullName, _fullName);
        age = _age;
    }

    void print (){
        cout << "Girl: " << fullName << " Age: " << age << endl;
    }

    const char *getFullName() const {
        return fullName;
    }

    int getAge() const {
        return age;
    }
};

class Date {
private:
    Boy boy;
    Girl girl;
    int counter;
public:
    Date(const Boy &boy = Boy(), const Girl &girl = Girl(), int counter = 1) : boy(boy), girl(girl), counter(counter) {}

    void print(){
        cout << "Date between: " << endl;
        boy.print();
        cout << "&" << endl;
        girl.print();
        cout << "Count of the date: " << counter << endl;
        if (isMatch()){
            cout << "Good match" << endl;
        } else {
            cout << "Not a match :(" << endl;
        }
    }

    bool isMatch (){
        int diff = abs(boy.getAge() - girl.getAge());
        return diff <= 5 || counter>=3;
    }
};

int main() {

    Boy boy;
    boy.print();

    Boy boy2 ("Petko", 28);
    boy2.print();

    Boy boy3("Vlatko");
    boy3.print();

    Girl girl;
    girl.print();

    Girl girl2("Ana");
    girl2.print();

    Girl girl3("Angela", 30);
    girl3.print();

    Date date;
    date.print();

    Date date2(boy2, girl3);
    date2.print();

    return 0;
}
