#include <iostream>

#include "sLinkedList.cpp"
using namespace std;

class Queue {
private:
	int addedElements { };
	LinkedList li;
public:

	void enqueue(int val) {
		li.insert_end(val);
	}
	bool isEmpty ()
	{
		return li.listSize()==0;
	}
	void dequeue() {
		li.deleteFront();
	}
	void display() {
		li.printListUsingFor();
	}

}
;
int main() {

	Queue myQ;
	myQ.enqueue(10);
	myQ.enqueue(80);
	myQ.enqueue(11);
	myQ.enqueue(22);;

	myQ.dequeue();
	myQ.dequeue();
	myQ.dequeue();

	myQ.display();

	cout<<" is EMpty: "<<myQ.isEmpty();
	return 0;
}
