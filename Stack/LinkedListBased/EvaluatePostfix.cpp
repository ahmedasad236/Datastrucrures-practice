#include <iostream>
#include <cassert>
#include <climits>
#include <cmath>
using namespace std;

class Stack {
private:
    // Tip: We can make this struct internally
    struct Node {
        long long data { };
        Node* next { };
        Node(long long data) :
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

    void push(long long value) {
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
        long long element = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return element;
    }

    int peek() {
        assert(!isEmpty());
        long long element = head->data;
        return element;
    }

    int isEmpty() {
        return !head;
    }
};

long long eval_op(long long op1, long long op2, char op) {
    if(op == '+') return op1 + op2;
    else if(op == '-') return op1 - op2;
    else if(op == '*') return op1 * op2;
    else if(op == '^') return pow(op1, op2);
    else if(op == '/') return op1 / op2;
}

long long postfix_evaluation(string s) {
    Stack stk;
    for(auto c : s) {
        if(isdigit(c)) stk.push(c - '0');
        else {
            long long op2 = stk.pop(), op1 = stk.pop();
            long long res = eval_op(op1, op2, c);
            stk.push(res);
        }
    }
    return stk.peek();
}

int main() {

    string exp = "432^^";
    cout << postfix_evaluation(exp) << '\n';
    
    temp = "135*+72/-";

    cout << postfix_evaluation(exp) << '\n'; // -----> 12
    return 0;
}

