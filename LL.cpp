#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

node *head = nullptr;  // Global variable for the head of the list

// Function to create a circular linked list
void create() {
    node *temp, *New;
    int val;
    char ans = 'y';

    do {
        cout << "Enter the element: ";
        cin >> val;

        // Allocate memory for the new node
        New = new node;
        if (New == nullptr) {
            cout << "Memory is not allocated\n";
            return;
        }
        New->data = val;
        New->next = nullptr;

        if (head == nullptr) {
            // First node creation
            head = New;
            New->next = head;
        } else {
            // Insert at the end of the circular list
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = New;
            New->next = head;
        }

        cout << "Do you want to enter more elements? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    cout << "Circular linked list created\n";
}

// Function to display the circular linked list
void display() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    node *temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)\n";
}

// Function to insert a node at the end of the circular linked list
void insert_last() {
    if (head == nullptr) {
        cout << "List is empty. Use create() to initialize the list.\n";
        return;
    }

    node *New = new node;
    if (New == nullptr) {
        cout << "Memory allocation failed\n";
        return;
    }

    cout << "Enter the element which you want to insert: ";
    cin >> New->data;

    node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = New;
    New->next = head;

    cout << "Node is inserted at the end\n";
}

// Function to insert a node at the beginning of the circular linked list
void insert_head() {
    if (head == nullptr) {
        cout << "List is empty. Use create() to initialize the list.\n";
        return;
    }

    node *New = new node;
    if (New == nullptr) {
        cout << "Memory allocation failed\n";
        return;
    }

    cout << "Enter the element which you want to insert: ";
    cin >> New->data;

    node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = New;
    New->next = head;
    head = New;

    cout << "Node is inserted at the beginning\n";
}

// Function to insert a node after a specific element in the circular linked list
void insert_after() {
    if (head == nullptr) {
        cout << "List is empty. Use create() to initialize the list.\n";
        return;
    }

    int key;
    cout << "Enter the element after which you want to insert: ";
    cin >> key;

    node *temp = head;
    do {
        if (temp->data == key) {
            node *New = new node;
            if (New == nullptr) {
                cout << "Memory allocation failed\n";
                return;
            }

            cout << "Enter the element which you want to insert: ";
            cin >> New->data;

            New->next = temp->next;
            temp->next = New;

            cout << "Node inserted after " << key << "\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Element " << key << " not found in the list\n";
}

int main() {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create Circular Linked List\n";
        cout << "2. Display Circular Linked List\n";
        cout << "3. Insert at Head\n";
        cout << "4. Insert at Last\n";
        cout << "5. Insert After Element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_head();
                break;
            case 4:
                insert_last();
                break;
            case 5:
                insert_after();
                break;
            case 6:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}