//选择排序法(函数模板)xuanze4.cpp
// 排序不改变原数组各元素的值
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#define M 10
template<class T>
void sortp(T d[],T *pd[],int b[],int size)
{int i,j,k;
 for(i=0;i<size-1;i++)
 {k=i;
  for(j=i+1;j<size;j++)
   if(d[b[k]]>d[b[j]]) k=j;
  if(i!=k)
  {T g;g=b[i];b[i]=b[k];b[k]=g;}}
 for(i=0;i<size;i++) pd[i]=&d[b[i]];
}
void main()
{cout<<"xuanze4.cpp运行结果:\n";
 int q[M],*p[M],a[M],n=M,i,m;
 for(i=0;i<n;i++) q[i]=random(101+i)%100;
 for(i=0;i<n;i++) {a[i]=i;p[i]=&q[i];}
 cout<<"排序前数组:\n";
 for(i=0;i<n;i++)
  cout<<setw(4)<<q[i];
 cout<<endl<<"排序后原数组:\n";
 sortp(q,p,a,n);
 for(i=0;i<n;i++)
  cout<<setw(4)<<q[i];
 cout<<endl<<"排序后数组:\n";
 for(i=0;i<n;i++)
  cout<<setw(4)<<*p[i];
 cout<<endl;
 float w[M],*t[M];
 cout<<setiosflags(ios::fixed);
 for(i=0;i<n;i++) w[i]=random(289+i)/100.0;
 for(i=0;i<n;i++) {a[i]=i;t[i]=&w[i];}
 cout<<"排序前数组:\n";
 for(i=0;i<n;i++)
  cout<<setprecision(2)<<setw(6)<<w[i];
 cout<<endl<<"排序后原数组:\n";
 sortp(w,t,a,n);
 for(i=0;i<n;i++)
  cout<<setprecision(2)<<setw(6)<<w[i];
 cout<<endl<<"排序后数组:\n";
 for(i=0;i<n;i++)
  cout<<setprecision(2)<<setw(6)<<*t[i];
 cout<<endl;cin.get();}
