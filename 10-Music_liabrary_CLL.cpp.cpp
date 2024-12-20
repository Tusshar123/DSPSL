//music library using circular linked list
#include <iostream>
#include <string>
using namespace std;

// Define the Track struct to store music track details
struct Track {
    string title;
    string artist;
    string album;
    string genre;
    int duration; // in seconds
    int releaseYear;
    Track *next; // pointer to the next track (circular list)
};

// Initialize pointers for the circular linked list
Track *head = nullptr;
Track *tail = nullptr;

class MusicLibrary {
public:
    // Function to add a new track to the music library
    void addTrack(string title, string artist, string album, string genre, int duration, int releaseYear) {
        Track *newTrack = new Track();
        newTrack->title = title;
        newTrack->artist = artist;
        newTrack->album = album;
        newTrack->genre = genre;
        newTrack->duration = duration;
        newTrack->releaseYear = releaseYear;

        if (head == nullptr) { // If list is empty, initialize it
            head = tail = newTrack;
            newTrack->next = head; // Points to itself, making it circular
        } else {
            tail->next = newTrack;
            newTrack->next = head; // Connect the last track to the first
            tail = newTrack;
        }
    }

    // Function to display all tracks in the music library
    void displayTracks() {
        if (head == nullptr) {
            cout << "No tracks in the music library.\n";
            return;
        }

        Track *temp = head;
        do {
            cout << "Title: " << temp->title << ", Artist: " << temp->artist 
                 << ", Album: " << temp->album << ", Genre: " << temp->genre 
                 << ", Duration: " << temp->duration << "s, Release Year: " 
                 << temp->releaseYear << endl;
            temp = temp->next;
        } while (temp != head);
    }

    // Function to search for a specific track by title
    void searchTrack(string title) {
        if (head == nullptr) {
            cout << "No tracks in the music library.\n";
            return;
        }

        Track *temp = head;
        do {
            if (temp->title == title) {
                cout << "Track found: " << temp->title << " by " << temp->artist << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Track with title " << title << " not found.\n";
    }

    // Function to remove a track by title
    void removeTrack(string title) {
        if (head == nullptr) {
            cout << "No tracks in the music library.\n";
            return;
        }

        Track *temp = head;
        Track *prev = nullptr;

        // Search for the track to remove
        do {
            if (temp->title == title) {
                if (temp == head && temp == tail) { // Single track case
                    delete temp;
                    head = tail = nullptr;
                } else if (temp == head) { // Removing the head
                    tail->next = head->next;
                    head = head->next;
                    delete temp;
                } else if (temp == tail) { // Removing the tail
                    prev->next = head;
                    tail = prev;
                    delete temp;
                } else { // Removing in between
                    prev->next = temp->next;
                    delete temp;
                }
                cout << "Track with title " << title << " removed.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Track with title " << title << " not found.\n";
    }

    // Function to update track information
    void updateTrack(string title, string newArtist, string newAlbum, string newGenre, int newDuration, int newReleaseYear) {
        if (head == nullptr) {
            cout << "No tracks in the music library.\n";
            return;
        }

        Track *temp = head;
        do {
            if (temp->title == title) {
                temp->artist = newArtist;
                temp->album = newAlbum;
                temp->genre = newGenre;
                temp->duration = newDuration;
                temp->releaseYear = newReleaseYear;
                cout << "Track with title " << title << " updated.\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Track with title " << title << " not found.\n";
    }
};

int main() {
    MusicLibrary ml;
    int choice;
    string title, artist, album, genre;
    int duration, releaseYear;

    do {
        cout << "\nMusic Library Menu:\n"
             << "1. Add Track\n"
             << "2. Display All Tracks\n"
             << "3. Search Track\n"
             << "4. Remove Track\n"
             << "5. Update Track\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter track title: ";
                cin >> title;
                cout << "Enter artist: ";
                cin >> artist;
                cout << "Enter album: ";
                cin >> album;
                cout << "Enter genre: ";
                cin >> genre;
                cout << "Enter duration (in seconds): ";
                cin >> duration;
                cout << "Enter release year: ";
                cin >> releaseYear;
                ml.addTrack(title, artist, album, genre, duration, releaseYear);
                break;

            case 2:
                ml.displayTracks();
                break;

            case 3:
                cout << "Enter track title to search: ";
                cin >> title;
                ml.searchTrack(title);
                break;

            case 4:
                cout << "Enter track title to remove: ";
                cin >> title;
                ml.removeTrack(title);
                break;

            case 5:
                cout << "Enter track title to update: ";
                cin >> title;
                cout << "Enter new artist: ";
                cin >> artist;
                cout << "Enter new album: ";
                cin >> album;
                cout << "Enter new genre: ";
                cin >> genre;
                cout << "Enter new duration (in seconds): ";
                cin >> duration;
                cout << "Enter new release year: ";
                cin >> releaseYear;
                ml.updateTrack(title, artist, album, genre, duration, releaseYear);
                break;
        }
    } while (choice != 6);

    return 0;
}
