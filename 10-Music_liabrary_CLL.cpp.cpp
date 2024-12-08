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

struct Music {
    string name;
    string alb_name;
    int year;
    Music *next;
};

Music *start = NULL;

void accept() {
    Music *newNode = new Music;
    cout << "\nEnter music details:";
    cout << "\nEnter name, album name, released year: ";
    cin >> newNode->name >> newNode->alb_name >> newNode->year;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
        newNode->next = start;
    } else {
        Music *temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = start;
    }
}

void display() {
    if (start == NULL) {
        cout << "\nNo music details to display.\n";
        return;
    }
    Music *temp = start;
    cout << "\nMusic Details:\n";
    do {
        cout << temp->name << "\t" << temp->alb_name << "\t" << temp->year << "\t" <<  "\n";
        temp = temp->next;
    } while (temp != start);
}

void update() {
    if (start == NULL) {
        cout << "\nNo music details to update.\n";
        return;
    }
    string title;
    cout << "\nEnter the name of the music to update: ";
    cin >> title;
    Music *temp = start;
    do {
        if (temp->name == title) {
            cout << "\nEnter new details (name, album name, year, duration): ";
            cin >> temp->name >> temp->alb_name >> temp->year;
            cout << "\nMusic details updated successfully.\n";
            return;
        }
        temp = temp->next;
    } while (temp != start);
    cout << "\nMusic not found.\n";
}

void remove() {
    if (start == NULL) {
        cout << "\nNo music details to remove.\n";
        return;
    }
    string title;
    cout << "\nEnter the name of the music to remove: ";
    cin >> title;

    Music *temp = start, *prev = NULL;

    if (start->name == title) {
        if (start->next == start) {
            delete start;
            start = NULL;
        } else {
            while (temp->next != start) {
                temp = temp->next;
            }
            temp->next = start->next;
            Music *toDelete = start;
            start = start->next;
            delete toDelete;
        }
        cout << "\nMusic removed successfully.\n";
        return;
    }

    prev = start;
    temp = start->next;
    do {
        if (temp->name == title) {
            prev->next = temp->next;
            delete temp;
            cout << "\nMusic removed successfully.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != start);

    cout << "\nMusic not found.\n";
}

void search() {
    if (start == NULL) {
        cout << "\nNo music details to search.\n";
        return;
    }
    string title;
    cout << "\nEnter the name of the music to search: ";
    cin >> title;
    Music *temp = start;
    do {
        if (temp->name == title) {
            cout << "\nMusic found: " << temp->name << "\t" << temp->alb_name << "\t" << temp->year << "\t" << "\n";
            return;
        }
        temp = temp->next;
    } while (temp != start);
    cout << "\nMusic not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Music\n2. Display Music\n3. Update Music\n4. Remove Music\n5. Search Music\n6. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
                accept(); 
                break;
            case 2: 
                display(); 
                break;
            case 3: 
                update(); 
                break;
            case 4: 
                remove(); 
                break;
            case 5: 
                search(); 
                break;
            case 6: 
                cout << "\nExiting...\n"; 
                break;
            default: cout << "\nInvalid choice.\n";
        }
    } while (choice != 6);
    return 0;
}
*/
