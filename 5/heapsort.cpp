//利用最小堆相关操作进行堆排序heapsort.cpp
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
typedef int ElemType;

#include "minheap.cpp"
#include "linelist.cpp"
void PrintList(List *L)
{int i,n;
 ElemType e;
 n=L->ListLength();
 for(i=0;i<n;i++)
  {cout<<setw(4)<<L->GetElem(i,&e);
   if((i+1)%10==0) cout<<endl;}
 cout<<endl;
}
void HeapSort(List *L)
{int i,n;
 ElemType e;
 n=L->ListLength();
 minheap H(n);
 for(i=0;i<n;i++)
  H.heapInsert(L->GetElem(i,&e));
 L->ClearList();i=0;
 while(!H.heapEmpty())
  L->ListInsert(i++,H.heapDelete());
 H.Destroyheap();
}
void main()
{cout<<"heapsort.cpp运行结果:\n";
 int i;
 List L;
 L.init(&L);
 for(i=0;i<10;i++)
  L.ListInsert(i,random(50));
 cout<<"原表:\n";
 PrintList(&L);
 HeapSort(&L);
 cout<<"排序后表:\n";
 PrintList(&L);
 L.DestroyList(L);
 getch();}
 

