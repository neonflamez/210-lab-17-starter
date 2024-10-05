// COMSC 210 || Lab 17 || Shayan Khan

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
Node* addNodeToFront(Node *, float);
Node* addNodeToTail(Node *, float);
Node* deleteNode(Node *, int);
Node* insertNode(Node *, int, float);
void deleteList(Node *&);

int main() {
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        head = addNodeToFront(head, rand() % 100);
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    head = deleteNode(head, entry);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    head = insertNode(head, entry, 10000);
    output(head);

    // deleting the linked list
    deleteList(head);
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

Node* addNodeToFront(Node *head, float value){
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if(!head){
        return newNode;
    }

    Node *current = head;
    while (current->next){
        current = current->next;
    }
    current->next = newNode;
    return head;
    
}

Node* deleteNode(Node *head, int position){
    if(!head) return head;

    Node *current = head;
    Node *prev = nullptr;

    if(position == 1){
        head = current->next;
        delete current;
        return head;
    }

    for(int i = 1; i < position && current != nullptr; i++){
        prev = current;
        current = current->next;
    }

    if(current){
        prev->next = current->next;
        delete current;
    }
    
    return head;

}












