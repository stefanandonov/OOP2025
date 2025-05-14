//
// Created by Stefan Andonov on 14.5.25.
//

#include<iostream>
using namespace std;

class Vehicle {
protected:
    string manufacturer;
    double speed;
public:
    Vehicle(const string &manufacturer, double speed) : manufacturer(manufacturer), speed(speed) {
        cout << "Vehicle constructor" << endl;
    }

    virtual void accelerate() = 0; //pure-virtual -> class is abstract
    virtual void print() = 0;
};

class Car : virtual public Vehicle {
public:
    Car(const string &manufacturer, double speed) : Vehicle(manufacturer, speed) {
        cout << "Car constructor" << endl;
    }

    void accelerate(){
        speed*=1.1;
    }

    void print(){
        cout << "Car " << manufacturer << " with speed " << speed << "km/h" << endl;
    }

};


class Jet : virtual public Vehicle {
public:
    Jet(const string &manufacturer, double speed) : Vehicle(manufacturer, speed) {
        cout << "Jet constructor" << endl;
    }

    void accelerate(){
        speed*=1.21;
    }

    void print(){
        cout << "Jet " << manufacturer << " with speed " << speed << "km/h" << endl;
    }

};

class JetCar : public Car, public Jet {
public:
    JetCar(const string &manufacturer, double speed) : Vehicle(manufacturer, speed), Jet(manufacturer, speed), Car(manufacturer, speed) {
        cout << "JetCar constructor" << endl;
    }

    void accelerate(){
        this->speed*=1.15;
    }

    void print(){
        cout << "JetCar " << this->manufacturer << " with speed " << this->speed << "km/h" << endl;
    }

};

int main (){

    Vehicle * vs[3];
    vs[0] = new Car("Toyota", 100);
    vs[1] = new Jet("Boeing", 1000);
    vs[2] = new JetCar("Boeing", 500);

    cout << "before acceleration" << endl;
    for (int i=0;i<3;i++){
        vs[i]->print();
    }


    for (int i=0;i<3;i++){
        vs[i]->accelerate();
    }

    cout << "after acceleration" << endl;
    for (int i=0;i<3;i++){
        vs[i]->print();
    }


    return 0;
}