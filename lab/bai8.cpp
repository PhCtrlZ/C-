#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}
    
    void display() {
        Node* p = head;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    
    void insertAtBeginning(int x) {
        Node* p = new Node;
        p->data = x;
        p->next = head;
        head = p;
    }
    
    void insertAtEnd(int x) {
        Node* p = new Node;
        p->data = x;
        p->next = nullptr;
        if (!head) head = p;
        else {
            Node* q = head;
            while (q->next) q = q->next;
            q->next = p;
        }
    }
    
    bool search(int x) {
        Node* p = head;
        while (p) {
            if (p->data == x) return true;
            p = p->next;
        }
        return false;
    }
    
    void deleteFirst() {
        if (head) {
            Node* p = head;
            head = head->next;
            delete p;
        }
    }
    
    void deleteLast() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* p = head;
        while (p->next->next) p = p->next;
        delete p->next;
        p->next = nullptr;
    }
    
    void sortAscending() {
        if (!head) return;
        bool swapped;
        do {
            swapped = false;
            Node* p = head;
            while (p->next) {
                if (p->data > p->next->data) {
                    swap(p->data, p->next->data);
                    swapped = true;
                }
                p = p->next;
            }
        } while (swapped);
    }
    
    void insertSorted(int x) {
        Node* p = new Node;
        p->data = x;
        if (!head || head->data >= x) {
            p->next = head;
            head = p;
            return;
        }
        Node* q = head;
        while (q->next && q->next->data < x) q = q->next;
        p->next = q->next;
        q->next = p;
    }
};

int main() {
    SinglyLinkedList list;
    
    list.insertAtBeginning(5);
    list.insertAtBeginning(3);
    list.insertAtEnd(7);
    list.display();
    
    cout << "Tim 5: " << list.search(5) << endl;
    
    list.deleteFirst();
    list.display();
    
    list.sortAscending();
    list.display();
    
    list.insertSorted(4);
    list.display();
    
    return 0;
}