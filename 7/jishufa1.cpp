//基数排序法(类方法)jishufa1.cpp
#include<iostream.h>
#include<iomanip.h>
const int N=10;
class jishu
{public:
  jishu(int d[],int s):n(s)
   {for(int i=0;i<n;i++)
     A[i]=d[i];}
  void output()
  {for(int i=0;i<n;i++)
    cout<<setw(4)<<A[i];
   cout<<endl;}
  void radix(int B[],int k,int r,int cnt[])
  {int j;
   for(int i=0,rtok=1;i<k;i++,rtok*=r)
   {for(j=0;j<r;j++) cnt[j]=0;
    for(j=0;j<n;j++) cnt[(A[j]/rtok)%r]++;
    for(j=1;j<r;j++) cnt[j]=cnt[j-1]+cnt[j];
    for(j=n-1;j>=0;j--) B[--cnt[(A[j]/rtok)%r]]=A[j];
    for(j=0;j<n;j++) A[j]=B[j];
    output();}}
 private:int A[N],n;
};
void main()
{cout<<"jishufa1.cpp运行结果:\n";
 int a[N],b[N],c[N],i,k=3;
 for(i=0;i<N;i++)
 {a[i]=random(459+i)%100;
  b[i]=0;}
 jishu jx(a,N);
 cout<<"排序前数组a:\n";
 jx.output();
 cout<<"数组排序的过程演示:\n";
 jx.radix(b,k,10,c);
 cout<<"排序后数组a:\n";
 jx.output();cin.get();}







