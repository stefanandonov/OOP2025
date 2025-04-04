#include <iostream>

using namespace std;
class StaticExample {
private:
    int myThing;
    static int everyoneThing;
public:

    StaticExample () {
        myThing = 100;
    }

    StaticExample (int myThing){
        this->myThing = myThing;
        everyoneThing++;
    }

    void print () {
        cout << "Mine: " << myThing << " Everyone's:" << everyoneThing << endl;
    }
};

int StaticExample::everyoneThing = 0;

int main() {

    StaticExample examples[11];
    for (int i=0;i<10;i++){
        examples[i] = StaticExample(i*288);
    }

    for (int i = 0; i < 10; ++i) {
        examples[i].print();
    }

    examples[10] = StaticExample(55555);
    for (int i = 0; i < 11; ++i) {
        examples[i].print();
    }
    
    return 0;
}
