#include <iostream>
#include<cstring>
#include<iomanip>

using namespace std;

class Date {
private:
    int d,m,y;
public:
    Date (int d = 1, int m = 1, int y = 2025){
        this->d = d;
        this->m = m;
        this->y = y;
    }

    void print () {
        cout << setfill('0') << setw(2) << d << "/" << setfill('0') << setw(2) << m << "/" << y;

    }

    bool isAfter (Date & other){
        if (this->y > other.y){
            return true;
        } else if (this->y < other.y){
            return false;
        } else { //this->y == other.y pr 2014 == 2014
            if (this->m > other.m){
                return true;
            } else if (this->m < other.m){
                return false;
            } else { //this->y == other.y && this->m == other.m 02.2014==02.2014
                return this->d > other.d;
            }
        }
    }
};

class SMS {
private:
    Date date;
    char content [151];
    char sender [11];
    char receiver [11];
public:
    SMS (Date date = Date(), char sender[11] = "", char receiver[11] = "", char content[151] = ""){
        this->date = date;
        strcpy(this->content, content);
        strcpy(this->sender, sender);
        strcpy(this->receiver, receiver);
    }

    void print () {
        date.print();
        cout << " " << sender << " " << receiver << " " << content << endl;
    }

    Date &getDate() {
        return date;
    }

    const char *getContent() const {
        return content;
    }

    const char *getSender() const {
        return sender;
    }

    const char *getReceiver() const {
        return receiver;
    }

    int getMessageLength(){
        return strlen(content);
    }

};

void filterMessages (SMS messages[100], int n, Date & filter) {
    int counter = 0;
    for (int i=0;i<n;i++){
        if (messages[i].getMessageLength()<70 && messages[i].getDate().isAfter(filter)){
            messages[i].print();
            ++counter;
        }
    }

    if (counter==0){
        cout << "No SMS satisfy the given condition.";
    }
}



int main() {
    int n;
    cin >> n;

    int d,m,y;
    char content [151];
    char sender [11];
    char receiver [11];

    SMS messages [100];

    for (int i=0;i<n;i++){
        cin >> d >> m >> y >> sender >> receiver;
        cin.ignore();
        cin.getline(content, 150);
        Date date (d,m,y);
        messages[i] = SMS(date, sender, receiver, content);
    }


    cin >> d >> m >> y;
    Date filter (d,m,y);

    filterMessages(messages, n, filter);
}