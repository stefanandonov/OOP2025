//
// Created by Stefan Andonov on 7.5.25.
//

#include<iostream>
#include<cstring>

using namespace std;

class Animal {
protected:
    string name;
    int age;
public:
    Animal(const string &name, int age) : name(name), age(age) {}

    virtual void sound() = 0; //klasata stanuva abstract

    virtual void print() {
        cout << name << " " << age << endl;
    }
};

class Cat : public Animal {
public:
    Cat(const string &name, int age) : Animal(name, age) {}

    void sound() override {
        cout << "MJAUUUUUUUMJAUUU" << endl;
    }

    void print() override {
        cout << "Cat ";
        Animal::print();
    }
};

class Dog : public Animal {
public:
    Dog(const string &name, int age) : Animal(name, age) {}

    void sound() override {
        cout << "AF AF AF AF" << endl;
    }

    void print() override {
        cout << "Dog ";
        Animal::print();
    }
};

int countCatsInZoo(Animal **animals, int n) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        Cat * casted = dynamic_cast<Cat *>(animals[i]);
        if (casted) {
            ++counter;
        }
    }
    return counter;
}

int main() {
    int N;
    cin >> N;

    Animal **animals = new Animal * [N];

    for (int i = 0; i < N; ++i) {
        string type, name;
        int age;
        cin >> type >> name >> age;

        if (type == "Dog") {
            animals[i] = new Dog(name, age);
        } else if (type == "Cat") {
            animals[i] = new Cat(name, age);
        } else {
            cout << "Unknown animal type!" << endl;
            --i; // retry the input for this index
            continue;
        }
    }

    for (int i = 0; i < N; ++i) {
        animals[i]->print();
        animals[i]->sound();
    }

    cout << "Cats in the zoo: " << countCatsInZoo(animals, N);

//    for (int i = 0; i < N; ++i) {
//        delete animals[i]; // cleanup
//    }

    return 0;
}
