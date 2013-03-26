//zhuanhuanm.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
typedef char ElemType;
#include "zhuanhuan.cpp"
void main()
{cout<<"zhuanhuanm.cpp运行结果:\n";
 char p1[40],p2[40];
 cout<<"输入中缀表达式:";
 gets(p1);
 zhuanhuan(p1,p2);
 cout<<"\n输出后缀表达式:";
 cout<<p2;cin.get();}
 


