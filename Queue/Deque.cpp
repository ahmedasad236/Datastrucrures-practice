struct NodeDouble {
    int data { };
    NodeDouble* next { };
    NodeDouble* prev { };	 // Previous node!

    NodeDouble(int data) : data(data) {}
    void set(NodeDouble* next, NodeDouble* prev) {
        this->next = next;
        this->prev = prev;
    }

    ~NodeDouble() {
        cout << "Destroy value: " << data << " at address " << this << "\n";
    }
};

class DoubleLinkedList {
private:
    NodeDouble *head { };
    NodeDouble *tail { };
    int length = 0;
public:

    void print() {
        for (NodeDouble* cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }

    // These 2 simple functions just to not forget changing the vector and length
    void delete_node(NodeDouble* node) {
        --length;
        delete node;
    }

    void add_node(NodeDouble* node) {
        ++length;
    }

    void link(NodeDouble* first, NodeDouble* second) {
        if(first)
            first->next = second;
        if(second)
            second->prev = first;
    }

    void insert_end(int value) {
        NodeDouble* item = new NodeDouble(value);
        add_node(item);

        if (!head)
            head = tail = item;
        else {
            link(tail, item);
            tail = item;
        }
    }

    void insert_front(int value) {
        NodeDouble* item = new NodeDouble(value);
        add_node(item);

        if (!head)
            head = tail = item;
        else {
            link(item, head);
            head = item;
        }
    }

    int delete_front() {
        if(!head) return -1e9;
        int val = head->data;
//        cout <<"deleted node: " << val << '\n';
        NodeDouble* newHead = head->next;
        delete head;
        length--;

        if(!newHead) {
            head = tail = nullptr;
            return val;
        }
        
        newHead->prev = nullptr;
        head = newHead;
        return val;
    }

    int delete_end() {
        if(!head) return -1e9;

        int val = tail->data;
        NodeDouble* newTail = tail->prev;
        tail->prev->next = nullptr;
        delete tail;
        tail = newTail;
        length--;
        if(!length) head = nullptr;
        return val;
    }
};

class Deque {

private:
    DoubleLinkedList list;
public:
    void enqueue_front(int val) {
        list.insert_front(val);
    }

    void enqueue_rear(int val) {
        list.insert_end(val);
    }

    int dequeue_front() {
      return list.delete_front();
    }

    int dequeue_rear() {
        return list.delete_end();
    }

    void display() {
        list.print();
    }

};

int main() {

    Deque dq;
    dq.enqueue_front(3);
    dq.enqueue_front(2);
    dq.enqueue_rear(4);
    dq.enqueue_front(1);
    dq.display();

    cout << dq.dequeue_rear() << "\n";
    dq.display();
    cout << dq.dequeue_front() << "\n";
    dq.display();
    cout << dq.dequeue_rear() << "\n";
    cout << dq.dequeue_front() << "\n";

    dq.enqueue_front(7);
    dq.display();



    return 0;
}