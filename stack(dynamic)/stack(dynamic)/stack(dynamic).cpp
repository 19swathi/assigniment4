#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int element) {
        if (!isFull()) {
            arr[++top] = element;
            std::cout << "Pushed: " << element << "\n";
        }
        else {
            std::cout << "Stack is full. Cannot push.\n";
        }
    }

    void pop() {
        if (!isEmpty()) {
            std::cout << "Popped: " << arr[top--] << "\n";
        }
        else {
            std::cout << "Stack is empty. Cannot pop.\n";
        }
    }

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
        std::cout << "\n1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Display\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter the element to push: ";
            std::cin >> element;
            stack.push(element);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.display();
            break;
        case 4:
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}