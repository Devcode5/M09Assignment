//
//  main.cpp
//  ProgrammingAssignmentPointers
//
//  Created by Aqila Nasiry on 4/15/25.
//

#include <iostream>
#include <string>
using namespace std;

void printMenu();
void printList(string *p, int size);
string *expand(string *p, int &size);
bool insertAtZero(string *p, string item, int &count);
bool insertAt(string *p, string item, int index, int &count);
bool insertAtEnd(string *p, string item, int &count);
bool removeFromEnd(string *p, int &count);
bool removeFrom(string *p, int index, int &count);
void sort(string *p, int count);

int main() {
    int size = 2;
    int count = 0;
    string *list = new string[size];
    int choice;

    do {
        printMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string item;
            cout << "Enter value: ";
            getline(cin, item);
            if (count == size) list = expand(list, size);
            insertAtEnd(list, item, count);
        } else if (choice == 2) {
            string item;
            cout << "Enter value: ";
            getline(cin, item);
            if (count == size) list = expand(list, size);
            insertAtZero(list, item, count);
        } else if (choice == 3) {
            string item;
            int index;
            cout << "Enter index: ";
            cin >> index;
            cin.ignore();
            cout << "Enter value: ";
            getline(cin, item);
            if (index < 0 || index > count) {
                cout << "Invalid index\n";
            } else {
                if (count == size) list = expand(list, size);
                insertAt(list, item, index, count);
            }
        } else if (choice == 4) {
            if (!removeFromEnd(list, count)) cout << "Nothing to remove.\n";
        } else if (choice == 5) {
            int index;
            cout << "Enter index to remove: ";
            cin >> index;
            if (!removeFrom(list, index, count)) cout << "Invalid index\n";
        } else if (choice == 6) {
            sort(list, count);
            cout << "List sorted.\n";
        } else if (choice == 7) {
            printList(list, count);
        } else if (choice == 8) {
            cout << "Bye!\n";
        } else {
            cout << "Try again.\n";
        }
    } while (choice != 8);

    delete[] list;
    return 0;
}








void printMenu() {
    cout << "\n Choose from the following menu options\n"
         << "1) Insert a new element at the end of the list.\n"
         << "2) Insert a new element at the beginning of the list\n"
         << "3) Insert an element into the list at a given index\n"
         << "4) Remove an element from the end of the list\n"
         << "5) Remove an element at a given index\n"
         << "6) Sort the list\n"
         << "7) Print the list\n"
         << "8) Exit\n"
         << "Your option: ";
}

void printList(string *p, int size) {
    for (int i = 0; i < size; i++) {
        cout << i << ": " << *(p + i) << endl;
    }
}

string *expand(string *p, int &size) {
    int newSize = size * 2;
    string *newArr = new string[newSize];
    for (int i = 0; i < size; i++) {
        *(newArr + i) = *(p + i);
    }
    delete[] p;
    size = newSize;
    return newArr;
}

bool insertAtZero(string *p, string item, int &count) {
    return insertAt(p, item, 0, count);
}

bool insertAtEnd(string *p, string item, int &count) {
    return insertAt(p, item, count, count);
}


/*
 the given index should not be greater than the count of strings currently in the list.
 If the index is out of bounds, return false.
 Otherwise, return true and update the count of elements in the list
 */
bool insertAt(string *p, string item, int index, int &count) {
    for (int i = count; i > index; i--) {
        *(p + i) = *(p + i - 1);
    }
    *(p + index) = item;
    count++;
    return true;
}

bool removeFromEnd(string *p, int &count) {
    if (count == 0) return false;
    count--;
    return true;
}

bool removeFrom(string *p, int index, int &count) {
    if (index < 0 || index >= count) return false;
    for (int i = index; i < count - 1; i++) {
        *(p + i) = *(p + i + 1);
    }
    count--;
    return true;
}

//Bubble sort
void sort(string *p, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (*(p + j) > *(p + j + 1)) {
                string temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }
}
