//插入排序法(类方法)charufa2.cpp
#include<iostream.h>
#include<iomanip.h>
#define MAXI 11
typedef int KeyType;
typedef int ElemType;
struct rec {
 KeyType key;
 ElemType data;
};
typedef rec sqlist[MAXI];
class charu
{public:
  charu(sqlist a,int m):n(m)
   {for(int i=1;i<n;i++) b[i]=a[i];}
  void insertsort()
  {int i,j,k;
   for(i=2;i<n;i++)
   {b[0]=b[i];
    j=i-1;
    while(b[0].key<b[j].key)
    {b[j+1]=b[j];j--;}
     b[j+1]=b[0];
    for(k=1;k<n;k++)
     cout<<setw(4)<<b[k].key;
    cout<<endl;}}
  void output()
   {for(int i=1;i<n;i++)
     cout<<setw(4)<<b[i].key;
    cout<<endl;}
 private:
  sqlist b;int n;
};
void main()
{cout<<"charufa2.cpp运行结果:\n";
 sqlist a1;int i,n=MAXI;
 for(i=1;i<n;i++)
 {a1[i].key=random(101+i)%80;
  a1[i].data=random(121+i)%100;}
 charu px(a1,n);
 cout<<"排序前数组:\n";
 px.output();
 cout<<"数组排序过程演示:\n";
 px.insertsort();
 cout<<"排序后数组:\n";
 px.output();cin.get();}

