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


string reverse_sub(string word) {
    int length = word.size();
    Stack stk(length);
    string reversed_str = "";
    for(int i = 0; i < length; i++) {
        if(word[i] == ' ') {
            while(!stk.isEmpty()) {
                reversed_str += (char)stk.pop();
            }
            reversed_str += ' ';
        } else stk.push((int)word[i]);
    }

    while(!stk.isEmpty()) reversed_str += (char)stk.pop();
    return reversed_str;
}

int main() {

  cout << "\nreversed_subword: " << reverse_sub("abc d efg xy") << '\n';

  return 0;
}