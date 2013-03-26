//顺序优先级队列的实现SqPQueue.cpp
#include "SqPQueue.h"
// 判断队空
int SqPqueue::PQueueEmpty() {
  return count==0;}
// 判断队满
int SqPqueue::PQueuefull(){
  return count==MaxSize;}
//重载关系运算符小于<
int operator <(datatype &b,datatype &c)
  {return b.priority<c.priority;}
//队列的插入
void SqPqueue::InsertPQ(datatype x)
{if(PQueuefull())
   {cerr<<"队列满.\n";exit(1);}
  data[count]=x;
   count++;
 }
//队列的删除
datatype SqPqueue::DeQueue()
 {if(PQueueEmpty())
   {cerr<<"队列空.\n";exit(1);}
  datatype min=data[0];
  int minindex=0;
  for(int i=0;i<count;i++)
   if(data[i]<min)
    {min=data[i];minindex=i;}
  data[minindex]=data[count-1];
  count--;
  return min;
 }
// 取队列的头元素
datatype SqPqueue::PQueuefront()
 {if(PQueueEmpty())
   {cerr<<"队列空.\n";exit(1);}
  datatype min=data[0];
  for(int i=1;i<count;i++)
   if(data[i]<min)
    min=data[i];
  return min;
 }
//求队列的元素个数
int SqPqueue::PQueueSize()
{return count;}


