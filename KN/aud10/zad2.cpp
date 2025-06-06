//
// Created by Stefan Andonov on 15.5.25.
//


#include<iostream>
#include<string>
using namespace std;


class Vehicle {
protected:
    double speed;
public:
    Vehicle(double speed = 10) {
        cout << "Vehicle constructor called" << endl;
        this->speed = speed;
    }

    virtual void accelerate () = 0; //pure-virtual --> class is abstract

    virtual void print (){
        cout << "Speed: " << speed << "km/h" << endl;
    }
};

class Car : virtual public Vehicle {
public:
    Car(double speed = 10) : Vehicle(speed){
        cout << "Car constructor" << endl;
    }

    void accelerate () {
        speed*=1.05;
    }

    void print () {
        cout << "Car ";
        Vehicle::print();
    }
};

class Jet : virtual public Vehicle {
public:
    Jet(double speed = 10) : Vehicle(speed){
        cout << "Jet constructor" << endl;
    }

    void accelerate () {
        speed*=1.10;
    }

    void print () {
        cout << "Jet ";
        Vehicle::print();
    }
};

class JetCar: public Car, public Jet {
public:
    JetCar (double speed) : Vehicle(speed), Jet(speed), Car(speed) {
        cout << "JetCar constructor" << endl;
    }


    void accelerate () {
        this->speed*=1.08;
    }

    void print () {
        cout << "JetCar";
        Vehicle::print();
    }
};

int main (){

    Vehicle * vehicles[3];
    vehicles[0] = new Car(100);
    vehicles[1] = new Jet(1000);
    vehicles[2] = new JetCar(500);

    for (int i=0;i<3;i++){
        vehicles[i]->print();
    }

    for (int i=0;i<3;i++){
        vehicles[i]->accelerate();
    }

    for (int i=0;i<3;i++){
        vehicles[i]->print();
    }

//    JetCar jc (500);
//    jc.print();
//    jc.accelerate();
//    jc.print();


    return 0;
}