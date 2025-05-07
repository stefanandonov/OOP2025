//
// Created by Stefan Andonov on 7.5.25.
//

#include<iostream>
using namespace std;

class Student {
protected:
    string id;
    double averageGrade;
public:
    Student(const string &id, double averageGrade) : id(id), averageGrade(averageGrade) {}

    void print () {
        cout << "ID: " << id << " Average grade: " << averageGrade << " ";
    }

};

class LabStaff{
protected:
    int hoursWeekly;
    int courses;
public:
    LabStaff (int h, int c) {
        hoursWeekly = h;
        courses = c;
    }

    virtual double salary () {
        double baseSalary =  hoursWeekly / 6.0 * 600;
        if (courses>2){
            baseSalary *= 1.1;
        }
        return baseSalary;
    }

    virtual void print () {
        cout << "Hours: " << hoursWeekly << " Courses: " << courses << " Salary: " << salary();
    }
};

class Tutor : public Student, public LabStaff {
public:
    Tutor(const string &id, double averageGrade, int h, int c) : Student(id, averageGrade), LabStaff(h, c) {

    }

    double salary() override {
        double base = LabStaff::salary();
        if (this->averageGrade>=9.5){
            base *= 1.1;
        }
        return base;
    }

    void print () override {
        Student::print();
        LabStaff::print();
    }
};

int main () {

    LabStaff * tutor = new Tutor("151020", 9.38, 5, 3);
    cout << tutor->salary() << endl;
    tutor->print();

    return 0;
}