// 链式堆栈的实现linearStack2.cpp
#include "linearStack2.h"
//构造函数
 LinStack::LinStack()
 {top=NULL;size=0;}
//初始化栈,分配存储空间并置空
  void LinStack::InitStack(int L)
 {top=new StackNode[L];
  size=0;
 }
//创建有序或无序栈
 void LinStack::CreateStack(int m,int mark)
 {ElemType x,a[LEN];
  for(int i=0;i<m;i++) a[i]=random(215+i)%100;
  for(int i=0;i<m-1;i++)
  {int k=i;
   for(int j=i+1;j<m;j++)
    if(a[k]>a[j]) k=j;
   if(k!=i)
   {x=a[k];a[k]=a[i];a[i]=x;}}
  for(int i=0;i<m;i++)
  if(mark==1) Push(a[m-1-i]);//升序
  else
   if(mark==-1) Push(a[i]);//降序
   else Push(rand()%100);//无序
 }
 int LinStack::StackSize()
 {return size;}
//清空栈
 void LinStack::ClearStack() {size=0;}
//删除栈
 void LinStack::DeleteStack()
 {delete top;}
//检查栈是否为空
 bool LinStack::StackEmpty() {return size==0;}
//读取栈顶元素
 ElemType LinStack::Peek()
 { return top->data;}
//向栈中插入元素
 void LinStack::Push(const ElemType& item)
 {StackNode *newNode=new StackNode;
  newNode->data=item;newNode->next=top;
  top=newNode;
  size++;
 }
//从栈中删除元素
 ElemType LinStack::Pop()
 {if(size==0) {
   cerr<<"栈为空!"<<endl;exit(1);}
   StackNode *p=top->next;
   ElemType data=top->data;
   delete top;
   size--;
   top=p;
   return data;
 }
//检查栈是否已满
 bool LinStack::StackFull(ElemType m)
 {return size==m;}
//栈的输出
 void LinStack::StackPrint(ElemType m)
 {for(int i=0;i<m;i++)
   cout<<setw(3)<<Pop();
 }