 #include <iostream>
#include <string>
using namespace std;

// structure of the Music Track node
struct Track {
    string title, artist, album, genre;
    int duration;  // in seconds
    int releaseYear;
    Track* next;
};

// Global variables
Track* head = nullptr;

// Function to create a new track node
Track* createTrack() {
    Track* newTrack = new Track();
    cout << "Enter Track Title: ";
    getline(cin, newTrack->title);
    cout << "Enter Artist Name: ";
    getline(cin, newTrack->artist);
    cout << "Enter Album Name: ";
    getline(cin, newTrack->album);
    cout << "Enter Genre: ";
    getline(cin, newTrack->genre);
    cout << "Enter Duration (in seconds): ";
    cin >> newTrack->duration;
    cout << "Enter Release Year: ";
    cin >> newTrack->releaseYear;
    newTrack->next = nullptr;
    return newTrack;
}

// Function to add a new music track
void addTrack() {
    Track* newTrack = createTrack();
    if (!head) {
        head = newTrack;
        head->next = head;
    } else {
        Track* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newTrack;
        newTrack->next = head;
    }
    cout << "Track added successfully!\n";
}

// Function to remove a music track by title
void removeTrack() {
    if (!head) {
        cout << "Music library is empty!\n";
        return;
    }
    string title;
    cout << "Enter the title of the track to remove: ";
    getline(cin, title);

    Track* current = head;
    Track* prev = nullptr;

    do {
        if (current->title == title) {
            if (current == head && current->next == head) {
                head = nullptr;  // Only one track
            } else if (current == head) {
                Track* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                head = head->next;
                temp->next = head;
            } else {
                prev->next = current->next;
            }
            delete current;
            cout << "Track removed successfully!\n";
            return;
        }
        prev = current;
        current = current->next;
    } while (current != head);

    cout << "Track not found!\n";
}

// Function to update a music track's information
void updateTrack() {
    if (!head) {
        cout << "Music library is empty!\n";
        return;
    }
    string title;
    cout << "Enter the title of the track to update: ";
    getline(cin, title);

    Track* current = head;

    do {
        if (current->title == title) {
            cout << "Enter new details for the track:\n";
            cout << "Enter Artist Name: ";
            getline(cin, current->artist);
            cout << "Enter Album Name: ";
            getline(cin, current->album);
            cout << "Enter Genre: ";
            getline(cin, current->genre);
            cout << "Enter Duration (in seconds): ";
            cin >> current->duration;
            cout << "Enter Release Year: ";
            cin >> current->releaseYear;
            cout << "Track updated successfully!\n";
            return;
        }
        current = current->next;
    } while (current != head);

    cout << "Track not found!\n";
}

// Function to search for a specific music track
void searchTrack() {
    if (!head) {
        cout << "Music library is empty!\n";
        return;
    }
    string title;
    cout << "Enter the title of the track to search: ";
    cin.ignore();
    getline(cin, title);

    Track* current = head;

    do {
        if (current->title == title) {
            cout << "\nTrack Found:\n";
            cout << "Title: " << current->title << "\n";
            cout << "Artist: " << current->artist << "\n";
            cout << "Album: " << current->album << "\n";
            cout << "Genre: " << current->genre << "\n";
            cout << "Duration: " << current->duration << " seconds\n";
            cout << "Release Year: " << current->releaseYear << "\n";
            return;
        }
        current = current->next;
    } while (current != head);

    cout << "Track not found!\n";
}

// Function to display all music tracks
void displayTracks() {
    if (!head) {
        cout << "Music library is empty!\n";
        return;
    }
    Track* current = head;

    cout << "\nMusic Library:\n";
    do {
        cout << "--------------------------------\n";
        cout << "Title: " << current->title << "\n";
        cout << "Artist: " << current->artist << "\n";
        cout << "Album: " << current->album << "\n";
        cout << "Genre: " << current->genre << "\n";
        cout << "Duration: " << current->duration << " seconds\n";
        cout << "Release Year: " << current->releaseYear << "\n";
        current = current->next;
    } while (current != head);
    cout << "--------------------------------\n";
}

// Main function
int main() {
    int choice;

    do {
        cout << "\nMusic Library System\n";
        cout << "1. Add New Music Track\n";
        cout << "2. Remove Music Track\n";
        cout << "3. Update Music Track\n";
        cout << "4. Search Music Track\n";
        cout << "5. Display All Tracks\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTrack();
                break;
            case 2:
                removeTrack();
                break;
            case 3:
                updateTrack();
                break;
            case 4:
                searchTrack();
                break;
            case 5:
                displayTracks();
                break;
            case 6:
                cout << "Exiting Music Library System...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
 /*
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    double donationAmount;
    Node* next;
    Node* prev;
};

class DonorList {
private:
    Node* head = NULL;

public:
    void insert() {
        Node* newNode = new Node();
        if (newNode == NULL) {
            cout << "Memory allocation failed" << endl;
            return;
        }

        cout << "Enter the name of the donor: ";
        cin >> newNode->name;

        cout << "Enter the donation amount: ";
        cin >> newNode->donationAmount;

        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Donor added successfully!" << endl;
    }

    void deleteDonor() {
        if (head == NULL) {
            cout << "No donors available to delete." << endl;
            return;
        }

        cout << "Enter the name of the donor to delete: ";
        string nameToDelete;
        cin >> nameToDelete;

        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == nameToDelete) {
                if (temp->prev != NULL) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }

                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }

                delete temp;
                cout << "Donor deleted successfully!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Donor not found!" << endl;
    }

    void update() {
        if (head == NULL) {
            cout << "No donors available to update." << endl;
            return;
        }

        cout << "Enter the name of the donor to update: ";
        string nameToUpdate;
        cin >> nameToUpdate;

        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == nameToUpdate) {
                cout << "Enter the new name of the donor: ";
                cin >> temp->name;

                cout << "Enter the new donation amount: ";
                cin >> temp->donationAmount;

                cout << "Donor details updated successfully!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Donor not found!" << endl;
    }

    void search() {
        if (head == NULL) {
            cout << "No donors available." << endl;
            return;
        }

        cout << "Enter the name of the donor to search: ";
        string nameToSearch;
        cin >> nameToSearch;

        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == nameToSearch) {
                cout << "Donor found!" << endl;
                cout << "Name: " << temp->name << ", Donation Amount: " << temp->donationAmount << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Donor not found!" << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "No donors available." << endl;
            return;
        }

        cout << "List of donors:" << endl;
        Node* temp = head;
        while (temp != NULL) {
            cout << "Name: " << temp->name << "\n Donation Amount: " << temp->donationAmount << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DonorList l;
    int choice, ch;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert donor details\n";
        cout << "2. Delete donor details\n";
        cout << "3. Update donor details\n";
        cout << "4. Search for a donor\n";
        cout << "5. Display all donors\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            l.insert();
            break;
        case 2:
            l.deleteDonor();
            break;
        case 3:
            l.update();
            break;
        case 4:
            l.search();
            break;
        case 5:
            l.display();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }

        cout << "Press 1 to continue: ";
        cin >> choice;
    } while (choice == 1);

    return 0;
}
*/
