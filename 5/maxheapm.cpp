//最大堆类的测试maxheapm.cpp
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
typedef int ElemType;
#include "maxheap.cpp"
void PrintArray(int a[],int n)
{for(int i=0;i<n;i++)
  cout<<setw(3)<<a[i];
 cout<<endl;
}
void main()
{cout<<"maxheapm.cpp运行结果:\n";
 ElemType b[HeapSIZE];
 for(int i=0;i<HeapSIZE;i++)
  b[i]=random(50);
 cout<<"输出数组b:\n";
 PrintArray(b,HeapSIZE);
 maxheap H(HeapSIZE),H1(HeapSIZE);
 for(int i=0;i<HeapSIZE;i++)
  H.heapInsert(b[i]);
 cout<<"输出当前堆H的堆顶元素:\n";
 cout<<setw(3)<<H.GetTop()<<endl;
 cout<<"输出插入后数组b:\n";
 PrintArray(b,HeapSIZE);
 cout<<"输出逐个删除的H堆中元素:\n";
 while(!H.heapEmpty())
  cout<<setw(3)<<H.heapDelete();
 cout<<endl;
 for(int i=0;i<HeapSIZE;i++)
  H1.heapInsert(random(80));
 cout<<"输出当前堆H1的堆顶元素:\n";
 cout<<setw(3)<<H1.GetTop()<<endl;
 cout<<"输出逐个删除的H1堆中元素:\n";
 while(!H1.heapEmpty())
  cout<<setw(3)<<H1.heapDelete();
 cout<<endl;
 H.Destroyheap();H1.Destroyheap();
 getch();}


