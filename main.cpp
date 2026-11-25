#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct customList {
    int id;
    customList *next;
};

void readFromFile(customList *&l) {
    ifstream file("data.txt");

    customList *last = l;
    int val;

    while (file >> val) {
        customList *temp = new customList{val, nullptr};
        if (last == nullptr)
            l = temp;
        else
            last->next = temp;
        last = temp;
    }
    cout << "Data read from file.\n";
}
void findValue(customList *l, int num) {
    int i = 0;
    bool found = false;

    customList *temp = l;
    while (temp != nullptr) {
        if (temp->id == num) {
            cout << "Value found at index " << i+1 << ".\n";
            found = true;
        }
        temp = temp->next;
        i++;
    }
    if (found == false)
        cout << "Value not found.\n";
}
void deleteValue(customList *&l, int i) {
    customList *curr = l;
    customList *prev = nullptr;

    if (l == nullptr || i < 0) {
        cout << "Index out of range.\n";
        return;
    }

    for (int j = 0; j < i && curr != nullptr; j++) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr) {
        cout << "Index out of range.\n";
        return;
    }

    if (prev == nullptr)
        l = curr->next;
    else
        prev->next = curr->next;

    cout << "Value '" << curr->id << "' at index " << i+1 << " removed.\n";
    delete curr;
}
void reverseList(customList *&l) {
    customList *prev = nullptr;
    customList *curr = l;
    customList *next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    l = prev;
}
void displayList(customList *l) {
    int i = 1;
    customList *temp = l;

    if (l == nullptr) {
        cout << "No data available.\n";
        return;
    }

    cout << "\n";
    while (temp != nullptr) {
        cout << i << " | " << temp->id << endl;
        temp = temp->next;
        i++;
    }
    cout << "\n";
}
void truncateList(customList *&l) {
    while (l != nullptr) {
        customList *temp = l;
        l = l->next;
        delete temp;
    }
}
int main() {
    customList *l = nullptr;
    int choice, i;

    do {
        cout << "\n1 | Load data from file\n";
        cout << "2 | Display list\n";
        cout << "3 | Find value\n";
        cout << "4 | Delete entry\n";
        cout << "5 | Reverse list\n";
        cout << "6 | Exit and Free Memory\n\n";
        cin >> choice;
        cout << "\n";

        switch (choice) {
            case 1:
                readFromFile(l);
                break;
            case 2:
                displayList(l);
                break;
            case 3:
                if (l == nullptr)
                    cout << "List is empty.\n";
                else {
                    cout << "Value: ";
                    cin >> i;
                    findValue(l, i);
                }
                break;
            case 4:
                if (l == nullptr)
                    cout << "List is empty.\n";
                else {
                    displayList(l);
                    cout << "Index: ";
                    cin >> i;
                    deleteValue(l, i-1);
                }
                break;
            case 5:
                reverseList(l);
                break;
            case 6:
                truncateList(l);
                break;
        }
    } while (choice != 6);
    return 0;
}
