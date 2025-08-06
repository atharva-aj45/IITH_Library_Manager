// Book.cpp
#include "Book.h"
#include <iostream>

Book::Book(string t, string a, string b, int p, int c)
    : title(t), author(a), branch(b), price(p), copies(c) {}

void Book::display() const {
    cout << "Title: " << title << "\n"
         << "Author: " << author << "\n"
         << "Branch: " << branch << "\n"
         << "Price: ₹" << price << "\n"
         << "Copies: " << copies << "\n";
}