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

vector<int> asteroid_collision(vector<int>& arr) {
    int n = arr.size();
    Stack stk(n);
    for(int i = 0; i < n; i++) {

        if(arr[i] > 0) stk.push(arr[i]);
        else {
            int currPeek = stk.isEmpty() ? 0 :  stk.peek();
            while (!stk.isEmpty() && arr[i] < 0 && stk.peek() > 0) {
                if (stk.peek() <= -arr[i]) {
                    currPeek = stk.peek();
                    stk.pop();
                } else break;
            }
            currPeek = stk.isEmpty() ? currPeek : stk.peek();
            if(currPeek < -arr[i]) stk.push(arr[i]);
        }
    }

    n = stk.length();
    int i = n - 1;
    vector<int> res(n);
    while(!stk.isEmpty()) {
        res[i--] = stk.pop();
    }

    return res;
}


int main() {
 
    cout << "******************* Asteroid Collision *******************************************\n";
    int n;
    cout << "n: ";
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> res =  asteroid_collision(arr);
    cout << "Result: [";
    for(int i = 0; i < res.size(); i++) cout << res[i] << ' ';
    cout << "]\n";
  

  return 0;
}