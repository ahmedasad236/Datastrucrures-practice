#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Stack {
private:
    int size { };
    int top { };
    int* array { };
public:
    Stack(int size = 20) :
            size(size), top(size) {
        array = new int[size];
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


void next_greater_num(vector<int>& arr) {
    int n = arr.size();
    vector<int> nextGreater(n);

    Stack stk(n);

    for (int i = 0; i < n; i++) {

        while(!stk.isEmpty() && arr[i] > arr[stk.peek()])
            nextGreater[stk.pop()] = arr[i];
        stk.push(i);
    }
    while(!stk.isEmpty()) nextGreater[stk.pop()] = -1;

    for(auto el : nextGreater) cout << el << ' ';
    cout << '\n';

}


int main() {

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    next_greater_num(nums);
   
    return 0;
}