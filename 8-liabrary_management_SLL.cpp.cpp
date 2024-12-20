#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;
    Book* next;
};

Book* head = nullptr;  // Global head for the linked list

// Function to create a new book node
Book* createBookNode() {
    Book* newBook = new Book;
    if (newBook == nullptr) {
        cout << "Memory allocation failed.\n";
        return nullptr;
    }
    cout << "Enter book title: ";
    getline(cin, newBook->title);
    cout << "Enter author name: ";
    getline(cin, newBook->author);
    cout << "Enter ISBN: ";
    getline(cin, newBook->ISBN);
    newBook->isAvailable = true;  
    newBook->next = nullptr;
    return newBook;
}

// Function to add a new book to the library
void addBook() {
    Book* newBook = createBookNode();
    if (newBook == nullptr) 
    cout<<"Memoert not allocated\n";
    return;

    if (head == nullptr) {
        head = newBook;
    } else {
        // Insert at the end of the linked list
        Book* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
    cout << "Book added successfully.\n";
}

// Function to display all books in the library
void displayBooks() {
    if (head == nullptr) {
        cout << "No books in the library.\n";
        return;
    }

    Book* temp = head;
    cout << "\nLibrary Collection:\n";
    while (temp != nullptr) {
        cout << "Title: " << temp->title << "\n"
             << "Author: " << temp->author << "\n"
             << "ISBN: " << temp->ISBN << "\n"
             << "Availability: " << (temp->isAvailable ? "Available" : "Checked Out") << "\n\n";
        temp = temp->next;
    }
}

// Function to search for a book by ISBN
void searchBook() {
    if (head == nullptr) {
        cout << "No books in the library.\n";
        return;
    }

    string searchISBN;
    cout << "Enter ISBN of the book to search: ";
    cin >> searchISBN;

    Book* temp = head;
    while (temp != nullptr) {
        if (temp->ISBN == searchISBN) {
            cout << "Book Found:\n";
            cout << "Title: " << temp->title << "\n"
                 << "Author: " << temp->author << "\n"
                 << "Availability: " << (temp->isAvailable ? "Available" : "Checked Out") << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Book with ISBN " << searchISBN << " not found.\n";
}

// Function to remove a book by ISBN
void removeBook() {
    if (head == nullptr) {
        cout << "No books in the library.\n";
        return;
    }

    string removeISBN;
    cout << "Enter ISBN of the book to remove: ";
    cin >> removeISBN;

    // If the book to be removed is the head node
    if (head->ISBN == removeISBN) {
        Book* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "Book removed successfully.\n";
        return;
    }

    // Traverse to find the book
    Book* temp = head;
    while (temp->next != nullptr && temp->next->ISBN != removeISBN) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Book with ISBN " << removeISBN << " not found.\n";
    } else {
        Book* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Book removed successfully.\n";
    }
}

// Function to mark a book as checked out or returned
void Returnbook() {
    if (head == nullptr) {
        cout << "No books in the library.\n";
        return;
    }

    string updateISBN;
    cout << "Enter ISBN of the book to return: ";
    cin >> updateISBN;

    Book* temp = head;
    while (temp != nullptr) {
        if (temp->ISBN == updateISBN) {
            temp->isAvailable = true;
            cout << "Book Returned" << "\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Book with ISBN " << updateISBN << " not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\nLibrary Management System Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book by ISBN\n";
        cout << "4. Remove Book by ISBN\n";
        cout << "5.Return Book\n";
        cout << "6. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                removeBook();
                break;
            case 5:
                Returnbook();
                break;
            case 6:
                cout << "Exiting Library Management System.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
  
