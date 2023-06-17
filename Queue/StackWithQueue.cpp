#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class CircularQueue {
private:
    int front;
    int rear;
    int added_elements;
    int size;
    int* arr;

    int next(int pos) {
        return (pos + 1) % size;
    }
public:
    CircularQueue(int size = 15) : size(size), front(0), rear(0), added_elements(0) {
        arr = new int[size];
    }

    bool isEmpty() {
        return added_elements == 0;
    }

    int length() {
        return added_elements;
    }

    bool isFull() {
        return added_elements == size;
    }



    void enqueue(int val) {
        assert(!isFull());
        arr[rear] = val;
        rear = next(rear);
        added_elements++;
    }

    int dequeue() {
        assert(!isEmpty());
        int val = arr[front];
        added_elements--;
        front = next(front);
        return val;
    }

    int top() {
        assert(!isEmpty());
        return arr[front];
    }

    int back() {
        assert(!isEmpty());
        return arr[(rear - 1 + size) % size];
    }

    void display() {
        cout << "Front " << front << " - rear " << rear << "\t";
        if(isFull()) cout << "Full";
        else if(isEmpty()) {
            cout << "Empty\n\n";
        }
        cout << "\n";
        for(int curr = front, step = 0; step < added_elements; ++step, curr = next(curr))
            cout << arr[curr] << ' ';
        cout << "\n\n";
    }

    ~CircularQueue() {
        delete []arr;
    }
};

class Stack {
private:
    int added_elements;
    CircularQueue q;
public:
    Stack(int size = 10) : q(10) {}

    void push(int val) {
        q.enqueue(val);
        added_elements++;

    }

    // Time complexity of pop operation is O(n)
    int pop() {
        added_elements--;
        CircularQueue q2(q.length());
        int val = -1e9;

        while(q.length() > 1) {
            q2.enqueue(q.dequeue());
        }

        val = q.dequeue();
        while(!q2.isEmpty()) q.enqueue(q2.dequeue());
        return val;
    }

    bool isEmpty() {
        return q.isEmpty();
    }


};

int main() {

	
   Stack stk(4);
   for(int i = 1; i <= 4; i++) stk.push(i);
   while(!stk.isEmpty()) cout << stk.pop() << " ";
   cout << '\n';
    return 0;
}

