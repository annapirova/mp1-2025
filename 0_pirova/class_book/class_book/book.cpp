#include "book.h"

// конструктор инициализации
Book::Book(string s1, string s2, int y) : name(s1), author(s2), year(y) {
    cout << "construstor for " << s1 << "\n";
}

// деструктор
Book::~Book() {
    cout << "I am destructor\n";
}

void Book::Print() {
    cout << name << " " << author << " " << year << std::endl;
}

bool Book::Compare(const Book& b2) {
    if (year < b2.year)
        return true;
    else return false;
}
