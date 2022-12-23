#ifndef MYVECTOR_H
#define MYVECTOR_H

class MyVector
{

private:
    int *arr=nullptr;
    int vectSSize=0;
    int cabacity=0;
    void expandVectSize(int );
public:
    MyVector(int );
    void setEl(int ,int );
    int getEl(int );
    int getSize();
    void push_back_VE(int );
    void right_rotate();
    void right_rotation(int );
    void left_rotate();
    int deleteEl(int);
    int findEl(int);
 /*   void push_back_old(int val)
    {

        this way takes too much steps
        and therefore much time
        the solution for this problem is by using
        a trick we will create the array with a double of the wanted size
        for reducing for loop use unless
        if the array was filled we will need to use the for loop to
        store the old data ,add the new value and double the size
        again
        ----------------------------------

        int *NArr=new int[vectSSize+1];
        for(int i=0;i<vectSSize;i++)
        NArr[i]=arr[i];
        NArr[vectSSize++]=val;
        swap(arr,NArr);
            delete []NArr;



    }
    */

    ~MyVector();
};

#endif // MYVECTOR_H
