#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Function to push an element onto the stack
    void push(int element) {
        if (!isFull()) {
            arr[++top] = element;
            std::cout << "Pushed: " << element << "\n";
        }
        else {
            std::cout << "Stack is full. Cannot push.\n";
        }
    }

    // Function to pop an element from the stack
    void pop() {
        if (!isEmpty()) {
            std::cout << "Popped: " << arr[top--] << "\n";
        }
        else {
            std::cout << "Stack is empty. Cannot pop.\n";
        }
    }

    // Function to display the elements of the stack
    void display() {
        if (!isEmpty()) {
            std::cout << "Stack: ";
            for (int i = 0; i <= top; ++i) {
                std::cout << arr[i] << " ";
            }
            std::cout << "\n";
        }
        else {
            std::cout << "Stack is empty.\n";
        }
    }
};

int main() {
    Stack stack;

    int choice, element;

    do {
        // Display menu options
        std::cout << "\n1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Display\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Perform actions based on user choice
        switch (choice) {
        case 1:
            std::cout << "Enter the element to push: ";
            std::cin >> element;
            stack.push(element); // Push the element onto the stack
            break;
        case 2:
            stack.pop(); // Pop the top element from the stack
            break;
        case 3:
            stack.display(); // Display the elements of the stack
            break;
        case 4:
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4); // Continue until the user chooses to quit

    return 0;
}