#include <iostream>
#include <cassert>
#include <climits>
#include <cmath>
#include <algorithm>

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





string remove_expression_brackets(string exp) {
    Stack stk;
    char nearOperator = NULL;
    for(int i = 0, n = exp.size(); i < n; i++) {
        if(exp[i] != ')') stk.push((int)exp[i]);
        else {
            string currExp = "";
            while (!stk.isEmpty() && stk.peek() != '(') currExp += (char)stk.pop();
            stk.pop();
            reverse(currExp.begin(), currExp.end());
            char currSign = stk.peek();
            if(!isdigit(currExp[0])) {
                if(currSign == currExp[0]) stk.push( '+');
                else stk.push(currExp[0]);
            } else stk.push(currExp[0]);

            for(int i = 1; i < currExp.size(); i++)
                if(isdigit(currExp[i])) stk.push(currExp[i]);
                else {
                    if(currExp[i] == currSign) stk.push('+');
                    else stk.push('-');
                }
        }
    }
    string res = "";
    while(!stk.isEmpty()) res += stk.pop();
    reverse(res.begin(), res.end());
    return res;

}

int main() {

    string exp = "";

    exp = "1+2-3-4+5-6-7+8";
    cout << remove_expression_brackets(exp) << '\n';
    cout << "*****************************************************\n";

    exp = "9-(2+3)";
    cout << remove_expression_brackets(exp) << '\n';
    cout << "*****************************************************\n";

    exp = "9-(2-3)";
    cout << remove_expression_brackets(exp) << '\n';
    cout << "*****************************************************\n";

    exp = "9+(2-3)";
    cout << remove_expression_brackets(exp) << '\n';
    cout << "*****************************************************\n";

    exp = "1-(2-3-(4+5))-6-(7-8)";
    cout << remove_expression_brackets(exp) << '\n';
    cout << "*****************************************************\n";

    exp = "1-(2-3-(4+5)+6-7)";
    cout << remove_expression_brackets(exp) << '\n';
    cout << "*****************************************************\n";

    exp = "1-(2-3-(4+5-(6-7)))";
    cout << remove_expression_brackets(exp) << '\n';
    cout << "*****************************************************\n";

    exp = "1-(2-3-(4+5)-2+(1-3))-6-(7-8)";
    cout << remove_expression_brackets(exp) << '\n';
    cout << "*****************************************************\n";

    return 0;
}

