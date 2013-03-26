// 堆排序法(迭代器)duifa3.cpp
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
void main()
{cout<<"duifa3.cpp运行结果:\n";
 const int SIZE=10;int i,a[SIZE];
 for(i=0;i<SIZE;i++)
  a[i]=random(201+i)%80;
 vector<signed int>v(a,a+SIZE),v2;
 ostream_iterator<int> output(cout," ");
 cout<<"Vector v before make_heap:\n";
 copy(v.begin(),v.end(),output);
 make_heap(v.begin(),v.end());
 cout<<"\nVector v after make_heap:\n";
 copy(v.begin(),v.end(),output);
 sort_heap(v.begin(),v.end());
 cout<<"\nVector v after sort_heap:\n";
 copy(v.begin(),v.end(),output);
 // perform the heapsort with push_heap and pop_heap
 cout<<"\nArray a contains: ";
 copy(a,a+SIZE,output);
 for(i=0;i<SIZE;++i) {
   v2.push_back(a[i]);
   push_heap(v2.begin(),v2.end());
   cout<<"\nv2 after push_heap(a["<<i<<"]): ";
   copy(v2.begin(),v2.end(),output);}
 for(i=0;i<(int)v2.size();++i) {
   cout<<"\nv2 after "<<v2[0]<<" popped from heap\n";
   pop_heap(v2.begin(),v2.end()-i);
   copy(v2.begin(),v2.end(),output);}
 cout<<endl;cin.get();}
