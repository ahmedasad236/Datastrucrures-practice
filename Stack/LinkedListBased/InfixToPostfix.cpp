#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

class Stack {
private:
    // Tip: We can make this struct internally
    struct Node {
        int data { };
        Node* next { };
        Node(int data) :
                data(data) {
        }
    };

    Node *head { };		// Points to Top

public:
    ~Stack() {
        while (!isEmpty())
            pop();
    }
    void display() {
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    void push(int value) {
        // By design: always new node = head
        // Great match with stack!
        Node* item = new Node(value);
        item->next = head;
        head = item;

        // Tip: This code works as long as machine has more RAM
        // In industry: You may check if return is null (can't create) or not.
    }

    int pop() {
        assert(!isEmpty());
        int element = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return element;
    }

    int peek() {
        assert(!isEmpty());
        int element = head->data;
        return element;
    }

    int isEmpty() {
        return !head;
    }
};

bool is_higher(char c1, char c2) {
    if(c1 == '^') return true;

    if(c1 == '*' || c1 == '/')
        return c2 != '^' && (c2 == '+' || c2 == '-');
    return false;
};

bool ischar(char c) {

    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string infix_to_postfix(string exp) {
    string exp_postfix = "";
    Stack ops;

    for(auto c : exp) {
        if(isdigit(c) || ischar(c)) exp_postfix += c;
        else if (c == '(' || (!ops.isEmpty() && ops.peek() == '(')) ops.push(c);
        else if(c == ')') {

            while(!ops.isEmpty() && ops.peek() != (int)'(') exp_postfix += ops.pop();

            if(!ops.isEmpty())
                ops.pop();
        }
        else {
            while(!ops.isEmpty() && ops.peek() != '(' && !is_higher(c, (char)ops.peek()))
                exp_postfix += (char)ops.pop();

            ops.push(c);
        }
    }
    while(!ops.isEmpty()) exp_postfix += (char)ops.pop();
    return exp_postfix;
}

int main() {


   string exp = "a+b*(c^d-e)^(f+G*h)-i";  // res: abcd^e-fGh*+^*+i-
   cout << infix_to_postfix(exp) << '\n';

   exp = "1+2^3^4*5-6";  // res:  1234^^5*+6-
   cout << infix_to_postfix(exp) << '\n';

   return 0;
}

