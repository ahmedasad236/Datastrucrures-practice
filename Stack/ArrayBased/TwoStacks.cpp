#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class TwoStacks {
private:
    int size { };
    int top1 { };
    int top2 { };
    int* array { };
public:
    TwoStacks(int size = 20) :
            size(size), top2(size), top1(-1) {
        array = new int[size];
    }

    ~TwoStacks() {
        delete[] array;
    }

    void push(int id, int x) {
        assert(!isFull(id));
        switch (id) {
            case 1:
                array[++top1] = x;
                break;
            case 2:
                array[--top2] = x;
                break;
        }
    }

    int pop(int id) {
        assert(!isEmpty(id));
        switch (id) {
            case 1:
                return array[top1--];
            case 2:
                return array[top2++];
        }
    }

    int peek(int id) {
        assert(!isEmpty(id));
        switch (id) {
            case 1:
                return array[top1];
            case 2:
                return array[top2];
        }
    }

    int isFull(int id) {
        switch (id) {
            case 1:
                return top1 + 1 == top2;
            case 2:
                return top2 - 1 == top1;
        }
    }

    int isEmpty(int id) {
        switch (id) {
            case 1:
                return top1 == -1;
            case 2:
                return top2 == size;
        }
    }



    void display() {
        if(!isEmpty(1)) {
            for (int i = top1; i >= 0; i--)
                cout << array[i] << " ";
            cout << "\n";
        }
        if(!isEmpty(2)) {
            for (int i = top2; i < size; i++)
                cout << array[i] << " ";
            cout << '\n';
        }
    }

};

int main() {

    TwoStacks two_stk(10);
    two_stk.push(2, 5);
    two_stk.push(2, 6);
    two_stk.pop(2);
    two_stk.push(2, 7);
    two_stk.push(2, 9);
    two_stk.display();
    two_stk.push(1, 4);
    cout << "peek(1): " << two_stk.peek(1) << '\n';
    cout << "peek(2): " << two_stk.peek(2) << '\n';

    two_stk.push(1, 6);
    two_stk.push(1, 8);
    two_stk.push(2, 3);
    two_stk.display();
    cout << "*****************************************************\n";

    return 0;
}