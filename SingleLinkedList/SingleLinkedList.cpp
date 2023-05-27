#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

struct Node {
    int val;
    Node* next{};

    Node(int data) : val(data) {}
    ~Node() {std::cout<< "Destruct the node: " << val << '\n';}
};

class LinkedList {
    Node* head;
    Node* tail;
    int length = 0;
    void printReverseUtility(Node* curr) {
        if(!curr) return;
        printReverseUtility(curr->next);
        std::cout << curr->val << " ";
    }
public:
    LinkedList(){
        head = tail = nullptr;
        length = 0;
    };
    void print() {
        Node* temp = head;
        while(temp != nullptr)
        {
            std::cout << temp->val << ' ';
            temp = temp->next;
        }
        std::cout << '\n';
    }

    Node* getHead() {return head;}
    void insertNode(int val) {
        Node* newNode = new Node(val);
        if(!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void insertFront(int val) {
        Node* newNode = new Node(val);
        if(!head) head = tail = newNode;
        else newNode->next = head, head = newNode;
        length++;
    }

    void deleteFront() {
        if(!head) return;
        if(head == tail) {delete head; head = tail = nullptr;}
        Node* deletedNode = head;
        head = head->next;
        delete deletedNode;
        length--;
    }

    Node* get_nth_fromBack(int n) {
        if(n < 1 || n > length) return nullptr;
        std::vector<Node*> arr;
        Node* curr = head;
        while(curr) {
            arr.push_back(curr);
            curr = curr->next;
        }
        return arr[length - n];
    }

    Node* get_nth(int n) {
        int i = 1;
        Node* curr = head;
        while(i < n && curr) {
            i++;
            curr = curr->next;
        }
        return curr;
    }

    bool isSame(LinkedList& other) {
        if(other.length != length) return false;
        Node* l1 = head,*l2 = other.head;

        while (l1 && l2){
            if(l1->val != l2->val)
                return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return !l1 && !l2;

    }

    int search(int val) {
        int i = 0;
        Node* curr = head;
        while(curr) {
            if(curr->val == val)
                return i;
            i++;
            curr = curr->next;
        }
        return -1;
    }

    bool verify() {
        if(length == 0) {
            return tail == head && head == nullptr;
        }
        else if(length == 1) {
            return tail == head;
        }
        int count = 0;
        Node* curr = head;
        while (curr) curr = curr->next, count++;
        return  count == length;

    }

    std::string toString() {
        if(length == 0) return "";
        std::ostringstream oss;
        for(Node* curr = head; curr; curr = curr->next) {
            oss << curr->val;
            if(curr->next) oss <<" ";
        }
        return  oss.str();
    }

    void delete_node_with_key(int val) {
        if(!head) return;
        if(val == head->val) deleteFront();
        Node* curr = head, *prev= nullptr;
        while(curr) {
            if(curr->val == val) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void reverse() {
        if(length <= 1) return;

        Node* prev = nullptr, *curr = head, *newTail = head;
        while (curr) {
            
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        tail = newTail;
    }

    void rotateLeft() {
        Node* beforeTail = get_nth(length - 1);
        tail->next = head;
        head = tail;
        tail = beforeTail;
        tail->next = nullptr;
    }

    void arrangeOddEvenNodes() {
        if(length <= 2) return;

        Node* firstOdd = head, *firstEven = head->next, *curr = head->next->next;
        Node* currOdd = head, *currEven = head->next;
        int cnt = 3;
        while(curr) {
            if(cnt & 1) {
                currOdd->next = curr;
                currOdd = curr;
            } else {
                currEven->next = curr;
                currEven = curr;
            }
            curr = curr->next;
            cnt++;
        }
        head = firstOdd;
        currOdd->next = firstEven;
        tail = currEven;
        tail->next = nullptr;


    }
    void delete_even_positions() {
        if(length < 2) return;

        Node* curr = head->next, *prev = head;
        while(curr) {
            Node* nextOdd = curr->next;
            if(curr == tail) {
                delete tail;
                tail = prev;
                tail->next = nullptr;
                return;
            } else {
                prev->next = nextOdd;
                delete curr;
            }
            length--;
            prev = nextOdd;
            curr = nextOdd->next;
        }
    }

    void insertToBeSorted(int val) {
        if(val <= head->val) insertFront(val);
        Node *curr = head, *prev = nullptr;

        while (curr && curr->val <= val)
             prev = curr, curr = curr->next;
        Node* newNode = new Node(val);
        newNode->next = curr;
        prev->next = newNode;
        length++;
    }

    void addHugeNumber(LinkedList& l, LinkedList& sum) {
;
        Node* curr1 = this->head, *curr2 = l.head;
        int carry = 0;
        while (curr1 && curr2) {
            int res = curr1->val + curr2->val + carry;
            //std::cout << "curr add: " << res << "\n";
            sum.insertNode(res%10);
            carry = res / 10;
            curr2 = curr2->next;
            curr1 = curr1->next;
        }

        while(curr1) {
            int res = curr1->val + carry;
            carry = res / 10;
            sum.insertNode(res % 10);
            curr1 = curr1->next;
        }

        while(curr2) {
            int res = curr2->val + carry;
            carry = res / 10;
            sum.insertNode(res % 10);
            curr2 = curr2->next;
        }

        if(carry) sum.insertNode(carry);

    }

    void printReverse() {
        printReverseUtility(this->head);
        std::cout << "\n";
    }

    ~LinkedList() {
        Node* temp;
        while(head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    LinkedList(const LinkedList&) = delete;
    LinkedList &operator=(const LinkedList& another) = delete;

};

void printStack(std::stack<char> st) {
    if(st.empty()) return;
    char c = st.top();
    st.pop();
    printStack(st);
    std::cout << c;
}

void solve(std::string& s) {
    std::stack<char> st;
    for(auto c : s) {
        if(st.empty() || st.top() != c) st.push(c);
        else st.pop();
    }
    printStack(st);
}

int main() {
    LinkedList l1, l2, sum;

    l1.insertFront(9);
    l1.insertFront(8);
    l1.insertFront(7);
    l1.insertFront(5);
    l1.insertFront(4);
    l1.insertFront(6);
    l1.insertFront(7);
    l1.insertFront(8);


    l2.insertFront(5);
    l2.insertFront(6);
    l2.insertFront(9);

    l1.addHugeNumber(l2, sum);

    sum.printReverse();


    return 0;
}
