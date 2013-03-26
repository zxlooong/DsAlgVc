//快速排序法kuaisufa3.cpp
#include<iostream.h>
#include<iomanip.h>
#define N 10
float b[N];
void output()
 {for(int i=0;i<N;i++)
   cout<<setprecision(2)<<setw(6)<<b[i];
    cout<<endl;}
int part(int s,int t)
 {int i,j;float p;
  i=s;j=t;p=b[s];
  while(i<j)
   {while(i<j&&b[j]>=p) j--;
     b[i]=b[j];
     while(i<j&&b[i]<=p) i++;
     b[j]=b[i];}
    b[i]=p;
    output();
  return i;}
void quicksort(int s,int t)
  {int i;
   if(s<t) {
    i=part(s,t);
    quicksort(s,i-1);
    quicksort(i+1,t);}
   else return;}
void main()
{cout<<"kuaisufa2.cpp运行结果:\n";
 int i,n=N,low=0,high=9;
 for(i=0;i<n;i++)
  b[i]=random(389+i)/200.0;
 cout<<"排序前数组:\n";
 cout<<setiosflags(ios::fixed);
 output();
 cout<<"数组排序的过程演示:\n";
 quicksort(low,high);
 cout<<"排序后数组:\n";
 output();cin.get();}

