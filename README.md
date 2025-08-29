# IITH_Library_Manager

## Project Overview
This project is a **Library Management System** implemented in C++.  
It allows users to manage books by adding, borrowing, returning, removing, and displaying books.  
Data persistence is handled via a CSV file (`books_inventory.csv`), ensuring that all changes are saved between sessions.

## Features
- Load and save book inventory from/to CSV file
- Add new books with validation (no negative price or copies)
- Borrow and return books with penalty calculation for overdue returns
- Remove books from inventory
- Display all books or filter by branch/department
- Persistent storage to maintain records

## Tech Stack
- **Language:** C++17  
- **Data Storage:** CSV file (`books_inventory.csv`)  
- **Libraries Used:** `<iostream>`, `<fstream>`, `<sstream>`, `<chrono>`, `<map>`

##  Project Structure
├── Book.h <br>
├── Book.cpp <br>
├── Library.h  <br>
├── Library.cpp  <br>
├── main.cpp  <br>
└── books_inventory.csv  <br>


## Future Enhancements
- User login system (students, admin)
- Search functionality (by author/title)
- GUI-based interface
- Fine payment system integration

## Author
 **Atharva Joshi** <br>
IIT Hyderabad
