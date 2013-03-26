//链式队列的类定义linqueue.h
//最大队列长度
#define QueueSize 10
typedef int datatype;
//链队列的类型定义为一个结构类型：
typedef struct QueueNode{
  datatype  data;
  struct QueueNode *next;
}queuenode;
class linkqueue{
 private:
  queuenode  *front;//队列头指针.
  queuenode  *rear; //队列尾指针.
  int count;// 队列结点个数
 public:
//构造函数
 linkqueue()
 { front=rear=NULL;count=0; }
//析构函数
 ~linkqueue(){front=rear=NULL;}
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


