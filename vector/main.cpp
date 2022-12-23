#include <iostream>
#include <algorithm>
#include "MyVector.h"
using namespace std;

int main()
{

    MyVector ve(5);
    for(int v=0;v<5;v++)
        ve.setEl(v,v);

    cout<<"\n size: "<<ve.getSize()<<endl;
    //ve.push_back_VE(10);
    //ve.right_rotate();
   // ve.left_rotate();
   ve.right_rotation(8);

   // cout<<ve.deleteEl(4);

    //cout<<ve.findEl(2);
        cout<<"\n size: "<<ve.getSize()<<endl;

    for(int v=0;v<ve.getSize();v++)
        cout<<ve.getEl(v)<<" ";
    /*

    vector <int> ve(5,2);
    vector <int> ve2;

    ve.insert(ve.begin(),10);
    ve.insert(ve.begin()+1,20);
    ve.insert(ve.begin()+2,400);
    ve.emplace(ve.begin(),15);
    auto iter=ve.begin();
    // vector <int>::iterator iter=ve.begin();
    for (iter;iter<ve.end();iter++)
        cout<<*iter<<" ";

        cout<<ve2.empty()<<" ";
    vector <double>sd={2.85,2.3,15.3,14.10,22.2,15.1,14.4,13.7};
            for (auto it:sd)
    cout<<"before edit "<<it<<endl;

    //sort(sd.begin(),sd.end());
    reverse(sd.begin(),sd.end());
      cout<<endl;
    for (auto it:sd)
        cout<<" reversed "<<it<<endl;

    auto mn= min_element(sd.begin(),sd.end());
    auto mx= max_element(sd.begin(),sd.end());
    auto pairEl = minmax_element(sd.begin(),sd.end());
    cout<<" min "<<*mn<<endl;
    cout<<" max "<<*mx<<endl;
    cout<<" min--max "<<*pairEl.first<<"--"<<*pairEl.second<<endl;

    int arr[]={5,4,5,6,4,8,1};
    vector<int>vectArr(7);
    copy(arr,arr+7,vectArr.begin());
    for(auto it:vectArr)
    cout<<it;
    */

}
