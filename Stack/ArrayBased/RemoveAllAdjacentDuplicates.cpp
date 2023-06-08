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


string remove_duplicates(string& s) {
    int length = s.size();
    Stack stk(length);
    stk.push(s[0]);
    for(int i = 1; i < length; i++) {
        if(stk.isEmpty()) stk.push(s[i]);
        else if(stk.peek() == s[i]) stk.pop();
        else stk.push(s[i]);
    }
    string res = "";
    while (!stk.isEmpty()) {
        res += (char)stk.pop();
    }

    return reverse_sub(res);
}

int main() {

  
  string str = "abbacaddeeraashhhsffgttgf";
  cout << "Remove duplicateds: " << str << " -----> " << remove_duplicates(str) << '\n';
  return 0;
}