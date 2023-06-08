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

bool is_closing(char c) {return c == ')' || c == ']' || c == '}';}
bool is_opening(char c) {return c == '(' || c == '[' || c == '{';}
bool is_matched(char c1, char c2) {
    return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
}

bool is_valid(const string& str) {
    Stack stk(str.size());
    int len = str.length();
    for(int i = 0; i < len; i++) {
        if(stk.isEmpty() && is_closing(str[i])) return false;
        if(is_closing((char)str[i])) {
            if(is_matched((char)stk.peek(), (char)str[i]))
                stk.pop();
            else return false;
        }
        else if(is_opening(str[i])) stk.push((int)str[i]);
    }
    return stk.isEmpty();
}

int main() {
    string parentheses = "(((())))";
    cout << "parentheses_1: " << parentheses << (is_valid(parentheses) ? " is valid\n" : " is not valid\n");

    parentheses = "([)]";
    cout << "parentheses_2: " << parentheses << (is_valid(parentheses) ? " is valid\n" : " is not valid\n");

  return 0;
}