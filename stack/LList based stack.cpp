#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
using namespace std;

class Stack {
  private:

    struct Node {
        int value{};
        Node *next{};
        Node(int val) {
            value = val;
        }
    };

    Node * top { };
    int stackLength{};

  public:
    /* Stack() :
         size(size), top(-1) {
         array = new int[size];
     }

     ~Stack() {
         delete[] array;
     }*/

    void push(int value) {
        try {
            Node * newNode=new Node(value);
            if (!newNode) throw overflow_error(" Stack is Full ! \n");

            newNode->next = top;
            top = newNode;
            stackLength++;

        } catch (exception &e) {
            cout<<e.what();
        }
    }

    int pop() {
        try {
             if (isEmpty()) throw underflow_error(" Stack is Empty ! \n");
             Node * tempTop = top;
             int topValue = top->value;
             top = top->next;
             delete tempTop;
             return topValue;
        } catch (exception &e) {
            cout<<e.what();
        }
    }

    int peek() {
        try {
            if (isEmpty()) throw underflow_error(" Stack is Empty ! \n");
//            return top->value;
        } catch (exception &e) {
            cout<<e.what();
        }
    }



    int isEmpty() {
        return !top;
    }

    void display() {
        for (Node * node = top; node; node=node->next)
            cout << node->value << " ";
        cout << "\n";
    }


};

int main() {
    Stack s;
    s.push(1);

    //s.insertAtBottom();
    s.display();
    return 0;
}
