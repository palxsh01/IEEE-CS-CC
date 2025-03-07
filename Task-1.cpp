#include <iostream>
using namespace std;
#define MAX 50  

class stack {
    private:
    int minStack[MAX];  
    int maxStack[MAX];  
    int mainStack[MAX]; 
    int top;            

    public:
    stack() {
        top = -1;    
    }

    void push(int x) {
        if (top + 1 >= MAX) {  
            cout << "Stack full!" << endl;
            return;
        }
        top++;    
        mainStack[top] = x;

        if (top == 0) {     
            minStack[top] = x;
            maxStack[top] = x;
        } else {
            minStack[top] = min(x, minStack[top - 1]);
            maxStack[top] = max(x, mainStack[top - 1]);
        }

        cout << "Data pushed!" << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack empty!" << endl;
            return;
        }
        top--;

        cout << "Data popped!" << endl;
    }

    int getTop() {
        if (top == -1) {
            cout << "Stack empty!" << endl;
            return -1;
        }
        return mainStack[top];
    }

    int getMin() {
        if (top == -1) {
            cout << "Stack empty!" << endl;
            return -1;
        }
        return minStack[top];
    }

    int getMax() {
        if (top == -1) {
            cout << "Stack empty!" << endl;
            return -1;
        }
        return maxStack[top];
    }

    void display() {
        if (top == -1) {
            cout << "Stack empty!" << endl;
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << "Index " << i + 1 << ": " << mainStack[i] << endl;
        }
    }
};

void menu(stack a) {
    int m;
    cout << "Push (1)  |  Pop (2)  |  Top (3)  |  getMin (4)  |  getMax (5)  |  Display (6)" << endl;
    cout << "Select an option: ";
    cin >> m;
    if (m == 1) {
        int x;
        cout << "Enter data to push: ";
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
    } else {
        cout << "Incorrect input!" << endl;
    }

    string c;
    cout << "Do you wish to continue? Yes (Y) or No (N): ";
    cin >> c;
    if (c == "Y" || c == "y") {
        menu(a);
    } else if (c == "N" || c == "n") {
        cout << "Program Terminated.";
    } else {
        cout << "Incorrect input!" << endl << "Program Terminated.";
    }
}

int main() {
    stack a;
    menu(a);
    return 0;
}