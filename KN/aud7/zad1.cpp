//
// Created by Stefan Andonov on 23.4.25.
//


#include<iostream>

using namespace std;

class Student {
private:
    int id;
    char *name;
    int *grades;
    int capacity;
    int n;

    void copy(const Student &other) {
        this->id = other.id;
        this->n = other.n;
        this->capacity = other.capacity;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->grades = new int[this->capacity];
        for (int i = 0; i < n; i++) {
            this->grades[i] = other.grades[i];
        }
    }

public:
    Student(int id = 151020, char *name = "Stefan Andonov") {
        this->id = id;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->capacity = 10;
        this->grades = new int[capacity];
        this->n = 0;
    }

    Student(const Student &other) {
        copy(other);
    }

    Student &operator=(const Student &other) {
        if (this != &other) {
            delete[] grades;
            delete[] name;
            copy(other);
        }
        return *this;
    }

    Student &operator+=(int grade) {
        if (n == capacity) {
            //TODO extend the grades arrays
            int * tmp = new int [2*capacity];
            for (int i=0; i < n; i++){
                tmp[i]=grades[i];
            }
            delete [] grades;
            grades = tmp;
            capacity*=2;
        }
        grades[n]=grade;
        n++;

        return *this;
    }

    double average () const {
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += grades[i];
        }
        if (n==0){
            return 5.0;
        }
        return sum / n;
    }

    friend ostream &operator<<(ostream &out, const Student &student) {
        out << student.id << " " << student.name<< " " << student.n << "( out of possible " << student.capacity<<") " << " " << student.average();
        return out;
    }


};

class Faculty {
private:
    Student * students;
    int n;
public:
    Faculty() {
        n = 0;
        students = new Student [n];
    }

    Faculty & operator += (const Student & s){
        Student * tmp = new Student [n+1];
        for (int i=0;i<n;i++){
            tmp[i] = students[i];
        }
        tmp[n++] = s;
        delete [] students;
        students = tmp;
        return * this;
    }

    friend ostream &operator<<(ostream &out, const Faculty &faculty) {
        for (int i=0;i<faculty.n;i++){
            out << faculty.students[i] << endl;
        }

        return out;
    }
};

int main() {
    Student s;
//    cout << s << endl;

    for (int i=0;i<40;i++){
        s+=(i%6+5);
    }

    Student s2;
    for (int i=0;i<18;i++){
        s2+=(i%3+8);
    }

    Faculty faculty;
    faculty+=s;
    faculty+=s2;

    cout << faculty;


    return 0;
}