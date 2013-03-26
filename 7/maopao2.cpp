//冒泡排序法(上浮)maopao2.cpp
#include<iostream.h>
#include<iomanip.h>
#define N 10
void gensort(int b[],int n)
{int i,j;
 for(i=0;i<n-1;i++)
  {for(j=i+1;j<n;j++)
    if(b[i]>b[j])
     {int temp=b[i];
      b[i]=b[j];b[j]=temp;}
   for(int k=0;k<n;k++)
    cout<<setw(4)<<b[k];
   cout<<endl;
  }
}
void main()
{cout<<"maopao2.cpp运行结果:\n";
 int ai[N],i;
 for(i=0;i<N;i++)
  ai[i]=random(101+i)%100;
 cout<<"排序前数组:\n";
 for(i=0;i<N;i++)
  cout<<setw(4)<<ai[i];
 cout<<endl;
 cout<<"排序过程演示:\n";
 gensort(ai,sizeof(ai)/sizeof(int));
 cout<<"排序后数组:\n";
 for(i=0;i<N;i++)
  cout<<setw(4)<<ai[i];
 cout<<endl;cin.get();}






