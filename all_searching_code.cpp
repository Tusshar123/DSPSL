#include <iostream>
using namespace std;

// Function to display the array
void display(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to perform linear search
void linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Element found at index " << i << endl;
            display(arr, n); // Show the current array after search
            return; // Stop after finding the element
        }
    }
    cout << "Element not found.\n";
    display(arr, n); // Show the current array after search
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Array sorted using Bubble Sort.\n";
}

// Function to perform binary search
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Element not found
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the element at the current position
        swap(arr[i], arr[minIndex]);
    }
    cout << "Array sorted using Selection Sort.\n";
}

int main() {
    int arr[100], n, choice;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Display Array\n";
        cout << "2. Linear Search\n";
        cout << "3. Binary Search\n";
        cout << "4. Bubble Sort\n";
        cout << "5. Selection Sort\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            display(arr, n);
        } else if (choice == 2) {
            int target;
            cout << "Enter element to search: ";
            cin >> target;
            linearSearch(arr, n, target);
        } else if (choice == 3) {
            int target;
            cout << "Enter element to search: ";
            cin >> target;
            bubbleSort(arr, n); // Ensure the array is sorted
            int index = binarySearch(arr, n, target);
            if (index != -1) {
                cout << "Element found at index " << index << endl;
            } else {
                cout << "Element not found.\n";
            }
            display(arr, n); // Show the array after the search
        } else if (choice == 4) {
            bubbleSort(arr, n);
        } else if (choice == 5) {
            selectionSort(arr, n);
        } else if (choice == 6) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
