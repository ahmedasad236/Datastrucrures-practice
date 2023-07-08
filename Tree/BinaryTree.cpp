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

    void get_max_priv(Node* node, int& mx) {
        if(!node) return;
        mx = max(mx, node->data);
        get_max_priv(node->left, mx);
        get_max_priv(node->right, mx);
    }

    int tree_height_priv(Node* node) {
        if(!node) return 0;
        int lh = tree_height_priv(node->left);
        int rh = tree_height_priv(node->right);
        return max(lh, rh) + 1;
    }

    int count_nodes_priv(Node* node) {
        if(!node) return 0;
        int l = count_nodes_priv(node->left);
        int r = count_nodes_priv(node->right);
        return l + r + 1;
    }
    int count_leaf_priv(Node* node) {
        if(!node) return 0;
        if(!node->left && !node->right) return 1;
        int l = count_leaf_priv(node->left);
        int r = count_leaf_priv(node->right);
        return l + r;
    }

    bool find_priv(Node* node, int val) {
        if(!node) return false;
        if(node->data == val) return true;

        return find_priv(node->left, val) || find_priv(node->right, val);
    }

    bool check_perfect_priv(Node* node) {
        if(!node) return true;
        if((!node->left && node->right) || (!node->right && node->left)) return false;
        return check_perfect_priv(node->left) && check_perfect_priv(node->right);
    }

    void clear_priv(Node* node) {
        if(!node) return;
        clear_priv(node->left);
        clear_priv(node->right);
        delete node;
        node = nullptr;
    }


    void traverse_left_boundry_priv(Node* node) {
        if(!node) return;
        cout << node->data << ' ';
        if(node->left) traverse_left_boundry_priv(node->left);
        else if(node->right) traverse_left_boundry_priv(node->right);
    }

    int diameter_priv(Node* node) {
        if(!node) return 0;
        int left_diam = diameter_priv(node->left);
        int right_diam = diameter_priv(node->right);
        int height = tree_height_priv(node->left) + tree_height_priv(node->right);
        return max(left_diam, max(right_diam, height));
    }
public:
    BinaryTree(int root_value) :
            root(new Node(root_value)) {
    }

    void print_inorder() {
        print_inorder_priv(root);
        cout << "\n";
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

    int get_max() {
        int mx = 0;
        get_max_priv(root, mx);
        return mx;
    }

    int height() {
        tree_height_priv(root);
    }

    int total_nodes() {
        return count_nodes_priv(root);
    }

    int leaf_nodes() {
        return count_leaf_priv(root);
    }

    bool is_exist(int val) {
        return find_priv(root, val);
    }

    bool is_perfect_rec() {
        return check_perfect_priv(root);
    }

    bool is_perfect_formula() {
        int h = this->height();
        int n = this->total_nodes();

        return n == pow(2, h + 1) - 1;
    }

    void print_inorder_iterative() {
        // Pair: node and it has been expended or not so far
        stack<pair<Node*, bool>> stk;

        // Just convert the recursion to calls
        stk.push({root, false});

        while(!stk.empty()) {
            auto top = stk.top();

            // if it has left child and has not expanded yet, push its child
            if(top.first->left && !top.second) {
                stk.top().second = true;
                stk.push({top.first->left, false});
            } else {

                // it means that it has not left child or it has processed it already
                cout << top.first->data << " ";
                stk.pop();
                if(top.first->right) stk.push({top.first->right, false});

            }
        }
        cout << '\n';
    }

    void traverse_left_boundry() {
        traverse_left_boundry_priv(root);
        cout << '\n';
    }

    void clear() {
        clear_priv(root);
    }

    int diameter() {
        return diameter_priv(root);
    }
    ~BinaryTree() {
        clear_priv(root);
    }
 };


void test4_diameter() {
    BinaryTree tree(1);

    assert(tree.diameter() == 0);

    tree.add( { 2 }, { 'L' });
    tree.add( { 3 }, { 'R' });

    assert(tree.diameter() == 2);

    tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
    tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
    tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
    tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });

    tree.add( { 2, 5, 13 }, { 'L', 'R', 'L' });
    tree.add( { 3, 6, 12 }, { 'R', 'R', 'R' });
    tree.add( { 3, 14, 15 }, { 'R', 'L', 'L' });
    tree.add( { 3, 14, 16 }, { 'R', 'L', 'R' });

    assert(tree.diameter() == 6);
}

void test5_boundry() {
    BinaryTree tree(1);

    tree.add( { 2, 4, 5, 6, 7, 9, 11 }, { 'L', 'L', 'R', 'R', 'L', 'L', 'R' });
    tree.add( { 2, 4, 5, 6, 8 }, { 'L', 'L', 'R', 'R', 'R' });
    tree.add( { 2, 4, 5, 6, 7, 10 }, { 'L', 'L', 'R', 'R', 'L', 'R' });
    tree.add( { 3 }, { 'R' });

    tree.traverse_left_boundry();
    // 1 2 4 5 6 7 9 11

    cout<<"\n";
    tree.print_inorder_iterative();
}



int main() {
    test4_diameter();
    test5_boundry();

    return 0;
}

