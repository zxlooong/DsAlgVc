//选择排序法(下沉)xuanze2.cpp
#include<iostream.h>
#include<iomanip.h>
#define N 10
void gensort(int b[],int n)
{int i,j,k;
 for(i=1;i<n;i++)
 {k=n-i;
  for(j=n-i-1;j>=0;j--)
   if(b[k]<b[j]) k=j;
  if(k!=n-i)
  {int temp=b[k];b[k]=b[n-i];b[n-i]=temp;}
  for(int m=0;m<N;m++)
   cout<<setw(4)<<b[m];cout<<endl;}
}
//选择排序法测试
void main()
{cout<<"xuanze2.cpp运行结果:\n";
 int ai[N],i,m;
 for(i=0;i<N;i++)
  ai[i]=random(101+i)%100;
 cout<<"排序前数组:\n";
 for(i=0;i<N;i++)
  cout<<setw(4)<<ai[i];
 cout<<endl<<"排序过程演示:\n";
 gensort(ai,sizeof(ai)/sizeof(int));
 cout<<"排序后数组:\n";
 for(i=0;i<N;i++)
  cout<<setw(4)<<ai[i];
 cout<<endl;cin.get();}
