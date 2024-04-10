#include <iostream>

// Node structure
template <typename T>
struct Node {
    T data;
    Node* next;

    // Constructor
    Node(const T& val) : data(val), next(nullptr) {}
};

// Linked list class
template <typename T>
class LinkedList {
private:
    Node<6>* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
        clear();
    }

    // Function to insert a node at the beginning of the linked list
    void insertAtBeginning(const T& val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    // Function to clear the linked list
    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to print the linked list
    void printList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create a linked list object
    LinkedList<int> list;

    // Insert elements into the linked list
    list.insertAtBeginning(3);
    list.insertAtBeginning(5);
    list.insertAtBeginning(7);

    // Print the linked list
    std::cout << "Linked List: ";
    list.printList();

    return 0;
}
