#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::string;


class Book {

    string name;
    string author;
    int year;


    void Set(string s1, string s2, int y) {
        name = s1; author = s2;
        year = y;
    }
public:
    // конструктор инициализации
    Book(string s1 = "", string s2 = "", int y = 2000);
    // деструктор

    // конструктор копирования - не обязательно, 
    //                если нет полей-указателей
    Book(const Book& b) {
        name = b.name;
        year = b.year;
        author = b.author;
    }

    ~Book();
    void Print();
    bool Compare(const Book& b2);
};
