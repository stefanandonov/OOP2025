//
// Created by Stefan Andonov on 23.4.25.
//

#include<iostream>

using namespace std;

class Array {
private:
    char *description;
    int *numbers;
    int size;
    int capacity;

    void copy(const Array &a) {
        this->description = new char[strlen(a.description) + 1];
        strcpy(this->description, a.description);
        this->size = a.size;
        this->capacity = a.capacity;
        this->numbers = new int[this->capacity];
        for (int i = 0; i < size; i++) {
            this->numbers[i] = a.numbers[i];
        }
    }

public:
    Array(char *description = "some numbers", int capacity = 10) {
        this->description = new char[strlen(description) + 1];
        strcpy(this->description, description);
        this->size = 0;
        this->capacity = capacity;
        this->numbers = new int[this->capacity];
    }

    Array(const Array &a) {
        copy(a);
    }

    Array &operator=(const Array &other) {
        if (this == &other) {
            return *this;
        }

        delete[] description;
        delete[] numbers;
        copy(other);
        return *this;

    }

    ~Array() {
        delete[] description;
        delete[] numbers;
    }

    Array &operator+=(int element) {
        if (size == capacity) {
            capacity *= 2;
            int *tmp = new int[capacity];
            for (int i = 0; i < size; i++) {
                tmp[i] = numbers[i];
            }
            delete[] this->numbers;
            this->numbers = tmp;
        }

        numbers[size] = element;
        size++;


        return *this;
    }

    friend ostream &operator<<(ostream &out, const Array &a) {
        out << a.description << " -> Size: " << a.size << "( out of " << a.capacity << ")" << endl;
        for (int i = 0; i < a.size; i++) {
            out << a.numbers[i] << " ";
        }
        return out;
    }
};

int main() {
    Array a("test", 12);
    cout << a << endl;
    for (int i = 0; i < 30; i++) {
        a += i * 5;
        cout << a << endl;
    }
    return 0;
}
