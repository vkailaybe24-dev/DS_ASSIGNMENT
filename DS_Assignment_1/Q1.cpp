#include <iostream>
using namespace std;

int arr[100];
int n = 0; // current number of elements

void createArray() {
    cout << "Enter the length of array: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void displayArray() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void insertElement() {
    int pos, val;
    cout << "Enter position (0 to " << n << "): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;
    if (pos < 0 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

void deleteElement() {
    int pos;
    cout << "Enter position to delete (0 to " << n - 1 << "): ";
    cin >> pos;
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void searchElement() {
    int val, found = 0;
    cout << "Enter element to be searched: ";
    cin >> val;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            cout << "Found at position " << i << "\n";
            found = 1;
        }
    }
    if (!found) cout << "Element not found.\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n------MENU------\n";
        cout << "1. Create Array\n";
        cout << "2. Display Array\n";
        cout << "3. Insert Element\n";
        cout << "4. Delete Element\n";
        cout << "5. Search Element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: searchElement(); break;
            case 6: return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}

