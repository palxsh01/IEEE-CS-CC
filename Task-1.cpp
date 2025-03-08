#include <iostream>
using namespace std;
//Constant for maximum array size
#define MAX 50    

class stack {
    private:
    int minStack[MAX];    //Initialize main array
    int maxStack[MAX];    //Initialize array to retrieve min value 
    int mainStack[MAX];   //Initialize array to retrieve max value
    int top;              //Initialize variable to store top index

    public:
    stack() {             //Constructor to initialize top
        top = -1;    
    }

    void push(int x) {
        if (top + 1 >= MAX) {    //Stack Overflow
            cout << "Stack full!" << endl;
            return;
        }
        top++;    //Increment top to store new data 
        mainStack[top] = x;

        if (top == 0) {     //Initializing empty stack
            minStack[top] = x;
            maxStack[top] = x;
        } else {            //Adding pushed data to min or max based on value
            minStack[top] = min(x, minStack[top - 1]);
            maxStack[top] = max(x, mainStack[top - 1]);
        }

        cout << "Data pushed!" << endl;
    }

    void pop() {
        if (top == -1) {    //Stack Underflow
            cout << "Stack empty!" << endl;
            return;
        }
        top--;    //Decrement top to delete last element

        cout << "Data popped!" << endl;
    }

    void getTop() {
        if (top == -1) {    //Stack Underflow
            cout << "Stack empty!" << endl;
            return;
        }
        cout << "Data at top index: " <<mainStack[top] << endl;    //Return data at top index in stack
    }

    void getMin() {
        if (top == -1) {    //Stack Underflow
            cout << "Stack empty!" << endl;
            return;
        }
        cout << "Minimum value in stack: " << minStack[top] << endl;    //Return minimum value in stack
    }

    void getMax() {
        if (top == -1) {    //Stack Underflow
            cout << "Stack empty!" << endl;
            return;
        }
        cout << "Maximum value in stack: " << maxStack[top] << endl;    //Return maximum value in stack
    }

    void display() {
        if (top == -1) {    //Stack Underflow
            cout << "Stack empty!" << endl;
            return;
        }
        for (int i = 0; i <= top; i++) {    //Loop to print all elements in stack
            cout << "Index " << i + 1 << ": " << mainStack[i] << endl;
        }
    }
};

void menu(stack a) {    //Function to perform operations
    int m;
    cout << "Push (1)  |  Pop (2)  |  Top (3)  |  getMin (4)  |  getMax (5)  |  Display (6)  |  Exit (7)" << endl;    //Options in the menu
    cout << "Select an option: ";
    cin >> m;
    if (m == 1) {
        int x;
        cout << "Enter data to push: ";    //Input data to push onto stack
        cin >> x;
        a.push(x);
    } else if (m == 2) {
        a.pop();
    } else if (m == 3) {
        a.getTop();
    } else if (m == 4) {
        a.getMin();
    } else if (m == 5) {
        a.getMax();
    } else if (m == 6) {
        a.display();
    } else if (m == 7) {
        cout << "Program Terminated.";
        return;
    } else {
        cout << "Incorrect input!" << endl;    //Incorrect input error
    }

    string c;
    cout << "Do you wish to continue? Yes (Y) or No (N): ";    //Option to continue program
    cin >> c;
    if (c == "Y" || c == "y") {
        menu(a);
    } else if (c == "N" || c == "n") {
        cout << "Program Terminated.";
        return;
    } else {
        cout << "Incorrect input!" << endl << "Program Terminated.";    //Incorrect input error
        return;
    }
}

int main() {
    stack a;    //Initialize stack
    menu(a);    //Call menu function
    return 0;
}
