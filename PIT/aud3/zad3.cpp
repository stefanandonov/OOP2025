//
// Created by Stefan Andonov on 12.3.25.
//

#include<iostream>
#include <cstring>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int day = 1, int month = 1, int year = 2025) : day(day), month(month), year(year) {}

    void print (){
        cout << day << "."<< month << "." << year << endl;
    }

};

class Employee {
    char name [20];
    double salary;
    Date dob; //date of birth
public:
    Employee(char * _name = "", double _salary = 0, Date _dob = Date()){
        strcpy(name, _name);
        salary = _salary;
        dob = _dob;
    }

    void print (){
        cout << "Employee: " << name << " Salary: " << salary << " Date of birth: ";
        dob.print();
    }

    const char *getName() const {
        return name;
    }

    double getSalary() const {
        return salary;
    }

    const Date &getDob() const {
        return dob;
    }
};

Employee & employeeWithHighestSalary (Employee * employees, int n){

    int idxMax = 0;
    double maxSalary = employees[idxMax].getSalary();
    for (int i=1;i<n;i++){
        if (employees[i].getSalary() > maxSalary){
            idxMax = i;
            maxSalary = employees[i].getSalary();
        }
    }

    return employees[idxMax];
}

int main (){

    int n;
    cin >> n;

    char name [20];
    double salary;
    int day;
    int month;
    int year;

    Employee employees [10];

    for (int i=0;i<n;i++){
        cin >> name >> salary >> day >> month >> year;
        //Stefan 40000 8 1 1997
//        Employee e (name, salary, Date(day, month, year));
        employees[i]=Employee(name, salary, Date(day, month, year));
    }

    for (int i = 0; i < n; ++i) {
        employees[i].print();
    }

    cout << "Highest payed employee" << endl;
    employeeWithHighestSalary(employees, n).print();
    return 0;
}

