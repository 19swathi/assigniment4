#include <iostream>

// Node class for a singly linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class to manage the linked list operations
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    // Function to insert a new element at the end of the linked list
    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        std::cout << "Element " << value << " inserted successfully.\n";
    }

    // Function to delete an element from the linked list
    void remove(int value) {
        if (head == nullptr) {
            std::cout << "List is empty. Cannot delete.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << "Element " << value << " deleted successfully.\n";
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Element " << value << " not found in the list.\n";
        }
        else {
            prev->next = current->next;
            delete current;
            std::cout << "Element " << value << " deleted successfully.\n";
        }
    }

    // Function to display the elements of the linked list
    void display() {
        Node* temp = head;

        if (temp == nullptr) {
            std::cout << "List is empty.\n";
            return;
        }

        std::cout << "Linked List: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

int main() {
    LinkedList linkedList;

    while (true) {
        std::cout << "\n1. Insert Element\n";
        std::cout << "2. Delete Element\n";
        std::cout << "3. Display List\n";
        std::cout << "4. Exit\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            std::cout << "Enter the element to insert: ";
            std::cin >> value;
            linkedList.insert(value);
            break;
        }
        case 2: {
            int value;
            std::cout << "Enter the element to delete: ";
            std::cin >> value;
            linkedList.remove(value);
            break;
        }
        case 3:
            linkedList.display();
            break;
        case 4:
            std::cout << "Exiting the program. Goodbye!\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}