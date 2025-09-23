#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked List class
class SinglyLinkedList {
    Node* head;

public:
    void init() { head = nullptr; }

    // Insert at beginning
    void insertAtBeginning(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
    }

    // Insert at given position (1-based index)
    void insertAtPosition(int x, int pos) {
        Node* newNode = new Node();
        newNode->data = x;

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Position out of range\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted: " << temp->data << endl;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) {
            cout << "Deleted: " << head->data << endl;
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) temp = temp->next;
        cout << "Deleted: " << temp->next->data << endl;
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete from given position
    void deleteFromPosition(int pos) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        if (pos == 1) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted: " << temp->data << endl;
            delete temp;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        cout << "Deleted: " << toDelete->data << endl;
        delete toDelete;
    }

    // Display list
    void display() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


int main() {
    SinglyLinkedList list;
    list.init();

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtPosition(15, 2);

    list.display();

    list.deleteFromBeginning();
    list.display();

    list.deleteFromEnd();
    list.display();

    list.deleteFromPosition(2);
    list.display();

    return 0;
}
