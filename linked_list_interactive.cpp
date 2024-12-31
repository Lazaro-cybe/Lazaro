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

// New function to find and display the middle element
void findMiddle(Node* head) {
    if (!head) {
        cout << "The list is empty.\n";
        return;
    }
    
    Node* slow = head;
    Node* fast = head;
    
    // Fast pointer moves twice as fast as slow
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    cout << "Middle element: " << slow->data << endl;
}

int main() {
    Node* head = nullptr;
    int n, value;

    cout << "Enter the number of elements to insert: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        append(head, value);
    }

    cout << "Original List: ";
    display(head);

    reverse(head);
    cout << "Reversed List: ";
    display(head);

    // Call the new function to find the middle element
    findMiddle(head);

    return 0;
}
