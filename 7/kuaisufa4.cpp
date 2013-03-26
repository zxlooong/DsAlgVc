//快速排序法kuaisufa4.cpp
#include<iostream.h>
#include<iomanip.h>
#define M 11
typedef int KeyType;
typedef int ElemType;
struct rec {
 KeyType key;ElemType data;};
typedef rec sqlist[M];
void output(sqlist b,int n)
 {for(int i=1;i<n;i++)
   cout<<setw(4)<<b[i].key;
    cout<<endl;
 }
void quicksort(sqlist r,int s,int t)
 {int i=s,j=t;
   if(s<t)
   {r[0]=r[s];
    while(i<j)
    {while(i<j&&r[j].key>=r[0].key) j--;
      r[i]=r[j];
     while(i<j&&r[i].key<=r[0].key) i++;
      r[j]=r[i];}
    r[i]=r[0];
    output(r,M);}
   else return;
  quicksort(r,s,j-1);
  quicksort(r,j+1,t);
 }
void main()
{cout<<"kuaisufa4.cpp运行结果:\n";
 sqlist a1;int i,n=M,low=0,high=10;
 for(i=0;i<n;i++)
  a1[i].key=random(235+i)%80;
 cout<<"排序前数组:\n";
 output(a1,n);
 cout<<"数组排序的过程演示:\n";
 quicksort(a1,low,high);
 cout<<"排序后数组:\n";
 output(a1,n);cin.get();}
kuaisufa4.cpp运行结果:
排序前数组:
  20  39  66  26   3   7   4  43  25  26
数组排序的过程演示:
  20  25   4  26   3   7  26  43  66  39
   3   4   7  26  25  20  26  43  66  39
   3   4   7  26  25  20  26  43  66  39
   3   4   7  26  25  20  26  43  66  39
   3   4   7  20  25  26  26  43  66  39
   3   4   7  20  25  26  26  43  66  39
   3   4   7  20  25  26  26  39  43  66
排序后数组:
   3   4   7  20  25  26  26  39  43  66

