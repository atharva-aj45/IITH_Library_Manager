// Book.h
#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
public:
    string title, author, branch;
    int price, copies;

    Book() = default;
    Book(string t, string a, string b, int p, int c);

    void display() const;
};

#endif
