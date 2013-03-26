//最小堆的实现minheap.cpp
#include "minheap.h"
minheap::minheap(int MaxSize)
{if(MaxSize<=0) {
  cerr<<"参数MaxSize非法!\n";exit(1);}
 heapArray=(ElemType *) new ElemType[MaxSize];
 if(!heapArray) exit(-1);
 maxheapSize=HeapSIZE;
 heapsize=0;
}
void minheap::Destroyheap()
{free(heapArray);}

void minheap::Clearheap()
{heapsize=0;}

bool minheap::heapEmpty()
{ if(heapsize==0) return true;
  else return false;
}
bool minheap::heapFull()
{return heapsize==maxheapSize;}
int minheap::heapLength()
{ return heapsize;}
ElemType minheap::GetTop()
{ if(heapsize==0)
   {cerr<<"堆已空!\n";exit(1);}
  return heapArray[0];
}
void minheap::FilterUp()
{int c,p;
 ElemType temp;
 c=heapsize-1;
 p=(c-1)/2;
 temp=heapArray[c];
 while(c!=0)
 {if(heapArray[p]<=temp) break;
  heapArray[c]=heapArray[p];
  c=p;
  p=(c-1)/2;}
 heapArray[c]=temp;
}
void minheap::FilterDown()
{int c,p;
 ElemType temp;
 p=0;
 c=2*p+1;
 temp=heapArray[p];
 while(c<heapsize)
 {if(c+1<heapsize&&heapArray[c+1]<heapArray[c])
   c=c+1;
  if(temp<=heapArray[c]) break;
  heapArray[p]=heapArray[c];
  p=c;
  c=2*p+1;}
 heapArray[p]=temp;
}
void minheap::heapInsert(ElemType item)
{if(heapsize==HeapSIZE)
  {cerr<<"堆已满!\n";exit(1);}
 heapArray[heapsize]=item;
 heapsize++;
 FilterUp();
}
ElemType minheap::heapDelete()
{ElemType temp;
 if(heapsize==0)
  {cerr<<"堆已空!\n";exit(1);}
 temp=heapArray[0];
 heapArray[0]=heapArray[heapsize-1];
 heapsize--;
 FilterDown();
 return(temp);}
