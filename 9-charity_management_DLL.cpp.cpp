 //charity management system
#include <iostream>
#include <string>
using namespace std;

// Structure to store donor data
struct Donor {
    int id;
    string name;
    double amount;
    Donor* next;
};

// Charity Management System
class CharitySystem {
private:
    Donor* head;

public:
    CharitySystem() : head(nullptr) {}

    // Add a new donation
    void addDonation(int donorID, const string& donorName, double donationAmount) {
        Donor* newDonor = new Donor{donorID, donorName, donationAmount, nullptr};
        
        // Add to the end of the list
        if (!head) {
            head = newDonor;
        } else {
            Donor* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newDonor;
        }
        cout << "Donation added: " << donorName << " donated Rs." << donationAmount << "\n";
    }

    // Remove a donation by donor ID
    void removeDonation(int donorID) {
        if (!head) {
            cout << "No donations recorded.\n";
            return;
        }
        
        // Remove head donor if ID matches
        if (head->id == donorID) {
            Donor* temp = head;
            head = head->next;
            delete temp;
            cout << "Donation removed.\n";
            return;
        }

        // Search for donor in the list
        Donor* current = head;
        Donor* previous = nullptr;
        while (current && current->id != donorID) {
            previous = current;
            current = current->next;
        }

        // Delete donor if found
        if (current) {
            previous->next = current->next;
            delete current;
            cout << "Donation removed.\n";
        } else {
            cout << "Donor ID " << donorID << " not found.\n";
        }
    }

    // Display all donations
    void showDonations() {
        if (!head) {
            cout << "No donations to display.\n";
            return;
        }
        
        Donor* temp = head;
        cout << "\nAll Donations:\n";
        while (temp) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Amount: $" << temp->amount << "\n";
            temp = temp->next;
        }
    }

    // Search for a donation by donor ID
    void findDonation(int donorID) {
        Donor* temp = head;
        while (temp) {
            if (temp->id == donorID) {
                cout << "Donation found: " << temp->name << " donated $" << temp->amount << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Donor ID " << donorID << " not found.\n";
    }

    // Destructor to clear all donations
    ~CharitySystem() {
        while (head) {
            Donor* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    CharitySystem charity;
    int choice, donorID;
    string donorName;
    double donationAmount;

    do {
        cout << "\n------ Charity Management System ------\n";
        cout << "1. Add Donation\n2. Remove Donation\n3. Show Donations\n4. Find Donation\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Donor ID: ";
                cin >> donorID;
                cin.ignore(); // Ignore newline character
                cout << "Enter Donor Name: ";
                getline(cin, donorName);
                cout << "Enter Donation Amount: ";
                cin >> donationAmount;
                charity.addDonation(donorID, donorName, donationAmount);
                break;

            case 2:
                cout << "Enter Donor ID to remove: ";
                cin >> donorID;
                charity.removeDonation(donorID);
                break;

            case 3:
                charity.showDonations();
                break;

            case 4:
                cout << "Enter Donor ID to search: ";
                cin >> donorID;
                charity.findDonation(donorID);
                break;

            case 5:
                cout << "Exiting Charity Management System. Thank you!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
  
