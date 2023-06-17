#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


struct Node {
    int val;
    Node* next{};

    Node(int data) : val(data) {}
    ~Node() {std::cout<< "Destruct the node: " << val << '\n';}
};

class LinkedList {
    Node* head;
    Node* tail;
    int length = 0;

public:
    LinkedList(){
        head = tail = nullptr;
        length = 0;
    };

    bool isEmpty() {
        return length == 0;
    }

    void print() {
        Node* temp = head;
        while(temp != nullptr)
        {
            std::cout << temp->val << ' ';
            temp = temp->next;
        }
        std::cout << '\n';
    }

    Node* getHead() {return head;}
    void insertNode(int val) {
        Node* newNode = new Node(val);
        if(!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void insertFront(int val) {
        Node* newNode = new Node(val);
        if(!head) head = tail = newNode;
        else newNode->next = head, head = newNode;
        length++;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if(!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    int deleteFront() {
        if(!head) return -1e9;
        if(head == tail) {delete head; head = tail = nullptr;}
        Node* deletedNode = head;
        head = head->next;
        delete deletedNode;
        length--;
    }

    ~LinkedList() {
        Node* temp;
        while(head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

};


class LinkedQueue {
private:
    LinkedList list;
public:

    bool isEmpty() {
        return list.isEmpty();
    }

    void enqueue(int val) {
        list.insertEnd(val);
    }

    int dequeue() {
        int val = list.getHead()->val;
        list.deleteFront();
        return val;
    }

    void print() {
        list.print();
    }

};

int main() {

    LinkedQueue q;
    q.enqueue(2);
    q.enqueue(8);
    q.enqueue(3);
    q.enqueue(7);

    q.print();

    q.dequeue();
    q.dequeue();

    q.enqueue(8);
    q.enqueue(396);
    q.enqueue(8);
    q.enqueue(15);

    q.print();

    return 0;
}
