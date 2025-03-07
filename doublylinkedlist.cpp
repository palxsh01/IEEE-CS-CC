#include <iostream>
using namespace std;

typedef struct node {    //Create structure for node
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;    //Initialize head node as null

void insert() {    //Function to insert a node
    string m;
    int data;

    node *newNode = new node;    //Creating a new empty node
    newNode -> prev = NULL;
    newNode -> next = NULL;

    cout << "Where do you wish to insert node? Head (H) or Tail (T): ";    //User input for inserting at head or tail
    cin >> m;

    cout << "Enter data: ";
    cin >> data;
    newNode -> data = data;    //Setting input as data for newly created node
    
    if (m == "H" || m == "h") {
        newNode -> next = head;
        if (head != NULL) {    //Checking if list is empty
            head -> prev = newNode;
        }
        head = newNode;    //Setting new node as head node
    } else if (m == "T" || m == "t") {
        if (head == NULL) {    //Checking if list is empty
            head = newNode;
            newNode -> next = NULL;    //Setting node as tail node
        } else {    
            node *ptr = head;    
            while (ptr -> next != NULL) {    //Traversing to end of list
                ptr = ptr -> next;
            }
            ptr -> next = newNode;    //Setting new node as last node
            newNode -> prev = ptr;
        }
    } else {    //Incorrect input error
        cout << "Incorrect Input!";
    }
}

void display() {
    node *ptr = head;    //Initializing traversal pointer to head 
    int index = 1;    //Index variable to track number of nodes
    if (ptr == NULL) {    //Checking if list is empty
        cout << "The list is empty." << endl;
        return;
    }
    while (ptr != NULL) {    //Traversing list and printing data for each node
        cout << "Node " << index << ": " << ptr -> data << endl;
        index++;
        ptr = ptr -> next;
    }
}

void menu() {    //Menu function
    string m;
    cout << "Insert (I)  or  Display (D): ";
    cin >> m;
    if (m == "I" || m == "i") {
        insert();
    } else if (m == "D" || m == "d") {
        display();
    } else {    //Incorrect input error
        cout << "Incorrect input!" << endl;
    }

    string c;
    cout << "Do you wish to continue? Yes (Y) or No (N): ";
    cin >> c;
    if (c == "Y" || c == "y") {
        menu();
    } else if (c == "N" || c == "n") {
        cout << "Program Terminated.";
    } else {    //Incorrect input error
        cout << "Incorrect input!" << endl << "Program Terminated.";
    }
}

int main() {
    menu();
    return 0;
}
