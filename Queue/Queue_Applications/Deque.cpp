#include <iostream>
using namespace std;

class Deque {
private:
	int front = 0, rear = -1;
	int *arr;
	int dequeSize { };
	int addedElements { };
public:

	/////////// helper functions

	bool isFull() {
		return dequeSize == addedElements;
	}
	bool isEmpty() {
		return dequeSize == 0;
	}

	int nextPos(int pos) {
		if (++pos == dequeSize)
			return 0;
		return pos;
	}
	int prevPos(int pos) {
		if (--pos == -1)
			pos = dequeSize - 1;
		return pos;
	}
	///////////////////////////

	Deque(int Size) {
		dequeSize = Size;
		arr = new int[dequeSize];
	}

	void enqueue_end(int val) {
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
	void enqueue_front(int val) {
		try {
			if (isFull())
				throw overflow_error(" Queue is full !!");
			front = prevPos(front);
			arr[front] = val;
			addedElements++;

		} catch (exception &e) {
			cout << e.what();
		}

	}
	void dequeue_front() {
		try {
			if (isEmpty())
				throw underflow_error(" Queue is Empty !!");
			front++;
			addedElements--;
		} catch (exception &e) {
			cout << e.what();
		}
	}
	void dequeue_end() {

		if (isEmpty()) return;
		rear=prevPos(rear);
		addedElements--;

	}
	void display() {
		// 4
		int limit = addedElements, step = 0, start = front - 1;

		while (limit >= ++step) {
			start = nextPos(start);
			cout << arr[start] << endl;
		}
	}
};
int main() {

	Deque dq(4);
	dq.enqueue_end(10);
	dq.enqueue_end(11);
	dq.enqueue_end(12);
	dq.enqueue_end(147);
	dq.dequeue_end();
	dq.enqueue_front(17);
	dq.display();
}
