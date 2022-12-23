#include <iostream>
#include <cmath>
#include "Queue.cpp"
using namespace std;

class PriorityQueue {
private:
	Queue *qu1;
	Queue * qu2;
	Queue *qu3;
	float fullSize{};
	int addedElements {};
public:
	PriorityQueue (int size)
	{
	 fullSize = size;
//	 sizePerQueue = ceil(fullSize / 3);
	 qu1 = new Queue (fullSize);
	 qu2 = new Queue (fullSize);
	 qu3 = new Queue (fullSize);
	}
	void Enqueue(int val,int priority){
		if (priority==1)
			qu1->enqueue(val);

		else if (priority==2)
			qu2->enqueue(val);

		else if (priority==3)
			qu3->enqueue(val);
	}
	int dequeue ()
	{
		if (!qu3->isEmpty())
			return qu3->dequeue();

		else if (!qu2->isEmpty())
			return qu2->dequeue();

		else if (!qu1->isEmpty())
			return qu1->dequeue();
		else return NULL;
	}

	void display ()
	{
		qu3->display();
		qu2->display();
		qu1->display();
	}
 ~PriorityQueue ()
 {
	 delete [] qu1 ;
	 delete [] qu2 ;
	 delete [] qu3 ;
 }

};
int main() {

		PriorityQueue tasks (8);
		tasks.Enqueue(1131, 1);
		tasks.Enqueue(2211, 2);

		tasks.Enqueue(1535, 1);
		tasks.Enqueue(2815, 2);
		tasks.Enqueue(3845, 3);
		tasks.Enqueue(3145, 3);

		tasks.display();
}
