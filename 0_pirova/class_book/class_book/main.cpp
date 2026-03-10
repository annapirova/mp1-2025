#include <iostream>
#include "book.h"

using namespace std;





//void BookToFile(const Book& b) {
//
//}
//
//void ReadFromFile(string fileName, Book& b) {
//
//}


int main()
{
    Book b1 = { "Anna Karenina", "Tolstoy", 1890 }, b2("MM", "B", 1930); // конструктор инициализации
    Book b3; // конструктор по умолчанию

    b1.Print();
    bool a = b1.Compare(b2); // this = &b1
    bool x = b2.Compare(b1); // this = &b2

    cout << a;

    return 0;
}