## Задача 1

Да се дефинира класа SMS, во која ќе се чуваат информации за датумот на пораката (објект од класа Date), содржина на пораката (низа од 150 карактери) и два телефонски броја (текстуални низи од 10 цифри за број кој испраќа и број кој прима). (10 поени)
Класата Date треба да содржи три цели броеви за ден, месец и година. (5 поени)


Да се напише main функција во која се чита цел броj N (max 500), a потоа информации за N пораки. Читањето на една порака е во следниот формат:

dd mm yyyy
број_што_праќа
број_што_прима
содржина. (10 поени)


Потоа, треба да се прочита уште еден датум кој означува почеток на временскиот период од тој датум до денес.

Пример влез:

18 03 2016
070211123
071300400
I'll call you back

.... пораки

18 12 2017
070211123
071300400
hahah

11 11 2015

На екран да се испечатат сите пораки кои се пократки од 70 карактери и се направени после внесен датум (не вклучувајќи ги и пораките направени на самиот тој датум). Да се искористи посебна функција која како аргументи прима: низа од објекти од класата SMS, големина на низата со пораки (цел број) и датум (објект од класата Date) кој означува почеток на временскиот период. Доколку не постојат пораки со бараниот услов, да се испечати соодветна порака (15 поени).

Форматот на печатење да се види од тест примерите.


ПОМОШ: Да се вклучи библиотеката #include<iomanip> за датумите да се испечатат со наредбата
cout << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/" << year
---------------------------------------------------------------------------------------------------------------

Define the class SMS, where information about the message date (an object of the Date class), message content (an array of 150 characters), and two phone numbers (textual arrays of 10 digits for the sender and the receiver) are stored.

The Date class should contain three integers for day, month, and year. (5 points)

Write a main function in which an integer N (max 500) is read, followed by information for N messages. Reading a single message is in the following format:

dd mm yyyy

sender_number

receiver_number

content. (10 points)

Then, another date should be read, indicating the start of the time period from that date until today.

Example input:

18 03 2016

070211123

071300400

I'll call you back

.... messages

18 12 2017

070211123

071300400

hahah

11 11 2015

Print all messages shorter than 70 characters made after the entered date (excluding messages on that exact date). Use a separate function that takes as arguments: an array of objects of the SMS class, the size of the message array (an integer), and a date (an object of the Date class) indicating the start of the time period. If there are no messages meeting the specified conditions, print an appropriate message. (15 points)

The printing format should be seen from the test examples.

HINT: Include the library #include<iomanip> to print dates using the command

cout << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/" << year


## Задача 2 

Да се дефинира класа Book, која репрезентира една книга. За класата Book се чуваат:

Наслов (текстуална низа од 30 знаци)

Сериски број (цел број)

Тип на книга (енумерациски тип, стручна литература или роман)

Цена (децимален број)

Серискиот број е единствен за секоја книга, неговата почетна вредност е 777550. Да се обезбеди секвенцијално генерирање на овој број, така што првата книга ќе има сериски број 777551, втората 777552, третата 777553 итн. (5 поени)

За оваа класа да се обезбедат потребните конструктори и set/get методи. (5 поени)

Да се имплементира метод print() со кој ќе се печатат информациите за секој објект во формат:
[сериски број] - [наслов] [тип] [цена]
(5 поени)

Да се имплементира метод increasePrice(float) кој како аргумент ќе прима реален број, што ќе претставува износ кој се додава на цената на книгата. (5 поени)

Потоа да се дефинира класа BookStore, во која се чуваат информации за:

Име (текстуална низа од 20 знаци)

Листа од книги (обична низа со максимум 100 објекти од класата Book)

Број на книги (број на елементи во низата од книги, иницијално е 0)

За оваа класа да се дефинираат потребните конструктори, деструктор (ако е потребен), set и get методи. (5 поени)

Да се имплементира метод print() во формат:
[име]
и потоа сите книги поединечно (види форматот од методот Book::print). (5 поени)

Да се имплементира метод addBook(const Book&) за додавање нова книга во продавницата.
Книгите се менаџираат според нивниот наслов, односно не смее да се дозволи додавање книга со ист наслов повеќе од еднаш. (10 поени)

Да се дефинира метод greaterThan(const BookStore&) кој ќе споредува дали едната продавница има повеќе книги од другата. (5 поени)

Да се дефинира метод void createMarketPrice() - со кој продавницата генерира продажни цени на сите книги. Продажните цени се пресметуваат во зависност од тоа за каков тип на литература станува збор:

За стручна литература се додава 5% на цената

За романи се додава 3% (10 поени)

Да се дефинира глобална функција best() - која прима низа од објекти од класатa BookStore и бројот на продавници, а ја враќа онаа продавница која има најмногу книги. Доколку повеќе продавници имаат ист број на книги, се враќа првата најдена. (5 поени)

Define the class Book, which represents a single book. The class holds the following attributes:

title – a textual array of up to 30 characters

id – serial number (integer)

type – enumerated type representing the book type: academic or roman

price – decimal number

The serial number is unique for each book. The initial value is 777550. Ensure sequential generation of this number, so that the first book has serial number 777551, the second 777552, the third 777553, etc. (5 points)

Provide the necessary constructors and set/get methods. (5 points)

Implement a method print() which prints the information in the following format:
[serial number] - [title] [type] [price]
(5 points)

Implement a method increasePrice(float) that takes a real number representing the margin, and adds it to the book's price. (5 points)

Then define the class BookStore, which stores information about:

Name (textual array of up to 20 characters)

List of books (regular array of up to 100 Book objects)

Number of books (number of elements in the array, initially 0)

Define the necessary constructors, destructor (if needed), and set/get methods. (5 points)

Implement a method print() in the following format:
[name]
and then all books printed individually (see format from the Book::print method). (5 points)

Implement a method addBook(const Book&) to add a new book to the store.
Books are managed based on their title, and adding a book with an already existing title is not allowed. (10 points)

Define a method greaterThan(const BookStore&) to compare two stores by the number of books. (5 points)

Define a method void createMarketPrice() that generates selling prices for all books in the store. The selling prices depend on the book type:

For academic literature, 5% is added to the price

For romans, 3% is added (10 points)

Define a global function best() that takes an array of BookStore objects and the number of stores, and returns the store with the most books. If multiple stores have the same number of books, the first one is returned. (5 points)