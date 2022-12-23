#include "MyVector.h"
#include <iostream>
#include <algorithm>
using namespace std;

MyVector::MyVector(int vectSize)
{
        if(vectSize<0)
            vectSize=1;
        vectSSize=vectSize;
        cabacity=vectSSize*2;
        arr=new int[cabacity];
}
void MyVector::setEl(int val,int index){
        arr[index]=val;

};

int  MyVector::getEl(int index){

        return arr[index];

};

void MyVector::push_back_VE(int val){
if(vectSSize==cabacity)
    {
        expandVectSize(val);
        return;
    }
    arr[vectSSize++]=val;
};

void MyVector::expandVectSize(int val)
{
    cabacity*=2;
    int *vect2=new int[cabacity];
    for(int i=0;i<cabacity;i++)
        vect2[i]=arr[i];
    vect2[vectSSize++]=val;
    swap(arr,vect2);
    delete [] vect2;

}

int MyVector::getSize()
{
    return vectSSize;
}

void MyVector::right_rotate()
{
    int roVal = arr[vectSSize-1];
    for (int i=1;i<vectSSize;i++)
    {
        arr[vectSSize-i]=arr[vectSSize-(i+1)];
    }
    arr[0]=roVal;
}
void MyVector::left_rotate()
{
    int roVal = arr[0];

    for (int i=0;i<vectSSize-1;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[vectSSize-1]=roVal;
}

void MyVector::right_rotation(int n)
{
   n%=vectSSize;
   while(n--)
       MyVector::right_rotate();

}
int MyVector::deleteEl(int idx)
{
    if (idx<0||idx>=vectSSize) return -1;
        int old = arr[idx];
      for (int i=idx;i<vectSSize-1;i++)
        {
            arr[i]=arr[i+1];
        }
        vectSSize--;
        return old;
}
int MyVector::findEl(int val)
{
  for (int i=0;i<vectSSize;i++)
  {
      if (arr[i]==val){
            if (i!=0)
        swap(arr[i],arr[i-1]);
        return i-1;
      }
  }
  return -1;
}

MyVector::~MyVector()
{

        delete [] arr;
        arr=nullptr;
}
