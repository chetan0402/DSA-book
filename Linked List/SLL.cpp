#include <iostream>

// Node struct
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// SinglyLinkedList struct
struct SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() : head(nullptr) {}

    // Insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Get the value at a specific index
    int get(int index) {
        if (index < 0) {
            std::cout << "Invalid index" << std::endl;
            return -1;
        }

        Node* current = head;
        int count = 0;

        while (current != nullptr) {
            if (count == index) {
                return current->data;
            }
            current = current->next;
            count++;
        }

        std::cout << "Index out of range" << std::endl;
        return -1;
    }

    // Print the elements of the list
    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};