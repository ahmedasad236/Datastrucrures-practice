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


string infix_to_postfix_modified(string exp) {
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
            // For equality in normal postfix, */-+ (LR) should be popped but ^  (RL) shouldn't
            // But for reversed infix, then ^ (LR) should be popped and +/*- (RL) shouldn't be popped
            while(!ops.isEmpty() && ops.peek() != '(' && (!is_higher(c, (char)ops.peek()) || (c == '^' && (char)ops.peek() == '^')))
                exp_postfix += (char)ops.pop();

            ops.push(c);
        }
    }
    while(!ops.isEmpty()) exp_postfix += (char)ops.pop();
    return exp_postfix;
}

string infix_to_prefix(string s) {
    string reversed_string = "";

    // reverse the original string
    for(int i = s.size() - 1; i >= 0; i--) {
        if(s[i] == '(') reversed_string += ')';
        else if(s[i] == ')') reversed_string += '(';
        else reversed_string += s[i];
    }
    reversed_string = infix_to_postfix_modified(reversed_string);

    // reverse the infixToPostfix string
    string res = "";
    for(int i = reversed_string.size() - 1; i >= 0; i--) res += reversed_string[i];
    return res;

}

int main() {


    string exp = "4^3^2";
    cout << infix_to_prefix(exp) << '\n';
    return 0;
}


