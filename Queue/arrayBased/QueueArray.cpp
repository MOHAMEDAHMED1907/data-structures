#include <iostream>
using namespace std;

class Queue {
private:
	int front = 0, rear = -1;
	int *arr;
	int queueSize { };
	int addedElements { };
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
	void dequeue() {
		try {
			if (isEmpty())
				throw underflow_error(" Queue is Empty !!");
			front++;
			addedElements--;
		} catch (exception &e) {
			cout << e.what();
		}
	}
	void display() {
		int limit = addedElements, step = 0, start = front - 1;
		while (limit >= ++step)
			cout << arr[nextPos(start++)] << endl;
	}

};
int main() {

	Queue myQ(10);
	myQ.enqueue(10);
	myQ.enqueue(80);
	myQ.enqueue(11);
	myQ.enqueue(22);
	myQ.enqueue(25);
	myQ.enqueue(21);
	myQ.enqueue(12);
	myQ.enqueue(29);
	myQ.enqueue(22);
	myQ.enqueue(70);
	myQ.enqueue(44);
	//myQ.enqueue(30);
	myQ.display();
	return 0;
}
