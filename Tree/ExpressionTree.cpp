#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

class BinaryTree {
private:
    struct Node {
        int data { };
        Node* left { };
        Node* right { };
        Node(int data) : data(data) { }
    };
    Node* root { };

    void print_inorder_priv(Node* current) {
        if (!current)
            return;
        print_inorder_priv(current->left);
        cout << current->data << " ";
        print_inorder_priv(current->right);
    }

    void print_postorder_priv(Node* current) {
        if (!current)
            return;
        print_inorder_priv(current->left);
        print_inorder_priv(current->right);
        cout <<  (current->data < 10 ? current->data : (char)current->data) << " ";

    }

    bool is_leaf(Node* node) {
        return  !node->left && !node->right;
    }


    void print_inorder_expression_priv(Node* node) {
        if(!node) return;

        if(node->left) {
            if (!is_leaf(node->left))
                cout << "(";
            print_inorder_expression_priv(node->left);
            if (!is_leaf(node->left))
                cout << ")";
        }
        cout << node->data << ' ';

        if(node->right) {
            if (!is_leaf(node->right))
                cout << "(";
            print_inorder_expression_priv(node->right);
            if (!is_leaf(node->right))
                cout << ")";
        }

    }



    void clear_priv(Node* node) {
        if(!node) return;
        clear_priv(node->left);
        clear_priv(node->right);
        delete node;
        node = nullptr;
    }

public:
    BinaryTree(int root_value) :
            root(new Node(root_value)) {
    }

    BinaryTree(string postfix) {
        stack<Node*> stk;
        for(auto c : postfix) {
            if(isdigit(c)) stk.push(new Node(c - '0'));
            else {
                Node* r = stk.top(); stk.pop();
                Node* l = stk.top(); stk.pop();

                Node* newNode = new Node(c);
                newNode->right = r, newNode->left = l;
                stk.push(newNode);
            }
        }
        root = stk.top();
    }

    void print_inorder() {
        print_inorder_priv(root);
        cout << "\n";
    }

    void print_inorder_expression() {
        print_inorder_expression_priv(root);
        cout << '\n';
    }

    void add(vector<int> values, vector<char> direction) {
        assert(values.size() == direction.size());
        Node* current = this->root;
        // iterate on the path, create all necessary nodes
        for (int i = 0; i < (int) values.size(); ++i) {
            if (direction[i] == 'L') {
                if (!current->left)
                    current->left = new Node(values[i]);
                else
                    assert(current->left->data == values[i]);
                current = current->left;
            } else {
                if (!current->right)
                    current->right = new Node(values[i]);
                else
                    assert(current->right->data == values[i]);
                current = current->right;
            }
        }
    }


    ~BinaryTree() {
        clear_priv(root);
    }
 };


void test1() {
    BinaryTree root("51+");

    cout << "infix expression: ";
    root.print_inorder_expression();
    cout << "\n";
    // infix expression: 5+1

}

void test2() {
    BinaryTree root("51+2/");

    cout << "infix expression: ";
    root.print_inorder_expression();
    cout << "\n";
    // infix expression: (5+1)/2
}

void test3() {
    BinaryTree root("23+4*");

    cout << "infix expression: ";
    root.print_inorder_expression();
    cout << "\n";
    // infix expression: (2+3)*4
}


void test4() {
    BinaryTree root("534*2^+");

    cout << "infix expression: ";
    root.print_inorder_expression();
    cout << "\n";
    // infix expression: 5+((3*4)^2)
}

int main() {
    test1();
    test2();
    test3();
    test4();

    return 0;
}

