//顺序循环队列的类定义queue1.h
#define QueueSize 10
typedef int datatype;
class cirqueue{
 private:
  int front;
  int rear;
  int count;
  datatype data[QueueSize];
 public:
//构造函数
 cirqueue();
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

