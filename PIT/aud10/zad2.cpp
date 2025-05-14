//
// Created by Stefan Andonov on 14.5.25.
//

#include<iostream>
#include<fstream>
using namespace std;


class IdNotValidException {
private:
    string id;
public:
    IdNotValidException(string id){
        this->id = id;
    }

    void message() {
        cout << "ID " << this->id << " is not valid";
    }
};


class StudentFailedException {
private:
    string id;
public:
    StudentFailedException(string id){
        this->id = id;
    }

    void message() {
        cout << "The student with ID " << this->id << " has failed and can't be added to the results" << endl;
    }
};

class Student {
private:
    string id;
    string name;
    string lastName;
    int point;
public:
    Student(const string &id = "123123", const string &name = "", const string &lastName = "", int point = 0) : id(id), name(name),
                                                                                       lastName(lastName),
                                                                                       point(point) {
        if (id.size()!=6){
            throw IdNotValidException(id);
        }
    }

    int grade() const {
        if (point>=90){
            return 10;
        } else if (point>=80){
            return 9;
        } else if (point>=70){
            return 8;
        } else if (point>=60){
            return 7;
        } else if (point>=50){
            return 6;
        } else {
            return 5;
        }
    }
    friend ostream & operator << (ostream & out, const Student & s){
        //151020 Stefan Andonov 89 Grade: 9
        out << s.id << " " << s.name << " " << s.lastName << " " << s.point << " Grade: " <<s.grade();
        return out;
    }

    friend istream & operator >> (istream & in, Student & s){
        getline(in, s.id);
        getline(in, s.name);
        getline(in, s.lastName);
        in >> s.point;
        in.ignore();
        return in;
    }

    friend class Results;
};

class Results {
private:
    Student students[100];
    int n;
public:
    Results() {
        n = 0;
    }

    Results & operator += (const Student & s){
        if (s.grade()==5){
            StudentFailedException e(s.id);
            throw e;
        }

        students[n]=s;
        n++;
        return *this;
    }

    friend ostream & operator << (ostream & out, const Results & r){
        for (int i=0;i<r.n;i++){
            out << r.students[i] << endl;
        }
        return out;
    }
};

int main (){


    string id;
    string name;
    string lastName;
    int point;

    Results results;

    ifstream in ("/Users/stefanandonov/CLionProjects/OOP2025/PIT/aud10/students.txt");

    Student s;
    while (in >> s){
        try {
            results+=s;
        } catch (StudentFailedException & e) {
            //moze da si igrame so topkata
            e.message();
        } catch (IdNotValidException & e){
            e.message();
        }
    }

    in.close();

    ofstream out ("/Users/stefanandonov/CLionProjects/OOP2025/PIT/aud10/output.txt");

    out << results;

    out.close();
    return 0;
}