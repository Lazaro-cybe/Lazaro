#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void reverse(Node*& head) {
    Node *prev = nullptr, *current = head, *next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    Node* head = nullptr;

    // Hardcoded values
    int values[] = {10, 20, 30, 40, 50};
    for (int value : values) {
        append(head, value);
    }

    cout << "Original List: ";
    display(head);

    reverse(head);
    cout << "Reversed List: ";
    display(head);

    return 0;
}
