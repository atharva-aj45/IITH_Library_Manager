#include "Library.h"
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    Library lib;
    string filename = "books_inventory.csv";
    lib.loadFromCSV(filename);

    int choice;
    do {
        cout << "\n1. Display All Books\n"
             << "2. Add Book\n"
             << "3. Borrow Book\n"
             << "4. Return Book\n"
             << "5. Remove Book\n"
             << "6. Display Books by Branch\n"
             << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string title, author, branch;
        int price, copies;

        switch (choice) {
        case 1:
            lib.displayAllBooks();
            break;
        case 2:
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter branch: ";
            getline(cin, branch);
            cout << "Enter price: ";
            cin >> price;
            if (price < 0) { cout << "Price cannot be negative.\n"; break; }
            cout << "Enter copies: ";
            cin >> copies;
            if (copies < 0) { cout << "Copies cannot be negative.\n"; break; }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            lib.addBook(Book(title, author, branch, price, copies));
            break;
        case 3:
            cout << "Enter title to borrow: ";
            getline(cin, title);
            lib.borrowBook(title);
            break;
        case 4:
            cout << "Enter title to return: ";
            getline(cin, title);
            lib.returnBook(title);
            break;
        case 5:
            cout << "Enter title to remove: ";
            getline(cin, title);
            lib.removeBook(title);
            break;
        case 6:
            cout << "Enter branch: ";
            getline(cin, branch);
            lib.displayBooksByBranch(branch);
            break;
        case 0:
            lib.saveToCSV(filename);
            cout << "Data saved. Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}