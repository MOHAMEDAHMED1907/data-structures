#include <iostream>
#include <cmath>
#include <exception>
#include <vector>
using namespace std;

class Stack {
  private:
    int size { };
    int top { };
    int* array { };
  public:
    Stack(int size) :
        size(size), top(-1) {
        array = new int[size];
    }

    ~Stack() {
        delete[] array;
    }

    void push(int x) {
        try {
            if (isFull()) throw overflow_error(" Stack is Full ! \n");
            array[++top] = x;
        } catch (exception &e) {
            cout<<e.what();
        }
    }

    int pop() {
        try {
            if (isEmpty()) throw underflow_error(" Stack is Empty ! \n");
            return array[top--];
        } catch (exception &e) {
            cout<<e.what();
        }
    }

    int peek() {
        try {
            if (isEmpty()) throw underflow_error(" Stack is Empty ! \n");
            return array[top];
        } catch (exception &e) {
            cout<<e.what();
        }
    }


    int isFull() {
        return top == size - 1;
    }

    int isEmpty() {
        return top == -1;
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << array[i] << " ";
        cout << "\n";
    }

    //////////// Proplems solving

    int reverseNum (int num ) {
        Stack stk(10);
        // stack input int by int
        while (num!= 0) {

            stk.push((num%10));

            num /= 10;

        }

        // stack output int by int
        int newInt = 0;
        short pw = 0;

        while (!stk.isEmpty())
            newInt += stk.pop() * pow(10,pw++);


        return newInt;
    }
    // valid parentheses
    int openTag (int ch) {
        if (ch==']') return'[';
        else if (ch=='}') return'{';
        else if (ch==')') return'(';
        return -1;
    }
    bool allTagsClosed(string parentheses) {
        int counter=0,numChar = parentheses.size();
        Stack stk_P(numChar);
        // in each char we check if it is opening or closing
        // opening ? we will push it to the stack
        // closing ? then we will pop the stack top if == openTag(closing) and if not then we return false
        while (counter<numChar) {
            char tag = parentheses[counter++];
            if (tag=='['||tag=='{'||tag=='(') stk_P.push(tag);
            else if (stk_P.isEmpty() || stk_P.pop()!= openTag(tag)) return false;
        }
        return isEmpty();
    }
    //removDuplicates
    string removDuplicates(string wrd) {

        Stack stk(wrd.size());
        int uniqueChars=wrd.size();
        for (int i=0; i<wrd.size(); i++) {
            int chr = wrd[i];
            if (stk.isEmpty() || stk.peek()!=chr) stk.push(chr);
            else if (stk.peek()==chr) {
                stk.pop();
                uniqueChars-=2;
            }
        }

        char newWrd [uniqueChars+1];
        newWrd[uniqueChars]='\0';
        while(!stk.isEmpty()) {
            newWrd[--uniqueChars]=stk.pop();
        }
        return newWrd;
    }
    Stack  asteroidCollision(vector <int> asteroids) {
        Stack TempStk(asteroids.size());
        int counter=0;
        for (auto it:asteroids) {
            counter++;
            if (TempStk.isEmpty() || TempStk.peek()<it ) TempStk.push(it);
            else if (TempStk.peek()== it || TempStk.peek()== (it * -1)) TempStk.pop();
        }
        Stack newStack (counter);
        while(!TempStk.isEmpty()) {
            newStack.push(TempStk.pop());
        }
        return newStack;
    }
    void insertAtBottom(int x) {
        if (isEmpty())
           {push(x);
            return;}

        int curr = pop();

        insertAtBottom(x);

        push(curr);
    }
    void reverseStack () {
        if (top==0){
            return;
        }

        int curr = pop(); // 100  33 10 20
        reverseStack();
        insertAtBottom(curr);
    }
    int factorial(Stack &manual)
    {
        if(isEmpty()) return 1;

        int curr = pop();
         curr *= factorial(manual);
        manual.push(curr);
        return curr;
        }
};

int main() {
    Stack s(5);
    /*        cout<<s.removDuplicates("abbaca");*/
    //s.asteroidCollision({-2,-1,1,2      }).display();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    //s.insertAtBottom();
    s.display();
    s.reverseStack();
    s.display();
    Stack manual(4);

    cout<<s.factorial(manual)<<endl;
    manual.display();
    return 0;
}
