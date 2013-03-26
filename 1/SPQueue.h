//SPQueue.h
//考虑优先级相同元素的先进先出
//问题的顺序优先级队列类定义
#include<fstream.h>
#define MaxSize 6
typedef struct Datatype
{int taskNo;
 int priority;
}datatype;
class SqPqueue
{private:
  datatype data[MaxSize];
  int count;
 public:
//构造函数
 SqPqueue(){count=0;}
//析构函数
 ~SqPqueue(){}
//清空队列
 void ClearPq(){count=0;}
// 判断队空
 int PQueueEmpty();
// 判断队满
 int PQueuefull();
//重载关系运算符小于<
 friend int operator <(datatype &,datatype &); 
// 队列的插入
 void InsertPQ(datatype);
// 队列的删除
 datatype DeQueue();
// 取队列的头元素
 datatype PQueuefront();
//求队列的元素个数
 int PQueueSize();
};

 