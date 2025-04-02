#include <iostream>
#include <cctype>

using namespace std;

class Letter {
private:
    char ch;
public:
    Letter (char ch = 'a'){
        this->ch = ch;
    }

    void upperLetter(){
        if (isalpha(ch)){
            ch = toupper(ch);
        } else {
            cout << "Character is not a letter";
        }
    }

    char get() {
        return ch;
    }
};


int main() {
    Letter obj;
    int n;
    cin >> n;
    int cmd;
    char k;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        switch (cmd) {
            case 1: {
                cin >> k;
                obj = Letter(k);
                cout << obj.get() << endl;
                break;
            }
            case 2: {
                obj.upperLetter();
                cout << obj.get() << endl;
                break;
            }
            case 3: {
                cin >> k;
                Letter obj2(k);
                obj2.upperLetter();
                cout << obj2.get() << endl;
                break;
            }
            default: {
                cout << obj.get() << endl;
                break;
            }
        }
    }
}