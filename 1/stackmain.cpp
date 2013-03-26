//顺序栈的测试stackmain.cpp
#include<iostream.h>
#include<iomanip.h>
#include<malloc.h>
#include<conio.h>
typedef int Status ;
typedef struct STU{
  char name[10];
  char stuno[10];
  int age;
  int score;
}SElemType;
void StackPrintElem(SElemType *e)
{cout<<"姓名   学号  年龄 成绩\n";
 cout<<e->name<<setw(8)<<e->stuno;
 cout<<setw(4)<<e->age;
 cout<<setw(5)<<e->score<<endl;
}
#include"stack.cpp"
void main()
{ SElemType e;
  SqStack *Sa;
  clrscr();
  cout<<"stackmain.cpp运行结果:\n";
  Sa->InitStack(&Sa);
  strcpy(e.name,"stu1");
  strcpy(e.stuno,"100001");
  e.age=20;
  e.score=87;
  cout<<"现在栈是空栈!\n";
  cout<<"现在调用压栈函数!\n";
  Sa->Push(e);
  cout<<"现在栈有一个元素!\n";
  StackPrintElem(&Sa->GetTop());
  if(Sa->StackEmpty()) cout<<"栈Sa空!\n";
  else cout<<"栈Sa非空!\n";
  strcpy(e.name,"stu3");
  strcpy(e.stuno,"100002");
  e.age=21;
  e.score=90;
  Sa->Push(e);
  cout<<"现在栈有二个元素!\n";
  StackPrintElem(&e);
  cout<<"栈Sa的长度:"<<Sa->StackLength()<<endl;
  cout<<"现在将元素e弹出栈!\n";
  Sa->Pop(&e);
  StackPrintElem(&e);
  cout<<"栈的剩余元素:\n";
  Sa->StackTraverse(StackPrintElem);
  if(Sa->StackEmpty()) cout<<"栈Sa空!\n";
  else cout<<"栈Sa非空!\n";
  getch();
}

