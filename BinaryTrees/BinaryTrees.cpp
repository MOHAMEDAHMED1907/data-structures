#include <iostream>
#include <vector>
#include <assert.h>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
class BinaryTree
{
private:
    int value{};
    BinaryTree* left{};
    BinaryTree* right{};

public:
    BinaryTree(int value)
    {
        this->value = value;
    }
    BinaryTree(string nodes)
    {
        BinaryTree* current = this;
        int limit = nodes.size()-1;
        for(int i=0;i<(int)nodes.size();i+=2,limit-=2)
        {
            int val = nodes[limit];

            current->value = val;
            if (limit > 0)
            {
                val = nodes[limit - 1];
                current->right = new BinaryTree(val);

                current->left = new BinaryTree({});
                current = current->left;
            }
            
        }
    }

    BinaryTree(deque<int>& pre, deque<int>& inOrder, int leftStart = 0, int rightEnd =-1) {
        if (rightEnd == -1) rightEnd= inOrder.size()-1;
        int currentRoot = pre[0]; pre.pop_front();
        for (int i = 0; i <= rightEnd; i++)
        {
            if (inOrder[i] == currentRoot) {
                if (i > leftStart)  left = new BinaryTree(pre, inOrder, leftStart , i-1);
                if (i < rightEnd)   right = new BinaryTree(pre, inOrder, i + 1, rightEnd);
            break;
            }
        }
}

    BinaryTree(queue<pair<int,bool>>& pre){

        pair <int, bool> curr = pre.front();
        pre.pop();
        value = curr.first;
            if (curr.second)
            {
                left  = new BinaryTree(pre);
                right = new BinaryTree(pre);
            }
        
    }
    void pre_Order (deque<int>&dq)
    {
        dq.push_back(this->value);
        if (left) left->pre_Order(dq);
        if (right)right->pre_Order(dq);
    }  
    void in_Order (deque<int>&dq)
    {
        if (left) left->pre_Order(dq);
        dq.push_back(this->value);
        if (right)right->pre_Order(dq);
    }
    void add(vector<int>values, string directions)
    {
        int lim = directions.size();
        assert(lim == values.size());
        BinaryTree* currentTree = this;
        for (int i = 0; i < lim; i++) {
            if (directions[i] == 'R') {
                if (!currentTree->right) {
                    currentTree->right = new BinaryTree(values[i]);
                }
                else assert(currentTree->right->value == values[i]);
                currentTree = currentTree->right;

            }
            else if (directions[i] == 'L') {
                if (!currentTree->left) {
                    currentTree->left = new BinaryTree(values[i]);
                }
                else assert(currentTree->left->value == values[i]);

                currentTree = currentTree->left;
            }
            else {
                cout << "wrong direction";
                break;
            }
        }

    }
    void print_in_order()
    {
        if (!value) return;
        if (left) left->print_in_order();
        cout << value << " ";
        if (right) right->print_in_order();
    }  
    void print_post_order()
    {
        if (left) left->print_post_order();
        if (right) right->print_post_order();
        cout << (char)value << " ";
    
    }
    
    void print_in_order_iterative()
    {
        stack <pair<BinaryTree*,bool>> Nodes;
        Nodes.push(make_pair(this, false));
        while (!Nodes.empty())
        {
            // extract node in top 
            // check if it is the a leaf ?print:push children
            BinaryTree* currentTree = Nodes.top().first;
            bool is_Node_done = Nodes.top().second;
            // remove extracted node 
            Nodes.pop();

            if (is_Node_done) cout << currentTree->value<<" ";
            else {
                if (currentTree->right) Nodes.push(make_pair(currentTree->right, false));
                    Nodes.push(make_pair(currentTree, true));
                if (currentTree->left) Nodes.push(make_pair(currentTree->left, false));
            }
        }
    }

    void print_Per_Level_Recursive(int level,bool reversed=false) {
        if (level == 0) cout << value << " ";
        else if (level)
        {
            if (reversed) {
                if (right)right->print_Per_Level_Recursive(level - 1,true);
                if (left)left->print_Per_Level_Recursive(level - 1, true);
            }
            else
            {
                if (left)left->print_Per_Level_Recursive(level - 1);
                if (right)right->print_Per_Level_Recursive(level - 1);
            }
        }
        // we've'not to check if there is left or right 
        // thanks to the height 
    }
    void iterate_Each_level_to_Recursive()
    {
        int H = height();
        for (int i = 0; i <= H; i++) cout<<"Level "<<i<<" : ",print_Per_Level_Recursive(i,((i+1)%2==0)), cout <<endl ;
    }
    void print_Per_Level() {
        queue <BinaryTree*> nodesQueue;
        nodesQueue.push(this);
        while (!nodesQueue.empty())
        {
            BinaryTree* currentNode = nodesQueue.front();
            nodesQueue.pop();
            cout << currentNode->value<<" ";
            if (currentNode->left) nodesQueue.push(currentNode->left);
            if (currentNode->right) nodesQueue.push(currentNode->right);
        }
        cout << endl;
    }
    void print_Per_Level_v2() {
        queue <BinaryTree*> nodesQueue;
        nodesQueue.push(this);
        int Level = 0;
        while (!nodesQueue.empty())
        {
            int levelNodes = nodesQueue.size();
            cout << " Level " << Level << " : ";
            while (levelNodes--) {
                BinaryTree* currentNode = nodesQueue.front();
                nodesQueue.pop();
                cout << currentNode->value << " ";
                if (currentNode->left) nodesQueue.push(currentNode->left);
                if (currentNode->right) nodesQueue.push(currentNode->right);
            }
            Level++;
            cout << endl;
        }
    }
    int maxNode()
    {
        int maxValue = value;
        if (right) {
            int rightValue = right->maxNode();
            maxValue = (maxValue < rightValue) ? rightValue : maxValue;
        }
        if (left) {
            int leftValue = left->maxNode();
            maxValue = (maxValue < leftValue) ? leftValue : maxValue;
        }
        return maxValue;
    }
    int countNodes()
    {
        int counter = 1;

        if (left) {
            counter += left->countNodes();
        }
        if (right) {
            counter += right->countNodes();
        }

        return counter;
    }
    int countLeafNodes()
    {
        int counter = !left & !right;
        if (left)  counter += left->countLeafNodes ();
        if (right) counter += right->countLeafNodes();
        return counter;
    }
    int height()
    {
        int counter = 0;
        if (left) {
            counter = max(counter, 1 + left->height());
        }
        if (right) {
            counter = max(counter, 1 + right->height());
        }
        return counter;
    }
    bool is_exist(int searchedNode)
    {
        bool found = value == searchedNode;

        if (!found && right)found = right->is_exist(searchedNode);
        if (!found && left) found = left->is_exist(searchedNode);

        return found;


    }
    bool is_Perfect_1()
    {
        return (countNodes() == pow(2, (height() + 1)) - 1);
    }
    bool is_Perfect_2(int h = -1)
    {
        h = height();
        if (!right && !left) return h == 0;
        if (right && !left || left && !right) return 0;
        return left->is_Perfect_2(h - 1) && right->is_Perfect_2(h - 1);
    }
    BinaryTree* clearTree()
    {
          // there is no need to call clearTree again 
         // right && left are trees 
        // , when terminated the destructor will call it itself 
       //       delete right->clearTree();

        if (right){
          delete right;
        right = NULL;}  
        if (left) 
        { //delete left;
          delete left;
        left = NULL;
        }
       

        return this;
    }
    void left_Boundary()
    {
        cout << value << " ";
        if (left) left->left_Boundary();
        else if (right) right->left_Boundary();
    }
    void right_Boundary() {
        cout << value << " ";
        if (right) right->right_Boundary();
        else if (left) left->right_Boundary();
    }
    bool is_compelete()
    {
        queue<BinaryTree*> nodes;
        bool allowed_more = true;
        nodes.push(this);
        while (!nodes.empty())
        {
            int size = nodes.size();
            while (size--)
            {
                BinaryTree* current = nodes.front();
                nodes.pop();
                if (!current->left|| !current->right) allowed_more = false;

                if (current->left) {
                    if (!allowed_more) return false;
                    nodes.push(current->left);
                }
                if (current->right) {
                    if (!allowed_more) return false;
                    nodes.push(current->right);
                } 

            }
        }
        return true;
    }
    void pre_Queue(queue <pair<int, bool>>& preQ) {
        
        preQ.push(make_pair(this->value,(left && right) ));
        if (left) left->pre_Queue(preQ);
        if (right)right->pre_Queue(preQ);
    }
    ~BinaryTree()
    {
        clearTree();
    }

};

int main()
{

    BinaryTree bt(7);
    bt.add({ 5,12 }, "LL");
    bt.add({ 5,14 }, "LR");
    bt.add({ 10,17 }, "RL");
    bt.add({ 10,18 }, "RR");
   // bt.add({ 10,18,15 }, "RRR");
       //bt.print_Per_Level();
      // bt.print_Per_Level_v2();
     //  bt.print_Per_Level_Recursive();
    //   bt.iterate_Each_level_to_Recursive();

  //  bt.print_in_order(); cout << endl;
    deque<int> dqPre,dqOrderd;
    bt.pre_Order(dqPre);
    bt.in_Order(dqOrderd);
    
    BinaryTree bt2(dqPre, dqOrderd);
 //   bt.print_Per_Level_v2();

    queue <pair<int, bool>>preQ;

    bt.pre_Queue(preQ);
  /*  while (!preQ.empty())
    {
        cout <<" pq "<<preQ.front().first<<" is "<< preQ.front().second<< endl;
        preQ.pop();

    }*/
   BinaryTree bt3(preQ);
  // cout <<" pq "<<preQ.front().first<<" is "<< preQ.front().second<< endl;
   bt3.print_Per_Level_v2();
    return 0;
}
