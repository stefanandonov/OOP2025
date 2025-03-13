//
// Created by Stefan Andonov on 13.3.25.
//

#include<iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int day = 1, int month = 1, int year = 1990) : day(day), month(month), year(year) {}

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    void print () {
        cout << day << "." << month << "." << year << endl;
    }

    bool isBefore (Date other) const {
        if (year < other.year){
            return true;
        } else if (year > other.year) {
            return false;
        } else { //year == other.year
            if (month < other.month){
                return true;
            } else if (month > other.month){
                return false;
            } else { //month == other.month
                if (day <= other.day){
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
};

class Employee {
private:
    char name [100];
    double salary;
    Date dateOfBirth;
    Date startDate;
public:
    Employee(char *_name = "noname", double salary = 21000, const Date &dateOfBirth = Date(), const Date &startDate = Date(13,3,2025)) : salary(salary),
                                                                                          dateOfBirth(dateOfBirth),
                                                                                          startDate(startDate) {
        strcpy(name, _name);
    }

    void print () {
        cout << "Name: " << name << endl << "Salary: " << salary << endl;
        cout << "Date of birth: ";
        dateOfBirth.print();
        cout << "Start date: ";
        startDate.print();
    }

    const char *getName() const {
        return name;
    }

    double getSalary() const {
        return salary;
    }

    const Date &getDateOfBirth() const {
        return dateOfBirth;
    }

    const Date &getStartDate() const {
        return startDate;
    }
};


Employee firstEmployee (Employee * employees, int n){
    Employee first = employees[0];
    for (int i=1;i<n;i++){
        if (employees[i].getStartDate().isBefore(first.getStartDate())){
            first = employees[i];
        }
    }
    return first;
}


Employee highestSalaryEmployee (Employee * employees, int n){
//    int array [100];
//
//    int max = array[0];
//    for (int i=0;i<n;i++){
//        if (array[i]>max){
//            max = array[i];
//        }
//    }

    Employee max = employees[0];
    for (int i=1;i<n;i++){
        if (employees[i].getSalary() > max.getSalary()){
            max = employees[i];
        }
    }
    return max;
}

int main (){

    int n;
    cin >> n;
    cin.ignore();

    Employee employees [10];
    char name [100];
    double salary;
    int d,m,y;

    for (int i=0;i<n;i++){
        cin.getline(name, 100);
        cin >> salary;
        cin >> d >> m >> y;
        Date dob (d,m,y);
        cin >> d >> m >> y;
        Date start (d,m,y);

        employees[i] = Employee(name, salary, dob, start);
        cin.ignore();

    }

//    for (int i=0;i<n;i++){
//        employees[i].print();
//    }

    cout << "Highest salary employee: " << endl;
    highestSalaryEmployee(employees, n).print();
//    Employee result = highestSalaryEmployee(employees, n);
//    result.print();

    cout << "First employee in the company: " << endl;
    firstEmployee(employees, n).print();


    return 0;
}
