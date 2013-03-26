//顺序循环队列的类定义queue2.h
//最大队列长度
#define QueueSize 10
typedef int datatype;
class cirqueue{
 private:
//队列头指针,若队列不空则指向队列头元素
  int front;
//队列尾指针,若队列不空则指向队列尾元素的下一个位置
  int rear;
  int count;
//初始化的动态分配存储空间首地址
  datatype *data;
 public:
//构造函数
 cirqueue();
//析构函数
 ~cirqueue(){delete []data;}
// 判断队空
 int queueempty();
// 判断队满
 int queuefull();
// 入队(队列的插入)
 void enqueue(datatype);
// 出队(队列的删除)
 datatype dequeue();
// 取队列的头元素
 datatype queuefront();
//求队列的长度(即队列的元素个数)
 int QueueLength();
};

