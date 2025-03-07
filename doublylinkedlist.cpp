#include <iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;

void insert() {
    string m;
    int data;

    node *newNode = new node;
    newNode -> prev = NULL;
    newNode -> next = NULL;

    cout << "Where do you wish to insert node? Head (H) or Tail (T): ";
    cin >> m;

    cout << "Enter data: ";
    cin >> data;
    newNode -> data = data;
    
    if (m == "H" || m == "h") {
        newNode -> next = head;
        if (head != NULL) {
            head -> prev = newNode;
        }
        head = newNode;
    } else if (m == "T" || m == "t") {
        if (head == NULL) {
            head = newNode;
            newNode -> next = NULL;
        } else {
            node *ptr = head;
            while (ptr -> next != NULL) {
                ptr = ptr -> next;
            }
            ptr -> next = newNode;
            newNode -> prev = ptr;
        }
    } else {
        cout << "Incorrect Input!";
    }
}

void display() {
    node *ptr = head; 
    int index = 1;
    if (ptr == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    while (ptr != NULL) { 
        cout << "Node " << index << ": " << ptr -> data << endl;
        index++;
        ptr = ptr -> next;
    }
}

void menu() {
    string m;
    cout << "Insert (I)  or  Display (D): ";
    cin >> m;
    if (m == "I" || m == "i") {
        insert();
    } else if (m == "D" || m == "d") {
        display();
    } else {
        cout << "Incorrect input!" << endl;
    }

    string c;
    cout << "Do you wish to continue? Yes (Y) or No (N): ";
    cin >> c;
    if (c == "Y" || c == "y") {
        menu();
    } else if (c == "N" || c == "n") {
        cout << "Program Terminated.";
    } else {
        cout << "Incorrect input!" << endl << "Program Terminated.";
    }
}

int main() {
    menu();
    return 0;
}