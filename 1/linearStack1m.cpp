//顺序堆栈的测试linearStack1m.cpp
#include<iostream.h>
#include<iomanip.h>
typedef int ElemType;
#include "linearStack1.cpp"
void main()
{cout<<"linearStack1m.cpp运行结果:\n";
 int m;
 Stack q,p,w;
 cout<<"输入欲构造栈q的长度m:";cin>>m;
 q.CreateStack(m,1);
 cout<<"输出q栈元素(升序):\n";
 q.StackPrint(m);cout<<endl;
 cout<<"q栈:";
 if(q.StackFull(m)==1)
  cout<<"已满!\n";
 else cout<<"未满!\n";
 cout<<"创建栈p(降序):\n";
 p.CreateStack(m,-1);
 cout<<"p栈:";
 if(p.StackFull(m)==1)
  cout<<"已满!\n";
 else cout<<"未满!\n";
 cout<<"删除元素为:"<<p.Pop()<<endl;
 cout<<"p栈:";
 if(p.StackEmpty()==1)
  cout<<"为空!\n";
 else cout<<"为非空!\n";
 cout<<"输出p栈元素:\n";
 p.StackPrint(m-1);cout<<endl;
 cout<<"创建栈w(无序):\n";
 w.CreateStack(m);
 cout<<"输出w栈元素:\n";
 w.StackPrint(m);cout<<endl;
 p.ClearStack();
 cin.get();cin.get();}



