#include <iostream>
#include <cstring>
using namespace std;

//YOUR CODE HERE:

enum BOOK_TYPE {
    ACADEMIC,
    NOVEL
};

class Book {
private:
    char title [31];
    int id;
    BOOK_TYPE type;
    double price;
    static int OBJECTS_CREATED;
public:

    Book (){
        strcpy(this->title, "");
        type = ACADEMIC;
        this->id = 0;
        this->price = 100;
    }
    Book (char title[31], int type, double price){
        strcpy(this->title, title);
        this->type = (BOOK_TYPE) type;
        this->price = price;
        this->id = 777551 + OBJECTS_CREATED;
        OBJECTS_CREATED++;
    }

    void print () {
        // academic 2300
        cout << this->id << " - " << this->title << " ";
        if (this->type==ACADEMIC){
            cout << "academic ";
        } else {
            cout << "roman ";
        }
        cout << this->price << endl;
    }

    void increasePrice(float amount){
        this->price+=amount;
    }

    friend class BookStore;


};


class BookStore {
private:
    char name [21];
    Book books[100];
    int n;
public:
    BookStore(char name[21] = ""){
        strcpy(this->name, name);
        n = 0;
    }

    void addBook (const Book & b){
        for (int i=0;i<n;i++){
            if (strcmp(books[i].title,b.title)==0){
                return ;
            }
        }

        books[n]=b;
        n++;
    }

    void print (){
        cout << name << endl;
        for (int i=0;i<n;i++){
            books[i].print();
        }
    }

    bool greaterThan (const BookStore & other){
        return this->n > other.n;
    }

    void createMarketPrice() {
        for (int i=0;i<n;i++){
            if (books[i].type==ACADEMIC){
                books[i].increasePrice(books[i].price*0.05);
            } else {
                books[i].increasePrice(books[i].price*0.03);
            }
        }
    }
};

int Book::OBJECTS_CREATED = 0;

int main() {
    int testCase;
    cin>>testCase;
    if(testCase==0)
    {
        cout<<"TESTING BOOK CONSTRUCTOR"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==1)
    {
        cout<<"TESTING BOOK print()"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        book1.print();
        book2.print();
        book3.print();
        cout<<"TEST PASSED"<<endl;
    } else if(testCase==2)
    {
        cout<<"TESTING BOOK increasePrice"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        book1.print();
        book2.print();
        book3.print();
        book1.increasePrice(200);
        book2.increasePrice(300);
        book3.increasePrice(150);
        cout<<"===== INCREASE ====="<<endl;
        book1.print();
        book2.print();
        book3.print();
        cout<<"TEST PASSED"<<endl;
    }
    else if(testCase==3)
    {
        cout<<"TESTING BOOKSTORE CONSTRUCTOR"<<endl;
        BookStore bookStore1("The Book Cellar");
        bookStore1.print();
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==4)
    {
        cout<<"TESTING BOOKSTORE addBook() and print()"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        BookStore bookStore1("The Book Cellar");
        bookStore1.addBook(book1);
        bookStore1.addBook(book2);
        bookStore1.addBook(book3);
        bookStore1.print();
        cout<<"TEST PASSED"<<endl;
    }
    else if(testCase==5)
    {
        cout<<"TESTING BOOKSTORE OPERATOR addBook() and print()"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        Book book4("Object-oriented programming",0,2300);
        BookStore bookStore1("The Book Cellar");
        bookStore1.addBook(book1);
        bookStore1.addBook(book2);
        bookStore1.addBook(book3);
        bookStore1.addBook(book4);
        bookStore1.print();
        cout<<"TEST PASSED"<<endl;
    }
    else if(testCase==6)
    {
        cout<<"TESTING BOOKSTORE COPY-CONSTRUCTOR"<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        Book book4("Anna Karenina",1,1200);
        Book book5("Calculus 1",0,1320);
        BookStore bookStore1("The Book Cellar");
        bookStore1.addBook(book1);
        bookStore1.addBook(book2);
        bookStore1.addBook(book3);
        BookStore bookStore2(bookStore1);

        bookStore1.print();
        bookStore2.print();
        cout<<"TEST PASSED"<<endl;

    }
    else if(testCase==7)
    {
        cout<<"TESTING BOOKSTORE greaterThan "<<endl;
        Book book1("Object-oriented programming",0,2300);
        Book book2("Discrete Mathematics",0,1800);
        Book book3("Crime and punishment",1,950);
        Book book4("Anna Karenina",1,1200);
        Book book5("Calculus 1",0,1320);
        BookStore bookStore1("The Book Cellar");
        bookStore1.addBook(book1);
        bookStore1.addBook(book2);
        bookStore1.addBook(book3);
        BookStore bookStore3("Word Wizardry Books");
        bookStore3.addBook(book4);
        bookStore3.addBook(book5);
        if(bookStore1.greaterThan(bookStore3))
        {
            cout<<"TEST PASSED"<<endl;
        }
        else
        {
            cout<<"TEST FAILED"<<endl;
        }
    }else if(testCase==8)
    {
        cout<<"TESTING METHOD createMarketPrice()"<<endl;
        char name[30],name1[30];
        int type, numofBookStores, numberOfBooks;
        float price;
        cin>>numofBookStores;
        cin.ignore();
        BookStore bookStores[10];
        for(int i=0;i<numofBookStores;i++)
        {
            cin.getline(name,20);
            bookStores[i]=BookStore(name);
            cin>>numberOfBooks;
            cin.ignore();
            Book books[10]; //777561
            for(int j=0;j<numberOfBooks;j++)
            {
                cin >> name1 >> type >> price;
                cin.ignore();
                books[j]=Book(name1,type,price);
                bookStores[i].addBook(books[j]);
            }
        }
        for(int i=0;i<numofBookStores;i++)
        {
            bookStores[i].print();
            cout<<"CREATED MARKET PRICES"<<endl;
            bookStores[i].createMarketPrice();
            bookStores[i].print();
        }

    }else if(testCase==9)
    {
        cout<<"TESTING METHOD best()"<<endl;
        char name[30],name1[30];
        int type, numofBookStores, numberOfBooks;
        float price;
        cin>>numofBookStores;
        cin.ignore();
        BookStore bookStores[10];
        for(int i=0;i<numofBookStores;i++)
        {
            cin.getline(name,20);
            bookStores[i]=BookStore(name);
            cin>>numberOfBooks;
            cin.ignore();
            Book books[10];
            for(int j=0;j<numberOfBooks;j++)
            {
                cin >> name1 >> type >> price;
                cin.ignore();
                books[j]=Book(name1,type,price);
                bookStores[i].addBook(books[j]);
            }
        }
//        best(bookStores,numofBookStores).print();
    }
    return 0;
}