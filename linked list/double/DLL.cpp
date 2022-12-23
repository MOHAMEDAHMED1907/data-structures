#include <iostream>
#include <assert.h>
#include <cmath>
using namespace std;

struct Node {
int index  {};
int value  {};
Node* next {};
Node* prev {};

Node (int value,int index)
{
    this->value = value;
    this->index = index;
}

};
class LinkedList {

private:
    Node *head ={};
    Node *tail ={};

    Node *head2 ={};
    Node *tail2 ={};
    int FullLength=0;
    int filledLength=0;

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
    LinkedList (int length)
    {
        FullLength = length;
        // initial nodes with zero
       initNodes(FullLength);
    }

    void link2nodes (Node *N1,Node *N2)
    {
        if (N1)
            N1->next = N2;
        if (N2)
            N2->prev = N1;
    }
    void initNodes (int length)
    {
         for (int i=0;i<length;i++)
        {
            insert_end(0,i);
        }
    }
    void setValue (int val,int index)
    {
    // linkedList contains nodes ? then assign the value to the node
        nodeWithIndex(index)->value = val;
    }
   Node * nodeWithIndex (int index) // O(n) time O(1) memory
   {
       if (index>FullLength||index<0) return nullptr;
       else if (index==FullLength-1) return tail;
       else if (index==0) return head;

       Node * T_node = head;
        for (int i=0;i<FullLength;i++,T_node=T_node->next)
        {
            if (i==index)
                return T_node;
        }
   }
    void insert_end(int val,int index)
    {

        // create node with value
         Node *node=new Node(val,index);
        // check if this is the firs insertion
        if (!head)
            head = tail = node;

        else{
            link2nodes(tail,node);
            tail = node;
        tail->next = nullptr;
        }
    }
    void insertGreaterThanZero (Node * node)
    {


        // check if this is the first insertion
        if (!head2)
            head2 = tail2 = node;

        else{
            link2nodes(tail2,node);
            tail2 = node;
        tail2->next = nullptr;
        }
        filledLength++;
    }

void pushAfter(Node *before,int val)
{
    Node * middle = new Node(val);

    Node * after = before->next;
    link2nodes(before,middle);
    link2nodes(middle,after);
                length++;
}
void insertThenSort (int val) // O(n) time O(1) memory
{
    if (!length ||val <= head->value) insertFront(val);

    else if (val >= tail->value) insert_end(val);

    else {
            Node *newNode = new Node(val);
        for (Node * node = head; node; node =node->next)
        {
            if ( val <= node->value)
            {
                pushAfter(node->prev,val);
                break;
            }
        }
    }
}
void deleteFront () // O(1) time O(1) memory
{
    if (!head) return;

    Node * nextHead = head->next;
    delete head;
    length--;
    head = nextHead;

    if (head)
    head->prev = nullptr;

    else if (!length)
    head = tail = nullptr;
}
void deleteEnd () // O(n) time O(1) memory
{
    if (!head) return;
    Node * beforeTail= tail->prev;
    delete tail;
    length--;

    tail = beforeTail;
    if (tail)
    tail->next = nullptr;

    else if (!length)
     head = nullptr;
}

Node * deleteAndLink (int val)
{
    if (!length) return nullptr;

    else if (val == head->value) deleteFront();
    else if (val == tail->value) deleteEnd();
    else {
        for (Node * node=head;node;node=node->next)
        {
            if (node->value == val )
            {
                Node * before = node->prev;
                link2nodes(before,node->next);
                delete node;
                length--;
                return before;
            }
        }
    }
}
void deleteAllWithKey (int k)
{
    int cnt = length;
    while (cnt)
    {
        deleteAndLink(k);
        cnt--;
    }
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
void printPreviousListUsingFor()
{
    for (Node * tempNode=tail;tempNode;tempNode=tempNode->prev)
        cout<<tempNode->value<<" ";
        cout<<endl;
}

Node * findMiddle1 ()
{
    for(Node* T_head=head,*T_tail = tail;T_tail,T_head;T_head=T_head->next,T_tail=T_tail->prev)
    {
       // cout<<" T_hhead: "<<T_head->value<<" T_tail: "<<T_tail->value<<endl;
        if (T_head==T_tail) return T_head;
        else if (T_head->next==T_tail) return T_tail;
    }
}

Node * findMiddle2 ()
{
    for(Node* slow_p=head,*fast_p= head;fast_p;slow_p=slow_p->next)
    {
       if (!fast_p->next||!fast_p) return slow_p;
        else
            fast_p=fast_p->next->next;
    }
}
void swapK(int k)
{
    Node*n=head,*t=tail;
    while (k)
    {
        if (k==1) break;
        n=n->next;
        t=t->prev;
        k--;
    }
    swap(n,t);
}
void reverseList2()
{
    for(Node * n=head;n;n=n->prev)
    {
        swap(n->next,n->prev);
    }
    swap(head,tail);
    head->prev=tail->next=nullptr;
}
void merge2lists (LinkedList &li) // it is good when length 1 > length 2 else will stuck
{
    if(!length)
    {
        head = li.head;
        tail= li.tail;
        length = li.length;
        return;
    }
    Node * head1 = head;
    Node * head2 = li.head;


    while (head1&& head2)
    {
     if(head1->value > head2->value)
     {
         Node*prv=head1->prev;
         Node*nxtt2=head2->next;

         link2nodes(prv,head2);
         link2nodes(head2,head1);
        head2=nxtt2;
        length++;
        li.length--;
     }
     else head1=head1->next;
    }

      if (length<li.length)
        {
            tail->next=li.head;
            tail=li.tail;
            tail->next = nullptr;
        }
}
//using recursion ////
// we nee to overLap the func so we can pass dataMember by default


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


};


int main()
{
    LinkedList li (10);
    return 0;
}


