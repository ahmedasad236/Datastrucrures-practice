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

int main() {

    CircularQueue q(6);
    q.enqueue(2);
    q.enqueue(8);
    q.enqueue(3);
    q.enqueue(7);

    q.display();

    q.dequeue();
    q.dequeue();

    q.enqueue(8);
    q.enqueue(396);
    q.enqueue(8);
    q.enqueue(15);

    q.display();

    

    return 0;
}
