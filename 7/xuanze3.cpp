//选择排序法(类方法)xuanze3.cpp
#include<iostream.h>
#include<iomanip.h>
#define N 10
class xuanze
{public:
  xuanze(int a[],int m):n(m)
  {for(int i=0;i<n;i++) b[i]=a[i];}
  void xuanzesort()
  {int i,j,k;
   for(i=0;i<n-1;i++)
   {k=i;
    for(j=i+1;j<n;j++)
     if(b[k]>b[j]) k=j;
    if(k!=i)
    {int temp=b[k];
     b[k]=b[i];b[i]=temp;}
    for(int m=0;m<n;m++)
     cout<<setw(4)<<b[m];
    cout<<endl;}}
   void output()
   {for(int i=0;i<n;i++)
    cout<<setw(4)<<b[i];
    cout<<endl;}
 private:
  int b[N],n;
};
//选择排序法测试
void main()
{cout<<"xuanze3.cpp运行结果:\n";
 int ai[N],i,m;
 for(i=0;i<N;i++)
  ai[i]=random(101+i)%100;
 xuanze px(ai,N);
 cout<<"排序前数组:\n";
 px.output();
 cout<<"数组排序过程演示:\n";
 px.xuanzesort();
 cout<<"排序后数组:\n";
 px.output();cin.get();}

