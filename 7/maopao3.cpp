//冒泡排序法(下沉)maopao3.cpp
#include<iostream.h>
#include<iomanip.h>
#define N 10
void gensort(int b[],int n)
{int i,j;
 for(i=1;i<n;i++)
 {for(j=0;j<n-i;j++)
   if(b[j]>b[j+1])
    {int temp=b[j];
     b[j]=b[j+1];b[j+1]=temp;}
  for(int k=0;k<n;k++)
   cout<<setw(4)<<b[k];
  cout<<endl;
 }
}
void main()
{cout<<"maopao3.cpp运行结果:\n";
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






