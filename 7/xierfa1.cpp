//希尔排序法(类方法)xierfa1.cpp
#include<iostream.h>
#include<iomanip.h>
#define MAXI 11
typedef int KeyType;
typedef int ElemType;
struct rec {
 KeyType key;ElemType data;};
typedef rec sqlist[MAXI];
class xier
{public:
  xier(sqlist a,int m):n(m)
  {for(int i=1;i<n;i++) b[i]=a[i];}
  void shellsort()
  {int i,j,gap,k;rec x;gap=n/2;
  while(gap>0)
  {for(i=gap+1;i<n;i++)
   {j=i-gap;
    while(j>0)
    if(b[j].key>b[j+gap].key)
    {x=b[j];b[j]=b[j+gap];b[j+gap]=x;j=j-gap;}
    else j=0;
    for(k=1;k<n;k++)
     cout<<setw(4)<<b[k].key;
    cout<<endl;}
    gap=gap/2;}}
 void output()
  {for(int i=1;i<n;i++)
    cout<<setw(4)<<b[i].key;
   cout<<endl;}
 private:sqlist b;int n;
};
void main()
{cout<<"xierfa1.cpp运行结果:\n";
 sqlist a1;int i,n=MAXI;
 for(i=1;i<n;i++)
 {a1[i].key=random(123+i)%100;
  a1[i].data=random(101)%80;}
 xier px(a1,n);
 cout<<"排序前数组:\n";
 px.output();
 cout<<"数组排序过程演示:\n";
 px.shellsort();
 cout<<"排序后数组:\n";
 px.output();cin.get();}

