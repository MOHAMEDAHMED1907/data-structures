#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

class minBinaryHeap {
private:
    int * array{};
    int capacity{1000};
    int count{};
public:
    minBinaryHeap ()
    {
        array = new int[capacity];
        count = 0;
    }
    
    int left(int node_P)
    {
        int pos = (2 * node_P) + 1;
        return pos > count ? -1 : pos;
    }
    int right(int node_P)
    {
        int pos = (2 * node_P) + 2;
        return pos > count ? -1 : pos;
    }
    int parent (int node_P)
    {
        int pos = (node_P - 1 ) / 2;
        return node_P == 0 ? -1 : pos;
    }
    bool empty()
    {
        return count == 0;
    }
    int top()
    {
        assert(!empty());
        return array[0];
    }

    // insertion 
    void heapify_Up(int node_P) {
        int parent_P = parent(node_P);
        if (node_P == 0 || array[node_P] > array[parent_P]) return;

        // then heapify to up 
        swap(array[node_P], array[parent_P]);
        
        // check with the above parent again
        heapify_Up(parent_P);
    }
    void push(int val)
    {
        assert(count + 1 <= capacity);
        array[count++] = val;
        // fix the properties
        heapify_Up(count-1);
    }
    // Deletion
    void heapify_down(int min_index = 0) {
        int min_CH = left(min_index);
        int right_CH = right(min_index);
        if (min_CH == -1) return;
        // I assumed the left is the smaller now compare with right
        if (right_CH != -1 && array[right_CH] < array[min_CH])
            min_CH = right_CH;
        if (array[min_index] > array[min_CH])
        {
            swap(array[min_index], array[min_CH]);
                heapify_down(min_CH);
        }
    }
    void pop()
    {
        assert(!empty());
        array[0] = array[--count];
        heapify_down();

    }
    ~minBinaryHeap() {
        delete[] array;
        array = nullptr;
    }

};

int main()
{
    minBinaryHeap  Bh;
    Bh.push(21);
    Bh.push(6);
    Bh.push(4);
    Bh.push(14);
    Bh.push(5);

    cout << Bh.top()<<endl;
    Bh.pop();
}