//循环双端队列顺序表示duilie.cpp
#include <iostream.h>
#include <iomanip.h>
#include <assert.h>
template <class T> class DoubleQueue
{ int end1,end2;//end1和end2为端点
  T *data;
  int size;
 public:
  DoubleQueue(int sz=10);
  ~DoubleQueue(){delete[] data;}
  void Enqueue(T item,int end);
  void Dequeue(int end);
  int IsEmpty(){return end1==end2;}
  int IsFull(){return (end1+1)%size==end2;}
  void list(int end);
};
//循环双端队列操作
template <class T>
DoubleQueue <T>::DoubleQueue(int sz):
  end1(0),end2(0),size(sz){
    data=new T[size];assert(data!=0);
}
//循环双端队列插入新元素操作
template <class T>
void DoubleQueue <T>::Enqueue(T item,int end)
{ assert(!IsFull());
  if(end==1){
    end1=(end1+1)%size;
    data[end1]=item;}
  else{
    data[end2]=item;
    end2=(end2-1+size)%size;}
}
// 循环双端队列删除操作
template <class T>
void DoubleQueue <T>::Dequeue(int end)
{ assert(!IsEmpty());
  if(end==1){
    end1=(end1+size-1)%size;}
  else{
    end2=(end2+1)%size;}
}
// 循环双端队列输出操作
template <class T>
void DoubleQueue <T>::list(int end)
{ if(end==1){
    for(T p=(end2+1)%size;p<=end1;p=(p+1)%size)
     cout<<setw(3)<<data[p];
    cout<<endl;}
  else{
    for(T p=end1;p!=end2;p=(p+size-1)%size)
      cout<<setw(3)<<data[p];
    cout<<endl;}
}
//循环双端队列的测试
void main()
{DoubleQueue <int> Q;
 cout<<"duilie.cpp运行结果:\n";
//向队列end1插入4,5,6 三个元素
 Q.Enqueue(4,1);
 Q.Enqueue(5,1);
 Q.Enqueue(6,1);
 cout<<"输出向队列end1插入4,5,6三个元素后情况:\n";
 Q.list(1);
// 删除最后插入的一个元素
 Q.Dequeue(1);
 cout<<"输出删除最后一个元素后的队列end1的情况:\n";
 Q.list(1);
//向队列end2插入7,8,9 三个元素
 Q.Enqueue(7,2);
 Q.Enqueue(8,2);
 Q.Enqueue(9,2);
 cout<<"输出向队列end2插入7,8,9三个元素后情况:\n";
 Q.list(2);cin.get();}

