## Прва задача - Колоквиум 2024

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

