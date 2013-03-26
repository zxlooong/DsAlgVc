//堆排序法duifa2.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<string.h>
#define M 11
typedef int KeyType;
typedef int ElemType;
struct rec {
 KeyType key;ElemType data;};
typedef rec sqlist[M];
void output(sqlist r,int n)
 {for(int i=1;i<n;i++)
   cout<<setw(4)<<r[i].key;
    cout<<endl;}
void sift(sqlist r,int s,int m)
{int j;rec x;
 x=r[s];
 for(j=2*s;j<=m;j*=2)
 {if(j<m&&(r[j].key<r[j+1].key)) ++j;
  if(!(x.key<r[j].key)) break;
   r[s]=r[j];s=j;}
  r[s]=x;}
void heapsort(sqlist &r,int m)
{int i;rec w;
 for(i=m/2;i>0;--i) sift(r,i,m);
 for(i=m;i>1;--i)
  {w=r[i];r[i]=r[1];r[1]=w;
   output(r,M);
   sift(r,1,i-1);}
}
void main()
{cout<<"duifa2.cpp运行结果:\n";
 sqlist a;int i;
 for(i=1;i<M;i++)
  a[i].key=random(201+i)%80;
 cout<<"排序前数组:\n";
 output(a,M);
 cout<<"数组排序的过程演示:\n";
 heapsort(a,M);
 cout<<"排序后数组:\n";
 output(a,M);cin.get();}

