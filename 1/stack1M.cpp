//顺序栈的测试stack1M.cpp
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>

typedef struct STU{
  char name[10];
  char stuno[10];
  int age;
  int score;
}DataType;

#include "stack1.h"
#include"stack1.cpp"

void StackPrintElem(DataType *e)
{cout<<"姓名   学号  年龄 成绩\n";
 cout<<e->name<<setw(8)<<e->stuno;
 cout<<setw(4)<<e->age;
 cout<<setw(5)<<e->score<<endl;
}
void main()
{ DataType e;
  Stack Sa;//clrscr();
  int N=8;
  cout<<"stack1M.cpp运行结果:\n";
  cout<<"首先调用创建空栈函数!\n";
  Sa.SetStack(N);
  strcpy(e.name,"stu1");
  strcpy(e.stuno,"100001");
  e.age=20;
  e.score=87;
  Sa.Push(e);
  cout<<"压栈后现在栈中有一个元素!\n";
  StackPrintElem(&Sa.Peek());
  if(Sa.StackEmpty()) cout<<"栈Sa空!\n";
  else cout<<"栈Sa非空!\n";
  strcpy(e.name,"stu3");
  strcpy(e.stuno,"100002");
  e.age=21;
  e.score=90;
  Sa.Push(e);
  cout<<"现在栈中有二个元素!\n";
  StackPrintElem(&Sa.Peek());
  cout<<"栈Sa的长度:"<<Sa.StackSize()<<endl;
  cout<<"现在将元素e弹出栈!\n";
  Sa.Pop(e);
  StackPrintElem(&e);
  cout<<"栈的剩余元素:\n";
  Sa.StackTraverse(StackPrintElem);
  if(Sa.StackEmpty()) cout<<"栈Sa为空栈!\n";
  else cout<<"栈Sa为非空栈!\n";
  getch();
}

