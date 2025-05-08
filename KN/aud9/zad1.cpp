//
// Created by Stefan Andonov on 8.5.25.
//

#include<iostream>

using namespace std;

class Animal {
protected:
    string name;
    int age;
public:
    Animal(const string &name, int age) {
        this->name = name;
        this->age = age;
    }

    virtual void sound() = 0; //pure-virtual, therefore the class is now abstract

    virtual void print() {
        cout << name << " " << age << endl;
    }

    friend Animal * youngestDog(Animal **animals, int n);

};

class Cat : public Animal {
public:
    Cat(const string &name, int age) : Animal(name, age) {

    }

    void sound() {
        cout << "MJAUUUU" << endl;
    }

    void print() {
        cout << "Cat ";
        Animal::print();
    }
};


class Dog : public Animal {
public:
    Dog(const string &name, int age) : Animal(name, age) {

    }

    void sound() {
        cout << "AF AF AF" << endl;
    }

    void print() {
        cout << "Dog ";
        Animal::print();
    }
};

Animal * youngestDog(Animal **animals, int n) {
    Animal *min = nullptr;

    for (int i = 0; i < n; i++) {
        if (dynamic_cast<Dog *>(animals[i])) {
            if (min == nullptr || animals[i]->age < min->age){
                min = animals[i];
            }
        }
    }

    return min;
}

int main() {
    int N;
    cin >> N;
    Animal **animals = new Animal *[N];

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

    cout << "Youngest dog: " << endl;
    youngestDog(animals,N)->print();

    return 0;
}

