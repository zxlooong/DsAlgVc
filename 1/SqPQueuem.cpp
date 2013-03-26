// 顺序优先级队列的应用SqPQueuem.cpp
#include<iostream.h>
#include<iomanip.h>
#include "SqPQueue.cpp"
void main()
{cout<<"SqPQueuem.cpp运行结果:\n";
 SqPqueue MyQueue;
 datatype task;
 int i,m;
 cout<<"输入产生随机数的种子数m:";cin>>m;
 srand(m);
 cout<<"生成顺序优先级队列MyQueue:\n";
 for(i=0;i<MaxSize;i++)
 {task.taskNo=i+1;
  task.priority=rand()%10;
  MyQueue.InsertPQ(task);}
 cout<<"求顺序优先级队列MyQueue的长度:";
 cout<<MyQueue.PQueueSize()<<endl;
 cout<<"输出顺序优先级队列MyQueue:\n";
 cout<<"序号 任务号 优先级\n";
 i=1;
 while(!MyQueue.PQueueEmpty())
  {cout<<setw(2)<<i;
   task=MyQueue.DeQueue();
   cout<<setw(6)<<task.taskNo;
   cout<<setw(7)<<task.priority<<endl;
   i++;}
 cin.get();cin.get();}

