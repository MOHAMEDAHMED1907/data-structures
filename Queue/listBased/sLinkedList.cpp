#include <iostream>
#include <assert.h>
#include <cmath>
using namespace std;

struct Node {

int value{};
Node* next{};

Node (int value)
{
    this->value=value;
}

};
class LinkedList {

private:
    Node *head ={};
    Node *tail ={};
    int length=0;

        void printUsingRec1(Node*start)
        {
            if(!start) {cout<<endl; return;}
                cout<<start->value<<" ";
                printUsingRec1(start->next);
        }

        void printUsingRec2(Node*start)
        {
            if(!start) {cout<<endl; return;}
                printUsingRec2(start->next);
                cout<<start->value<<" ";
        }

public:
    void insertFront (int val)
    {
        // O(1) time & memory
     Node * newNode = new Node(val);
     newNode->next = head; // assign the address of the old first list to the next NewNode property
     head=newNode; // then make the hea points to the new node
     length++;
     if (length==1)
     tail = newNode;
    }
    void insert_end(int val)
    {

        // create node with value
         Node *node=new Node(val);

        // check if this is the firs insertion
        if (!head)
            head = tail = node;

        else
        {
            // make the previous node->Next  which is now tail->next equal the newNode address
            tail->next = node;
            // then make the tail points to the last node which is the new Node
            tail = node;
        }
        // always after opertion the tail->next = null and this make a sence
            length++;
         tail->next = nullptr;
    }
void printListUsingWhile ()
    {
        Node * tempNode=head;
        while (tempNode)
        {
            cout<<tempNode->value<<" ";
            tempNode=tempNode->next;
        }
        cout <<endl;
    }
void printListUsingFor()
{
    for (Node * tempNode=head ;tempNode;tempNode=tempNode->next)
        cout<<tempNode->value<<" ";
        cout<<endl;
}
void deleteFront () // O(1) time O(1) memory
{
    Node * nextHead = head->next;
    delete head;
    length--;
    head = nextHead;

    if (length==0)
    head = tail = {};
}
void deleteEnd () // O(1) time O(1) memory
{
    Node * beforeTail= {};
   for (Node *node=head;node;node=node->next)
   {
       if (node->next ==tail)
       {
           beforeTail = node;
           break;
       }
   }

    delete tail;
    length--;

    tail = beforeTail;
    tail->next = nullptr;

    if (length==0)
    head = tail = {};
}

//using recursion ////
// we nee to overLap the func so we can pass dataMember by default

void printUsingRecursion (){

printUsingRec1(head);
cout<<"descending :-";
printUsingRec2(head);
}

int  search (int val)
    {
      if (head->value==val)
        return 0;

     else if (tail->value == val)
        return length-1;


        int cnt=0;
        for (Node *start=head; start ; start=start->next,cnt++)
            {
                if (start->value== val)
                    return cnt;
            }
           return -1;
    }

int  imporvedSearch (int val)
    {
        if (head->value == val)
         return 0;

        int cnt=1;

        for (Node *start=head; start ; start=start->next, cnt++)
            {
                if (start->next->value == val)
                {
                        int  temp = start->value;
                        start->value = start->next->value;
                        start->next->value = temp;
                       // swap(start->value,start->next->value);

                    return cnt;
                }
            }


           return -1;
    }

Node* get_NodeByPos (int pos)
    {
        if (pos>length || pos<0)
            return nullptr;

        int counter = 0;
        for (Node *start=head; start ; start=start->next)
            {
                if (counter++ == pos)
                    return start;
            }
    }

void cleanLinkedList ()
{
      while (head)
        {
            Node * currentNode = head->next;
            delete head;
            length--;
            head = currentNode;
        }
}
    ~LinkedList()// O(n) time O(1) memory
    { cleanLinkedList();
    }

Node * getNodeFromBack (int pos,int coun=1) // O(n) time O(1) memory
{
    if (pos>length || pos <0)
        return nullptr;

    if (pos==1) return tail;

    else if (pos==length) return head;

    int posFront= (length)-pos,cnt=1;
    Node * curr=head->next;
    while (posFront)
    {
        if (posFront == cnt)
            return curr;
        cnt++;
        posFront--;
        curr=curr->next;

    }
    return nullptr;

}

bool isSameList (LinkedList *list2)
{
  if (length!=list2->length)
        return false;

      Node * node1 = head ,*node2=list2->head;
      for (;(node1&&node2);node1=node1->next,node2=node2->next)
    {
        if (node1->value!=node2->value) return false;
    }
    if(!node1&!node2)
    return true;
}

void deleteWithKey (int value)
{
    if (value == head->value)
        {
         deleteFront();
         return;
        }

       Node *  nextAddress = nullptr;

    for (Node * curr=head; curr!=tail;curr=curr->next)
    {
        if (curr->next->value==value)
        {
            nextAddress = curr->next->next;
            delete curr->next;
            length--;
            curr->next = nextAddress;
            return;
        }
    }
    delete nextAddress;
    cout<<endl<<" this Value is not found "<<endl;
    return;
}
void swapListPairs ()
{
    int cnt=length/2;
    Node *curr = head;
    while (cnt)
    {
        swap(curr->value,curr->next->value);
        curr=curr->next->next;
        cnt--;
    }
}

void reverseList ()
{
    tail= head;
    Node * prev= head;
    head=head->next;
    while (head)
    {
        // store the the next node before we mutate
        // then we make the next of the current node points to
        // the previous node instead of the next node
        Node * nextHead = head->next;
        head->next = prev;

        // then move step
        // if you confused review this vid
        // https://www.udemy.com/course/dscpp-skills/learn/lecture/25883510#questions
        prev = head;
        head = nextHead;

    }
    head = prev;
    tail->next= nullptr;

}

void deleteEvenPositions()
{
    Node * oddPos = head;
    bool even = (length%2==0);

    while (1)
    {
        // length even ? then the last node needed will be the previous of old tail
        if (even){
                if (oddPos->next ==tail)
                {
                    tail = oddPos;
                    delete tail->next;
                        length--;
                     tail->next=nullptr;
                    break;
                }
            }
            // length odd ? then the last node needed will be the previous tail
        else
            if (oddPos== tail) break;

        Node * deleteNode = oddPos->next;

        // odd link to odd
        oddPos->next=oddPos->next->next;

        delete deleteNode;
        length--;

        // move to the next odd pos
        oddPos = oddPos->next;

    }
}

void insertThenSort (int val) // O(n) time O(1) memory
{
    if (length ==0||val <= head->value) insertFront(val);

    else if (val >= tail->value) insert_end(val);

    else {
            Node *newNode=new Node(val);
    for (Node * node = head; node; node =node->next)
    {
        if (node->next->value >= val)
        {
            Node* rightNode = node->next;
            node->next =newNode;
            newNode->next= rightNode;
            length++;
            break;
        }
    }
    }
}

void  swapHeadTail () // O(n) time O(1) memory
{
    // seperate the head and tail to the list
    Node * afterHead = head->next;
    Node * beforeTail= {};

    // loop to reach the previous node of tail
    for (Node *node=head; node;node=node->next)
        {if (node->next== tail)
        {beforeTail=node;
         break;}}

    beforeTail->next = nullptr;
    head->next = nullptr;

    // swap
    swap(head , tail);
    // then link them to the list again
     head->next = afterHead;
     beforeTail->next = tail;
}
void rotateLeft(int k) // O(n) time O(1) memory
{
     // if k == length then we need do nothing
     // so we use remainder if k = 50 && length= 5->
     // it is like k= 5,length =5 and therefore we return
     // if k= 51 & length =5 -> k = 1 , length = 5 so the modules is great to use in this state

    k %=length;
    if (k==0 || length <=1) return;
    // export the nodes to relink them after rotation
    Node * firstTailNode = head;
    Node * lasttailNode = {};
    Node * oldTail = tail;
    Node * curr = head;
    int counter =1;
    while (1)
        {
            if (counter==k)
            {
                lasttailNode = curr;
                break;
            }
            else {
                counter++;
                 curr = curr->next;
                 }
        }
   Node * newHead = lasttailNode->next;
   // relink them again
    head = newHead;
    tail->next= firstTailNode;
    tail = lasttailNode;
    tail->next = nullptr;




}


void deleteNextNode (Node* node) {
		// Delete the next of the current node
		// Handle if next is tail case
		assert(node);

		Node* to_delete = node->next;
		bool is_tail = to_delete == tail;

		// node->next in middle to delete
		node->next = node->next->next;

		delete to_delete;
		--length;

		if (is_tail)
			tail = node;
	}


void removeDuplicates ()
{
       		if (length <= 1)
                return;
    for (Node *cur1 = head; cur1; cur1 = cur1->next) {
        for (Node *cur2 = cur1->next, *prv = cur1; cur2;) {
            if (cur1->value==cur2->value)
                {
                        deleteNextNode(prv);
                        cur2=prv->next;
                } else prv=cur2, cur2 = cur2->next;
            }

    }

}
void removeLastOccurance (int k) // O(n) time O(1) memory
{
    if (k==tail->value)
    {
        deleteEnd();
        return;
    }

    Node * prev={};
    for (Node * node=head,*prv=head;node!=tail;prv=node,node=node->next)
    {
        if (node->value==k)
        {
            prev = prv;
        }
    }

    if (!prev)
        return;
    if (prev==head)
    {
        deleteFront();
        return;
    }
    deleteNextNode(prev);
}

void moveKeyToBack (int k) // O(n) time O(1)
{
    int ln=length;
    for (Node * node=head,*prv=head;ln>0;ln--)
    {
        if (node->value==k&&prv==node)
            {
            deleteFront();
            insert_end(k);
            node=prv =head;
            continue;
            }
        else  if (node->value==k)
         {
               deleteNextNode(prv);
               insert_end(k);
            node =prv;

         }
            prv=node;
            node=node->next;
        }
}
int maxRec(Node *start=nullptr,bool firstCall=true)
{
    if (firstCall)
    return maxRec(this->head,false);

    if (start==nullptr)
        return INT_MIN;

        return max(start->value,maxRec(start->next,false));
}
void arrangeOddEven ()
{
    if (length <=2) return;
    Node* odd=head, *even=odd->next,
    * lastOdd={},  * firstEven= even;

    int oddN=ceil(float(length)/2);
    int evenN=length/2;

    while (1)
    {
        oddN--;
        evenN--;
        if (oddN==0){
            lastOdd=odd;
            tail=even;
            tail->next=nullptr;
                break;
        }

      Node * nextOdd = odd->next->next;

      odd->next = nextOdd;
      odd=nextOdd;
      if (evenN>0){
      Node * nextEven= nextOdd->next;
      even->next = nextEven;
      even = nextEven;
      }
    }
    lastOdd->next = firstEven;
}
void insertAlternating(LinkedList &list2)
{
    if (!list2.length) return;

    if (!length){
        int cnt = list2.length;

        head = list2.head;
        tail= list2.tail;
        length = list2.length;
        return;
    }

    Node * start1 = head;
    Node * start2 = list2.head;

    Node * secondNode1 = start1->next;
    Node * secondNode2 = list2.head->next;

    int limit = min(length,list2.length);
    bool greaterList=false;


    if (length<list2.length) greaterList = true;
    int counter = 0;

    while (1)
    {
    start1->next = start2;
    start2->next = secondNode1;

    counter++;

    // we will loop to the smallest list
   if (limit==counter){

        if (greaterList) // if they aren't same length relink the the tail to the another tail
        {
        tail->next->next=secondNode2;;
        tail=list2.tail;
        tail->next=nullptr;
        }
      break;
    }

    // move start 1 &2 to next
    start1 = secondNode1;
    start2 = secondNode2;

    secondNode1 = start1->next;
    secondNode2 = start2->next;
    }
    length +=list2.length;

    list2.head = list2.tail = nullptr;
    list2.length = 0;
}

void removeRepeats () // O(N) TIME  O(1) MEMORY
{
    int avoid{};
    int cnt = 0;
    LinkedList LinList;

    for (Node * curr=head; curr;curr=curr->next)
    {
        if (!curr->next->next)
        {
        if (curr->value !=tail->value && curr->value!=avoid)
            {
                LinList.insert_end(curr->value);
                LinList.insert_end(curr->next->value);}

        else if (curr->value !=tail->value && curr->value==avoid)
          LinList.insert_end(tail->value);

            break;
        }
        if (curr->value == curr->next->value)
        { avoid = curr->value;
            continue;}

        if (curr->value != curr->next->value && curr->value!=avoid) LinList.insert_end(curr->value);

    }
    cleanLinkedList();
    head= LinList.head;
    tail= LinList.tail;
    LinList.head=LinList.tail = nullptr;
}
int listSize()
{
	return length;
}
};
