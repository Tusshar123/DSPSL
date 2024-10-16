 #include <iostream>
using namespace std;

int main() {
    int n, target;
    
    cout << "Enter the Number of Elements: ";
    cin >> n;

    int arr[n];
    
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Enter element At [" << i << "] : ";
        cin >> arr[i];
    }

    cout << "Given Array: [ ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i < n - 1 ? ", " : " ");
    }
    cout << "]\n";

    cout << "Enter the target element to search for: ";
    cin >> target;

    int index = -1;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "Element found at index: " << index << "\n";
    } else {
        cout << "Element not found.\n";
    }

    return 0;
}
