//
// Created by Stefan Andonov on 15.5.25.
//


#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class StudentFailedException {
private:
    string id;
public:
    StudentFailedException(const string & id){
        this->id = id;
    }

    void message() {
        cout << "Student with id "<< id <<" failed the course";
    }
};

class Student {
private:
    string id;
    string name;
    string lastName;
    int point;
public:
    Student(const string &id = "111111", const string &name = "", const string &lastName = "", int point = 0) : id(id),
                                                                                                                name(name),
                                                                                                                lastName(
                                                                                                                        lastName),
                                                                                                                point(point) {

    }

    int grade() const {
        if (point >= 90) {
            return 10;
        } else if (point >= 80) {
            return 9;
        } else if (point >= 70) {
            return 8;
        } else if (point >= 60) {
            return 7;
        } else if (point >= 50) {
            return 6;
        } else {
            return 5;
        }
    }

    friend ostream &operator<<(ostream &out, const Student &s) {
        //151020 Stefan Andonov 89 Grade: 9
        return out << s.id << " " << s.name << " " << s.lastName << " " << s.point << " " << s.grade();
    }

    friend istream & operator >> (istream & in, Student & s){
        in >> s.id >> s.name >> s.lastName >> s.point;
        return in;
    }

    friend class Results;
};

class Results {
    Student students[100];
    int n;
public:
    Results() {
        n = 0;
    }

    Results &operator+=(const Student &s) {
//        if (s.point<50)
        if (s.grade() == 5) {
            throw StudentFailedException(s.id);
        }

        students[n] = s;
        n++;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Results &results) {
        for (int i = 0; i < results.n; i++) {
            out << results.students[i] << endl;
        }
        return out;
    }
};

int main() {
    string id;
    string name;
    string lastName;
    int point;

    Results results;
    ifstream in ("/Users/stefanandonov/CLionProjects/OOP2025/KN/aud10/input.txt");

    Student s;
    while (!in.eof()) {
        getline(in, id);
        getline(in, name);
        getline(in, lastName);
        in >> point;
        in.ignore();
        try {
            s = Student(id, name, lastName, point);
            results += s;
        } catch (StudentFailedException & e){
            e.message();
        }
    }

    in.close();

    ofstream out ("/Users/stefanandonov/CLionProjects/OOP2025/KN/aud10/output.txt");
    out << results;
    out.close();
    return 0;
}