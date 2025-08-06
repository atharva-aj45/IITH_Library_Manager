// Library.h
#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <map>
#include <string>
#include <chrono>
using namespace std;

class Library {
private:
    map<string, Book> books;
    map<string, chrono::system_clock::time_point> borrowDates;

public:
    void loadFromCSV(const string& filename);
    void saveToCSV(const string& filename);
    void displayAllBooks() const;
    void addBook(const Book& book);
    void borrowBook(const string& title);
    void returnBook(const string& title);
    void removeBook(const string& title);
    void displayBooksByBranch(const string& branch) const;
};

#endif
