//计算后缀表达式的值Evaluatem.cpp
#include<iostream.h>
#include<stdlib.h>
#include<strstrea.h>
#include<iomanip.h>
#include<stdio.h>
typedef float ElemType;
#include "Evaluate.cpp"
void main()
{char p[40];
 float y;
 cout<<"Evaluatem.cpp运行结果:\n";
 cout<<"输入后缀表达式:";
 gets(p);
 y=Evaluate(p);
 cout<<"后缀表达式的值:";
 cout<<y<<endl;cin.get();}


