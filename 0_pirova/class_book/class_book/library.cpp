#include <iostream>
#include <string>
using namespace std; 


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
    
  /*  Book(const Book& b2) {
        name = b2.name;
        author = b2.author;
        year = b2.year;
    }
    */
    
    // деструктор
    ~Book();
    void Print();
    bool Compare(const Book& b2);
};

// конструктор инициализации
    Book::Book(string s1, string s2 , int y) : name(s1), author(s2), year(y) {
        cout << "constructor for " << s1 << "\n";
    }
    
    // деструктор
    Book::~Book() {
        // cout << "I am destructor\n";
    }

    void Book::Print() {
        cout << name << " " << author << " " << year << endl;
    }
    
    bool Book::Compare(const Book& b2) {
        if (year < b2.year)
        return true;
        else return false;
    }

///////////////////////////

class Library {
  
  public:

  Book *books;
  size_t size;

  Library(int k = 5) : size(k) {
    books = new Book [size];
  }

  Library(const Library& other) {
      size = other.size;
      books = new Book [size];
      for (int i = 0; i < size; i++)
        books[i] = other.books[i];
  }
  
  Library& operator=(const Library& other) {
      if (this == &other) {
          return *this;
      }
      
      if (size != other.size) {
        delete [] books;
        size = other.size;
        books = new Book [size];
      }
      for (int i = 0; i < size; i++)
        books[i] = other.books[i];
      
      return *this;
  }
  
  void Print() {
      cout << "Library start\n";
      for (int i = 0; i < size; i++)
        books[i].Print();
      cout << "Library end" << std::endl;
  }
  
  ~Library() {
      delete [] books;
      cout << "library cleaned\n";
  }
  
};

 
int main() 
{ 
   Book b1 = {"Anna Karenina", "Tolstoy", 1890}, 
   b2("MM", "B", 1930); // конструктор инициализации
   Book b3(b2); // конструктор по умолчанию
   
   //b1.Print();
   //b3.Print();
   
   Library mylib(3);
   mylib.books[0] = b1;
   mylib.books[1] = b2;
   mylib.books[2] = b3;
 
   mylib.Print();
 
   Library unnlib(2);

   unnlib = mylib;
   
   unnlib.Print();

   return 0; 
}