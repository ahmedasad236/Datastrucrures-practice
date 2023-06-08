#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Stack {
private:
    int size { };
    int top { };
    int* array { };
public:
    Stack(int size = 20) :
            size(size), top(size) {
        array = new int[size];
    }

    ~Stack() {
        delete[] array;
    }

    void push(int x) {
        assert(!isFull());
        array[--top] = x;
    }

    int pop() {
        assert(!isEmpty());
        return array[top++];
    }

    int peek() {
        assert(!isEmpty());
        return array[top];
    }

    int isFull() {
        return top == 0;
    }

    int isEmpty() {
        return top == size;
    }

    void display() {
        for (int i = top; i < size; i++)
            cout << array[i] << " ";
        cout << "\n";
    }

    int length() {
        return size - top;
    }

    void insert_at_bottom(int x) {
        if(isEmpty()) {
            push(x);
            return;
        }
        int currPeek = pop();
        insert_at_bottom(x);
        this->push(currPeek);
    }

    void reverse() {
        if(isEmpty()) return;
        int currPeek = pop();
        reverse();
        insert_at_bottom(currPeek);
    }

};


int main() {

  cout << "********************************** Excercise 1 ****************************************************\n";


    Stack stk(20);
    stk.push(10);
    stk.push(20);
    stk.push(30);

    if (!stk.isFull())
        stk.push(50);
    else
        cout << "Full Stack\n";
    stk.display();	// 30 20 10
    cout << stk.peek() << "\n";	// 30

    while (!stk.isEmpty()) {
        cout << stk.peek() << " ";
        stk.pop();
    } // 30 20 10


    cout << "******************* Insert at the end *******************************************\n";
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.display();
    stk.insert_at_bottom(7);
    stk.insert_at_bottom(8);
    stk.display();
    stk.reverse();
    stk.display();


  return 0;
}