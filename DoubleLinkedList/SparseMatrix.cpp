#include <iostream>
#include <cassert>
#include <climits>

#include <vector>		// for debug
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
        if(arr2.length != length) {
            cerr << "Not matched dimentsions\n";
            return;
        }
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


struct MatrixRow {
    ArrayLinkedList row;
    MatrixRow* nextRow;
    MatrixRow* prevRow;
    int rowIndex;

    MatrixRow(ArrayLinkedList& currRow, int index): rowIndex(index), row(currRow) {}
};

class SparseMatrix {
    int rows;
    int cols;
    MatrixRow* firstRow;
    MatrixRow* lastRow;

    bool is_valid_index(int i, int j) {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }


public:

    SparseMatrix(int n = 10, int m = 10) : rows(n), cols(m), firstRow(nullptr), lastRow(nullptr) {}

    void link(MatrixRow* first, MatrixRow* second) {
        if(first)
            first->nextRow = second;
        if(second)
            second->prevRow = first;
    }


    void insert_end(ArrayLinkedList& row, int rowNum) {

        MatrixRow* currRow = new MatrixRow(row, rowNum);
        if (!firstRow)
            firstRow = lastRow = currRow;
        else {
            link(lastRow, currRow);
            lastRow = currRow;
        }
    }

    void insert_front(ArrayLinkedList& row, int rowNum) {
        MatrixRow* currRow = new MatrixRow(row, rowNum);

        if (!firstRow)
            firstRow = lastRow = currRow;

        else {
            link(currRow, firstRow);
            firstRow = currRow;
        }
    }

    void set_value(int value, int i, int j) {
        if(!is_valid_index(i, j)) return;

        ArrayLinkedList r(cols);
        r.set_value(value, j);
        r.print_array_nonzero();


        if(!firstRow || firstRow->rowIndex > i) {
            insert_front(r, i);
            return;
        }

        MatrixRow* curr = firstRow;
        while(curr && i > curr->rowIndex)
            curr = curr->nextRow;

        if(!curr) {
            insert_end(r, i);
            return;
        }

        if(curr->rowIndex == i) curr->row.set_value(j, value);
        else {
            MatrixRow* newNode = new MatrixRow(r, i);
            MatrixRow* prevNode = curr->prevRow;
            link(prevNode, newNode);
            link(newNode, curr);
        }
    }

    int get_value(int i, int j) {
        if(!is_valid_index(i, j)) {
            cerr << "Invalid Index :(\n";
            return -1e9 + 7;
        }
        MatrixRow* curr = firstRow;
        while(curr && curr->rowIndex != i) {
            if(i < curr->rowIndex) return 0;
            curr = curr->nextRow;
        }
        if(curr) return curr->row.get_value(j);
        return 0;
    }

    void print_matrix() {
        int currRow = 0;
        MatrixRow* curr = firstRow;
        while(currRow < rows) {
            if(curr && curr->rowIndex == currRow) {
                curr->row.print_array();
                curr = curr->nextRow;
            } else {
                for (int i = 0; i < cols; i++) cout << "0 ";
                cout << '\n';
            }
            currRow++;
        }
        cout << '\n';
    }

    void print_matrix_nonzero() {
        MatrixRow* curr = firstRow;
        while(curr) {
            curr->row.print_array_nonzero();
            curr = curr->nextRow;
        }
        cout << '\n';
    }

    void add(SparseMatrix& mat) {
        if(mat.cols != cols || mat.rows != rows) {
            cerr << "Not matched dimentsions\n";
            return;
        }
        MatrixRow* curr1 = firstRow, *curr2 = mat.firstRow;
        while(curr1) {
            if(curr1->rowIndex == curr2->rowIndex) {
                curr1->row.add(curr2->row);
                curr1 = curr1->nextRow;
                curr2 = curr2->nextRow;
            } else if(curr1->rowIndex > curr2->rowIndex) {
                MatrixRow* prevCurr1 = curr1->prevRow;
                MatrixRow* newMatrixNode = new MatrixRow (curr2->row, curr2->rowIndex);
                link(prevCurr1, newMatrixNode);
                link(newMatrixNode, curr1);
                curr2 = curr2->nextRow;
            } else {
                curr1 = curr1->nextRow;
            }
        }

        while(curr2) insert_end(curr2->row, curr2->rowIndex), curr2 = curr2->nextRow;
    }

};

int main() {

    SparseMatrix mat(10, 10);
    SparseMatrix mat2(10, 10);

    mat.set_value(5, 3, 5);
    mat.set_value(7, 3, 7);
    mat.set_value(2, 3, 2);
    mat.set_value(0, 3, 2);
    mat.set_value(6, 5, 6);
    mat.set_value(4, 5, 4);
    mat.set_value(3, 7, 3);
    mat.set_value(1, 7, 1);

    mat2.set_value(6, 5, 6);
    mat2.set_value(4, 5, 4);
    mat2.set_value(3, 7, 3);
    mat2.set_value(1, 7, 1);
    //mat.print_matrix_nonzero();
    //mat.print_matrix();
    mat.add(mat2);

    mat.print_matrix();

    cout << "value at (3, 2) = " << mat.get_value(3, 2) << '\n';

    cout << "\n\nNO RTE\n";

    return 0;
}