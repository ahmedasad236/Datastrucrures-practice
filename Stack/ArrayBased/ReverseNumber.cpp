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


int reverse_num(int num) {
    int ans = 0;
    Stack stk;
    Stack final_stack;
    while(num) {
        stk.push(num % 10);
        num /= 10;
    }
    while(!stk.isEmpty()) {
        final_stack.push(stk.pop());
    }

    while(!final_stack.isEmpty()) {
        ans *= 10;
        ans += final_stack.pop();
    }

    return ans;
}

int main() {

  cout << "reversed_num: " << reverse_num(123456789) << '\n';


  return 0;
}