//linelistm.cpp
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include "linelist.h"
#include "linelist.cpp"
void main()
{ clrscr();
  cout<<"linelistm.cpp运行结果:\n";
  List La;
  List Lb(&La);
  ElemType ch[10];
  int k;
  cout<<"首先调用插入函数.\n";
  for(k=0;k<8;k++)
  {ch[k]='a'+k;
   La.ListInsert(k,ch[k]);}
  cout<<"表La长:"<<La.ListLength()<<endl;
  getch();//cin.get();按回车键
  for(k=0;k<7;k++)
  cout<<La.GetElem(k,&ch[k])<<',';
  cout<<La.GetElem(k,&ch[k])<<endl;getch();
}