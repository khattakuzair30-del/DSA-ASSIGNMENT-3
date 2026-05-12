#include <iostream>
using namespace std;

struct Node {
    int rollNo;
    string name;
    Node* next;
};

extern Node* head;

void deleteByRollNo(int rollNo) {
    if (head == NULL) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    if (temp->rollNo == rollNo) {
        head = temp->next;
        delete temp;
        cout << "Student deleted successfully.\n";
        return;
    }

    while (temp != NULL && temp->rollNo != rollNo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Student not found!\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Student deleted successfully.\n";
}

void searchStudent(int rollNo) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            cout << "Student Found:\n";
            cout << "Roll No: " << temp->rollNo << endl;
            cout << "Name: " << temp->name << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Student not found!\n";
}

void insertAtEnd(int, string);
void displayList();
int countStudents();

int main() {

    insertAtEnd(101, "Ali");
    insertAtEnd(102, "Sara");
    insertAtEnd(103, "Ahmed");
    insertAtEnd(104, "Zain");
    insertAtEnd(105, "Hina");

    displayList();

    cout << "\nSearching for Roll No 103:\n";
    searchStudent(103);

    cout << "\nDeleting Roll No 102:\n";
    deleteByRollNo(102);

    displayList();

    cout << "\nTotal Students Remaining: "
        << countStudents() << endl;

    return 0;
}