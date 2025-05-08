//
// Created by Stefan Andonov on 8.5.25.
//

#include<iostream>

using namespace std;

string printBool(bool value) {
    if (value) {
        return "True";
    } else {
        return "False";
    }
}


class QuizAttempt {
protected:
    char ID[7];
public:

    QuizAttempt(char *ID = "151020") {
        strcpy(this->ID, ID);
    }

    virtual double score() = 0;

    virtual void print() = 0;

    bool operator>=(QuizAttempt &other) {
        return this->score() >= other.score();

    }
};

class MCQuizAttempt : public QuizAttempt {
private:
    char correct[11];
    char student[11];
public:
    MCQuizAttempt(char *ID, char *correct, char *student) : QuizAttempt(ID) {
        strcpy(this->correct, correct);
        strcpy(this->student, student);
    }

    double score() {
        double sum = 0;
        for (int i = 0; i < 10; i++) {
            if (correct[i] == student[i]) {
                sum += 1.0;
            } else {
                sum -= 0.25;
            }
        }
        return sum;
    }

    void print() {
        // Points: 1

        for (int i = 0; i < 10; i++) {
            cout << i + 1 << ". Correct: " << correct[i] << " Answer: " << student[i] << " Points: ";
            if (student[i] == correct[i]) {
                cout << "1";

            } else {
                cout << "-0.25";

            }
            cout << endl;
        }
        cout << "Total score: " << score();
    }
};

class TFQuizAttempt : public QuizAttempt {
private:
    bool correct[10];
    bool student[10];
public:
    TFQuizAttempt(char *ID, bool *correct, bool *student) : QuizAttempt(ID) {
        //NEEEE strcpy(this->student,student);
        for (int i = 0; i < 10; i++) {
            this->correct[i] = correct[i];
            this->student[i] = student[i];
        }
    }

    double score() {
        double sum = 0;
        for (int i = 0; i < 10; i++) {
            if (correct[i] == student[i]) {
                sum += 1.0;
            } else {
                sum -= 0.5;
            }
        }
        return sum;
    }

    void print() {
        for (int i = 0; i < 10; i++) {
            cout << i + 1 << ". Correct: " << printBool(correct[i]) << " Answer: " << (student[i] ? "True" : "False")
                 << " Points: ";
            if (student[i] == correct[i]) {
                cout << "1";

            } else {
                cout << "-0.5";

            }
            cout << endl;
        }
        cout << "Total score: " << score();
    }

};

double averagePointsOfPassedStudents(QuizAttempt **attempts, int n) {
    double sum = 0;
    int counter = 0;
    for (int i=0;i<n;i++){
        if (attempts[i]->score() >= 5.0){
            sum+=attempts[i]->score();
            ++counter;
        }
    }
    return sum/counter;
}

QuizAttempt *readMCQuizAttempt() {
    char ID[7];
    char correct[11];
    char answers[11];

    cin >> ID >> correct >> answers;
    return new MCQuizAttempt(ID, correct, answers);
}

QuizAttempt *readTFQuizAttempt() {
    char ID[7];
    bool correct[10];
    bool answers[10];
    cin >> ID;
    for (int i = 0; i < 10; i++) {
        cin >> correct[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> answers[i];
    }

    return new TFQuizAttempt(ID, correct, answers);
}


int main() {
    int testCase;

    cin >> testCase;

    if (testCase == 1) {
        cout << "Test MCQuizAttempt" << endl;
        QuizAttempt *attempt = readMCQuizAttempt();
        cout << "Score: " << attempt->score() << endl;
        attempt->print();
    } else if (testCase == 2) {
        cout << "Test TFQuizAttempt" << endl;
        QuizAttempt *attempt = readTFQuizAttempt();
        cout << "Score: " << attempt->score() << endl;
        attempt->print();
    } else if (testCase == 3) {
        cout << "Test operator >=" << endl;
        int n;
        cin >> n;
        QuizAttempt **attempts = new QuizAttempt *[n];
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                attempts[i] = readMCQuizAttempt();
            } else {
                attempts[i] = readTFQuizAttempt();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if ((*attempts[i]) >= (*attempts[j])) {
                        cout << i << " >= " << j << endl;
                    } else {
                        cout << i << " < " << j << endl;
                    }
                }
            }
        }
    } else {
        int n;
        cin >> n;
        QuizAttempt **attempts = new QuizAttempt *[n];
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                attempts[i] = readMCQuizAttempt();
            } else {
                attempts[i] = readTFQuizAttempt();
            }
            attempts[i]->print();
            cout << endl;
        }

        cout << "Average score of passed students is: " << averagePointsOfPassedStudents(attempts, n) << endl;
    }

    return 0;
}