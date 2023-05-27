// This is a sparse Array implemented using a doubly linked list

#include <iostream>
#include <cassert>
#include <climits>
#include <algorithm>
#include <sstream>
using namespace std;

struct Node {
    int data { };
    int index { };
    Node* next { };
    Node* prev { };	 // Previous node!

    Node(int data) : data(data) {}
    Node(int data, int index) : data(data), index(index) {}
    void set(Node* next, Node* prev) {
        this->next = next;
        this->prev = prev;
    }

    ~Node() {
        cout << "Destroy value: " << data << " at address " << this << "\n";
    }
};


class ArrayLinkedList {
    Node *head { };
    Node *tail { };
    int length = 0;
    bool check_index(int index) {
        return index >= 0 && index < length;
    }

public:
    ArrayLinkedList(int len) : length(len) {
    }
    ArrayLinkedList(const ArrayLinkedList&) = delete;
    ArrayLinkedList &operator=(const ArrayLinkedList &another) = delete;

    void link(Node* first, Node*second) {
        if(first)
            first->next = second;
        if(second)
            second->prev = first;
    }


    void insert_end(int value, int index) {
        Node* item = new Node(value, index);

        if (!head)
            head = tail = item;
        else {
            link(tail, item);
            tail = item;
        }
    }
    void insert_front(int value, int index) {
        Node* item = new Node(value, index);

        if (!head)
            head = tail = item;
        else {
            link(item, head);
            head = item;
        }
    }

    void set_value(int value, int index) {
        if(!check_index(index)) return;

        if(!head || head->index > index) {
            insert_front(value, index);
            return;
        }

        Node* curr = head;
        while(curr && index > curr->index)
            curr = curr->next;
        if(!curr) {
            insert_end(value, index);
            return;
        }
        if(curr->index == index) curr->data = value;
        else {
            Node* newNode = new Node(value, index);
            Node* prevNode = curr->prev;
            link(prevNode, newNode);
            link(newNode, curr);
        }
    }

    int get_value(int index) {
        if(!check_index(index)) {
            cerr << "Invalid Index :(\n";
            return -1e9 + 7;
        }
        Node* curr = head;
        while(curr && curr->index != index) {
            if(index < curr->index) return 0;
            curr = curr->next;
        }
        if(curr) return curr->data;
        return 0;
    }

    void print_array() {
        int currIndex = 0;
        Node* curr = head;
        while(currIndex < length) {
            if(curr && curr->index == currIndex) {
                cout << curr->data << ' ';
                curr = curr->next;
            } else cout << "0 ";
            currIndex++;
        }
        cout << '\n';
    }

    void print_array_nonzero() {
        Node* curr = head;
        while(curr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << '\n';
    }

    void add(const ArrayLinkedList& arr2) {
        Node* curr1 = head, *curr2 = arr2.head;
        while(curr1) {
            if(curr1->index == curr2->index) {
                curr1->data += curr2->data;
                curr2 = curr2->next;
                curr1 = curr1->next;
            } else if(curr1->index > curr2->index) {
                Node* prevCurr1 = curr1->prev;
                Node* newNode = new Node(curr2->data, curr2->index);
                link(prevCurr1, newNode);
                link(newNode, curr1);
                curr2 = curr2->next;
            } else {
                curr1 = curr1->next;
            }
        }

        while(curr2) insert_end(curr2->data, curr2->index), curr2 = curr2->next;
    }
};


int main() {

    ArrayLinkedList array(10);
    array.set_value(50, 5);
    array.set_value(20, 2);
    array.set_value(70, 7);
    array.set_value(40, 4);


    array.print_array();

    ArrayLinkedList array2(10);
    array2.set_value(1, 4);
    array2.set_value(3, 7);
    array2.set_value(4, 6);
    array2.set_value(4, 9);


    array2.print_array();

    array.add(array2);

    array.print_array();


    cout << array.get_value(2) << '\n';
    cout << array.get_value(10) << '\n';
    cout << array.get_value(-1) << '\n';
    cout << array.get_value(5) << '\n';


    cout << "\n\nNO RTE\n";

    return 0;
}

