#include <iostream>
using namespace std;

struct Node {
    int rollNo;
    string name;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int rollNo, string name) {
    Node* newNode = new Node();
    newNode->rollNo = rollNo;
    newNode->name = name;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList() {
    if (head == NULL) {
        cout << "Waiting list is empty!\n";
        return;
    }

    Node* temp = head;
    cout << "\nWaiting List:\n";
    while (temp != NULL) {
        cout << "Roll No: " << temp->rollNo
            << " | Name: " << temp->name << endl;
        temp = temp->next;
    }
}

int countStudents() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}