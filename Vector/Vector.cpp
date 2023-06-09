#include <iostream>
#include <cassert>
using namespace std;

class Vector {
private:
	int *arr { nullptr };
	int size { 0 };			// user size
	int capacity { };		// actual size

	void expand_capacity() {
		// Double the actual array size
		capacity *= 2;
		cout << "Expand capacity to "
				<< capacity << "\n";
		int *arr2 = new int[capacity] { };
		for (int i = 0; i < size; ++i)
			arr2[i] = arr[i];	// copy data

		swap(arr, arr2);
		delete[] arr2;
	}

public:


	Vector(int size) :
			size(size) {
		if (size < 0)
			size = 1;
		capacity = size + 10;
		// The actual size array will
		// be bigger than needed
		arr = new int[capacity] { };
	}

	~Vector() {
		delete[] arr;
		arr = nullptr;
	}

	int get_size() {
		return size;
	}

	int get(int idx) {
		assert(0 <= idx && idx < size);
		return arr[idx];
	}

	void set(int idx, int val) {
		assert(0 <= idx && idx < size);
		arr[idx] = val;
	}

	void print() {
		for (int i = 0; i < size; ++i)
			cout << arr[i] << " ";
		cout << "\n";
	}

	int find(int value) {
		for (int i = 0; i < size; ++i)
			if (arr[i] == value)
				return i;
		return -1;	// -1 for NOT found
	}

	int get_front() {
		return arr[0];
	}

	int get_back() {
		return arr[size - 1];
	}

	void push_back(int value) {
		// we can't add any more
		if (size == capacity)
			expand_capacity();
		arr[size++] = value;
	}

	void rotateRight() {
		
		int lastElement = arr[size - 1];
		for(int i = size - 1; i >= 1; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = lastElement;
	}

	void rotateRightMultipleOfTimes(int times) {
		if(times <= 0) return;

		int* arr2 = new int[size];
		int j = 0;
		for(int i = size - times; i < size; i++, j++)
			arr2[j] = arr[i];
		for(int i = 0; i < size - times; i++)
			arr2[j++] = arr[i];
		
		swap(arr, arr2);
		delete [] arr2;
	}

	void rotateLeft() {
		int firtsElement = arr[0];
		for(int i = 0; i < size - 1; i++)
		 	arr[i] = arr[i + 1];
		
		arr[size - 1] = firtsElement;
	}

	int pop(int idx) {
		if(size == 0) {
			cout << "Already empty\n";
			return -1e9;
		} 

		if(idx >= size || idx < 0) {
			cout << "Invalid Index\n";
			return -1e9;
		}

		int deletedElement = arr[idx];
		if(idx == size - 1)  {
			size--;

			return deletedElement;
		}

		for(int i = idx; i < size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
		return deletedElement;
	}
};

int main() {

	int n = 2;
	Vector v(n);
	for (int i = 0; i < n; ++i)
		v.set(i, i);

	for (int i = 0; i < 15; ++i)
		v.push_back(i + 10);

	v.print();	
	v.rotateRightMultipleOfTimes(5);
	v.print();

	return 0;
}
