//
// Created by Stefan Andonov on 8.5.25.
//

#include<iostream>

using namespace std;

class Student {
protected:
    string id;
    double averageGrade;
public:
    Student(const string &id, double averageGrade) : id(id), averageGrade(averageGrade) {}

    void print() {
        cout << "ID: " << id << " Average: " << averageGrade;
    }
};

class LabStaff {
protected:
    int slotsWeekly;
    int courses;
public:
    LabStaff(int s, int c) {
        slotsWeekly = s;
        courses = c;
    }

    virtual void print() {
        cout << "Slots weekly: " << slotsWeekly << " Courses: " << courses << " Salary: " << salary();
    }

    virtual double salary() {
        double base = slotsWeekly / 6.0 * 600;
        if (courses>2){
            base*=1.1;
        }
        return base;
    }
};

class Tutor : public Student, public LabStaff {
public:
    Tutor(const string &id, double averageGrade, int s, int c) : Student(id, averageGrade), LabStaff(s, c) {

    }

    void print () {
        cout << "Tutor ";
        Student::print();
        cout << " ";
        LabStaff::print();
    }

    double salary() {
        if (averageGrade==10.0){
            return LabStaff::salary() * 1.1;
        } else {
            return LabStaff::salary();
        }
    }


};

int main() {
    LabStaff * tutor = new Tutor("151020", 10.0, 5, 3);
    tutor->print();
    return 0;
}
