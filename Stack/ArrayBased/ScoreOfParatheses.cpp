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


int scoreOfParentheses(string str) {
    Stack stk(str.size());

    stk.push(0);
    for(auto c : str) {
        if(c == '(') stk.push(0);
        else {
            int top = stk.pop();
            if(top == 0) top = 1;
            else top *= 2;

            int beforeTop = stk.peek() + top;
            stk.pop();
            stk.push(beforeTop);
        }
    }
    return stk.peek();
}

int main() {

    string temp = "()((())())";
    cout << "Score of __ " << temp << " __ = " << scoreOfParentheses(temp) << '\n';

    temp = "((())())";
    cout << "Score of __ " << temp << " __ = " << scoreOfParentheses(temp) << '\n';

    temp = "(())(())";
    cout << "Score of __ " << temp << " __ = " << scoreOfParentheses(temp) << '\n';
   
    return 0;
}