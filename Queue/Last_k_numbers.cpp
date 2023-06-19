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


class Last_k_numbers_sum_stream {
private:
    CircularQueue q;
    int k;
    int curr_sum;
public:
    Last_k_numbers_sum_stream(int k) : k(k), q(k), curr_sum(0) {}
    int next(int new_num) {
        curr_sum += new_num;
        if(q.length() == k) {
            curr_sum -= q.dequeue();
        }
        q.enqueue(new_num);
        return curr_sum;
    }
};

int main() {

    Last_k_numbers_sum_stream processor(4);
    int num;
    while(cin >> num) {
        cout << processor.next(num) << "\n";
    }

    return 0;
}