//
// Created by Stefan Andonov on 4.4.25.
//


#include<iostream>
using namespace std;

class Student {
    int index;
    double averageGrade;

public:
    Student(int index = 151020, double averageGrade = 9.0) : index(index), averageGrade(averageGrade) {

    }

    double getAverageGrade() const {
        return averageGrade;
    }

    void print () {
        cout << index << ": " << averageGrade << endl;
    }
};

class Faculty {
private:
    Student students[100];
    int n;
public:
    Faculty(){
        n = 0;
    }

    void addStudent (const Student & student) {
        if (n==100){
            return ;
        }

        int pos = n;
        for (int i=0;i<n;i++){
            if (student.getAverageGrade() <= students[i].getAverageGrade()){
                pos = i;
                break;
            }
        }

        for (int i=n;i>pos;i--){
            students[i]=students[i-1];
        }

        students[pos]=student;
        n++;

    }

    void print ()  {
        for (int i=0;i<n;i++){
            students[i].print();
        }
    }
};

int main () {
    Faculty f;
    f.addStudent(Student(100, 8.2));
    f.addStudent(Student(101, 9.5));
    f.addStudent(Student(102, 7.8));
    f.addStudent(Student(105, 8.2));
    f.addStudent(Student(103, 8.5));
    f.print();
    return 0;
}
