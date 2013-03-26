//intarray.cpp
//建立一维,二维数组的类实现
//数组下标从1开始,引用下标作下标越界检查
#include<iostream.h>
#include<iomanip.h>
#include "intarray.h"
void IntArray1::init(int n)
{if(n<1){
  cout<<"Error dimension description";
  exit(1);}
 size=n;
 data=new int[size];
}
int &IntArray1::operator[](int i)
{if(i<1||i>size){ //下标越界检查
   cout<<endl<<"Subscript out of range";
   delete []data;
   exit(2);}
 return data[i-1];//IntArry1的下标从1开始
}
void IntArray1::ReArray(int si)
{if(si<1)
  {cerr<<"长度无效!\n";exit(1);}
 if(si==size) return;
 int *newArray=new int[si];
 if(!newArray)
  {cerr<<"内存分配失败!\n";exit(1);}
 int n=(si<=size)?si:size;
 int *souceP=data;
 int *destP=newArray;
 while(n--)
  *destP++=*souceP++;
 delete []data;
 data=newArray;
 size=si;
}   
IntArray2::IntArray2(int m,int n)
{if(m<1||n<1){
   cout<<"Error dimension description";
   exit(1);}
 size=m;
 data=new IntArray1[size];
 for(int i=0;i<size;i++) data[i].init(n);
}
IntArray1 &IntArray2::operator[](int i)
{if(i<1||i>size){ //下标越界检查
   cout<<endl<<"Subscript out of range";
   delete []data;
   exit(1);}
 return data[i-1];//IntArry2的下标从1开始
}
