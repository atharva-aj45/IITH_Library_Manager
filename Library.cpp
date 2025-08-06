// Library.cpp
#include "Library.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>
using namespace std;
void Library::loadFromCSV(const string& filename) {
    ifstream file("books_inventory.csv");
    if (!file) {
        cerr << "Error: Cannot open file." << endl;
        return;
    }
    string line, title, author, branch, priceStr, copiesStr;
    getline(file, line); // Skip header
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, branch, ',');
        getline(ss, priceStr, ',');
        getline(ss, copiesStr, ',');
        int price = stoi(priceStr);
        int copies = stoi(copiesStr);
        books[title] = Book(title, author, branch, price, copies);
    }
    file.close();
}

void Library::saveToCSV(const string& filename) {
    ofstream file(filename);
    file << "Title,Author,Branch,Price (\u20b9),Copies\n";
    for (const auto& pair : books) {
        const Book& b = pair.second;
        file << b.title << "," << b.author << "," << b.branch << "," << b.price << "," << b.copies << "\n";
    }
    file.close();
}

void Library::displayAllBooks() const {
    for (const auto& pair : books) {
        pair.second.display();
        cout << "-----------------------\n";
    }
}

void Library::addBook(const Book& book) {
    books[book.title] = book;
    cout << "Book added/updated successfully.\n";
}

void Library::borrowBook(const string& title) {
    if (books.count(title) && books[title].copies > 0) {
        books[title].copies--;
        borrowDates[title] = chrono::system_clock::now();
        cout << "Borrowed successfully. Due in 90 days.\n";
    } else {
        cout << "Book unavailable.\n";
    }
}

void Library::returnBook(const string& title) {
    if (books.count(title)) {
        books[title].copies++;

        if (borrowDates.count(title)) {
            cout << "Enter return date (YYYY MM DD): ";
            int y, m, d;
            cin >> y >> m >> d;
            cin.ignore();

            chrono::system_clock::time_point borrowedOn = borrowDates[title];
            tm returnTm = {};
            returnTm.tm_year = y - 1900;
            returnTm.tm_mon = m - 1;
            returnTm.tm_mday = d;

            time_t returnTime = mktime(&returnTm);
            chrono::system_clock::time_point returnedOn = chrono::system_clock::from_time_t(returnTime);

            auto duration = chrono::duration_cast<chrono::hours>(returnedOn - borrowedOn).count() / 24;
            int overdueDays = duration - 90;

            if (overdueDays <= 0) {
                cout << "Returned successfully. No penalty.\n";
            } else if (overdueDays <= 7) {
                cout << "Returned with ₹" << overdueDays << " penalty (\u20b91/day).\n";
            } else {
                int fine = 7 + (overdueDays - 7) * 10;
                cout << "Returned with ₹" << fine << " penalty (\u20b91/day for first 7 days, \u20b910/day after).\n";
            }

            borrowDates.erase(title);
        } else {
            cout << "Returned. But no borrow date recorded.\n";
        }
    } else {
        cout << "Invalid book title.\n";
    }
}

void Library::removeBook(const string& title) {
    if (books.erase(title)) {
        borrowDates.erase(title);
        cout << "Book removed successfully.\n";
    } else {
        cout << "Book not found.\n";
    }
}

void Library::displayBooksByBranch(const string& branch) const {
    bool found = false;
    for (const auto& pair : books) {
        if (pair.second.branch == branch) {
            pair.second.display();
            cout << "-----------------------\n";
            found = true;
        }
    }
    if (!found) cout << "No books found for branch: " << branch << "\n";
}