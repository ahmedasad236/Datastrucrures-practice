#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Stack {
private:
    int size { };
    int top { };
    int* array { };
public:
    Stack(int size = 20) : size(size), top(size) {
        array = new int[size];
    }

    void clone_stack(const Stack& stk) {
        size = stk.size;
        top = stk.top;

        array = new int[stk.size];
        for(int i = 0; i < size; i++) array[i] = stk.array[i];
    }

    ~Stack() {
        delete[] array;
    }

    void push(int x) {
        assert(!isFull());
        array[--top] = x;
    }

    int pop() {
        assert(!isEmpty());
        return array[top++];
    }

    int peek() {
        assert(!isEmpty());
        return array[top];
    }

    int isFull() {
        return top == 0;
    }

    int isEmpty() {
        return top == size;
    }

    void display() {
        for (int i = top; i < size; i++)
            cout << array[i] << " ";
        cout << "\n";
    }

    int length() {
        return size - top;
    }

    void insert_at_bottom(int x) {
        if(isEmpty()) {
            push(x);
            return;
        }
        int currPeek = pop();
        insert_at_bottom(x);
        this->push(currPeek);
    }

    void reverse() {
        if(isEmpty()) return;
        int currPeek = pop();
        reverse();
        insert_at_bottom(currPeek);
    }

};

class Queue {

private:
    int size;
    int added_elements;
    Stack s1;
    Stack s2;

    void move(Stack& from, Stack& to) {
        while(!from.isEmpty())
            to.push(from.pop());
    }

public:
    Queue(int size = 10) : size(size), added_elements(0) {}
/*
 * Implement dequeue to be O(1) and enqueue is O(n)
 *     void enqueue(int val) {
        assert(!isFull());
        added_elements++;
	move(s1, s2);
	s1.push(value);
	move(s2, s1);
    }

    int dequeue() {
        assert(!isEmpty());
        added_elements--;
        return s1.pop();
    }

 * */

    // Implement dequeue to be O(n) and enqueue is O(1)
    void enqueue(int val) {
        assert(!isFull());
        added_elements++;
        s1.push(val);

    }

    int dequeue() {
        assert(!isEmpty());
        if(s2.isEmpty()) move(s1, s2);
        added_elements--;
        int val = s2.pop();
        return val;
    }

    bool isEmpty() {return added_elements == 0;}
    bool isFull() {return added_elements == size;}

};

int main() {

    Queue q(6);
    for(int i = 1; i <= 3; i++) q.enqueue(i);

    cout << q.dequeue() << " ";
    for(int i = 4; i <= 5; i++)
        q.enqueue(i);

    while(!q.isEmpty()) cout << q.dequeue() << " ";
    return 0;
}