#include <iostream>
using namespace std;

class Queue {
private:
	int *arr;
	int queueSize { };
	int addedElements { };
	int front = 0, rear = -1;
public:

	/////////// helper functions

	bool isFull() {
		return queueSize == addedElements;
	}
	bool isEmpty() {
		return queueSize == 0;
	}

	int nextPos(int pos) {
		if (++pos == queueSize)
			return 0;
		return pos;
	}
	///////////////////////////

	Queue(int Size) {
		queueSize = Size;
		arr = new int[queueSize];
	}

	void enqueue(int val) {
		try {
			if (isFull())
				throw overflow_error(" Queue is full !!");
			arr[nextPos(rear)] = val;
			addedElements++;
			rear++;
		} catch (exception &e) {
			cout << e.what();
		}

	}
	int dequeue() {
		try {
			if (isEmpty())
				throw underflow_error(" Queue is Empty !!");
			int value = arr[front++];
			addedElements--;
		return value;
		} catch (exception &e) {
			cout << e.what();
		}
	}
	void display() {
		int limit = addedElements, step = 0, start = front - 1;
		while (limit >= ++step)
			cout << arr[nextPos(start++)] << " ";
		cout<<endl;
	}

};
