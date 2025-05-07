//
// Created by Stefan Andonov on 7.5.25.
//

#include<iostream>
#include <cstring>
using namespace std;




class QuizAttempt {
protected:
    char ID [7];
public:
    QuizAttempt(char * ID) {
        strcpy(this->ID, ID);
    }

    virtual double score() = 0;
    virtual void print() = 0;

    bool operator >= (QuizAttempt & other){
        return this->score() >= other.score();
    }
};




class MCQuizAttempt : public QuizAttempt{
private:
    char correctAnswers[11];
    char studentsAnswers[11];
public:
    MCQuizAttempt(char * ID, char * correctAnswers, char * studentsAnswers) : QuizAttempt(ID){
        strcpy(this->correctAnswers, correctAnswers);
        strcpy(this->studentsAnswers, studentsAnswers);
    }


    double score() {
        double sum = 0;
        for (int i=0;i<10;i++){
            if (correctAnswers[i]==studentsAnswers[i]){
                sum+=1.0;
            } else {
                sum-=0.25;
            }
        }
        return sum;
    }

    void print() {
        for (int i=0;i<10;i++){
            // Points: 1
            cout << i+1 << ". Correct: " << correctAnswers[i] << " Answer: " << studentsAnswers[i] << " Points: ";
            if (correctAnswers[i]==studentsAnswers[i]){
                cout << "1";
            } else {
                cout << "-0.25";
            }
            cout << endl;
        }
        cout << "Total score: " << score() << endl;
    }


};

class TFQuizAttempt : public QuizAttempt{
private:
    bool correctAnswers[10];
    bool studentsAnswers[10];
public:
    TFQuizAttempt(char * ID, bool * correctAnswers, bool * studentsAnswers) : QuizAttempt(ID){
        for (int i=0;i<10;i++){
            this->correctAnswers[i]=correctAnswers[i];
            this->studentsAnswers[i]=studentsAnswers[i];
        }
    }

    double score() {
        double sum = 0;
        for (int i=0;i<10;i++){
            if (correctAnswers[i]==studentsAnswers[i]){
                sum+=1.0;
            } else {
                sum-=0.5;
            }
        }
        return sum;
    }

    void print() {
        for (int i=0;i<10;i++){
            // Points: 1
            cout << i+1 << ". Correct: " << correctAnswers[i] << " Answer: " << studentsAnswers[i] << " Points: ";
            if (correctAnswers[i]==studentsAnswers[i]){
                cout << "1";
            } else {
                cout << "-0.5";
            }
            cout << endl;
        }
        cout << "Total score: " << score() << endl;
    }


};





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

double averagePointsOfPassedStudents (QuizAttempt ** attempts, int n) {
    double sumPoints = 0;
    int passedStudents = 0;

    for (int i=0;i<n;i++){
        if ((attempts[i])->score() >= 5.0){
            sumPoints+=attempts[i]->score();
            ++passedStudents;
        }
    }

    return sumPoints/passedStudents;

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