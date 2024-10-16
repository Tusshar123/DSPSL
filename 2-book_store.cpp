#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
public:
    string name;
    float price;

    Book(string n, float p) : name(n), price(p) {}
};

void addBook(vector<Book>& library) {
    string name;
    float price;
    cout << "  • Book Name: ";
    cin >> name;
    cout << "  • Book Price: ";
    cin >> price;
    library.emplace_back(name, price);
}

void displayBooks(const vector<Book>& library) {
    cout << "----------------------------------------------------------" << endl;
    cout << "|         Book Name          |         Price            |" << endl;
    cout << "----------------------------------------------------------" << endl;
    for (const auto& book : library) {
        cout << "|          " << book.name << "           |         " << book.price << "        |" << endl;
    }
    cout << "----------------------------------------------------------" << endl;
}

void removeDuplicates(vector<Book>& library) {
    sort(library.begin(), library.end(), [](const Book& a, const Book& b) {
        return a.name < b.name;
    });
    library.erase(unique(library.begin(), library.end(), [](const Book& a, const Book& b) {
        return a.name == b.name;
    }), library.end());
    cout << "Duplicates removed." << endl;
}

void sortBooksByPrice(vector<Book>& library) {
    sort(library.begin(), library.end(), [](const Book& a, const Book& b) {
        return a.price > b.price;
    });
    cout << "Books sorted by price in descending order." << endl;
}

void displayBooksInRange(const vector<Book>& library, float target) {
    cout << "\nBooks Under " << target << ":\n";
    for (const auto& book : library) {
        if (book.price < target) {
            cout << book.name << " - " << book.price << endl;
        }
    }

    cout << "\nBooks Above or Equal to " << target << ":\n";
    for (const auto& book : library) {
        if (book.price >= target) {
            cout << book.name << " - " << book.price << endl;
        }
    }
}

int main() {
    vector<Book> library;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Remove Duplicates\n";
        cout << "4. Sort Books by Price (Descending)\n";
        cout << "5. Display Books by Price Range\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(library); break;
            case 2: displayBooks(library); break;
            case 3: removeDuplicates(library); break;
            case 4: sortBooksByPrice(library); break;
            case 5: {
                float target;
                cout << "Enter the price: ";
                cin >> target;
                displayBooksInRange(library, target);
                break;
            }
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
