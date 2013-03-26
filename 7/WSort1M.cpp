//外存文件的排序操作的测试WSort1M.cpp
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>
#include "WSort1.h"
void main()
{cout<<"WSort1M.cpp运行结果:\n";
 int n,i;
 char *fa=".\\fa1.dat";
 fstream fna(fa,ios::in|ios::out|ios::binary);
 cout<<"输入表长n:";cin>>n;
 cout<<"文件未排序前的结果:\n";
 LoadFile myfile(fa,n);
 myfile.Print(fna);
 if(n%2==0)
  {myfile.FMergeSort(fna,2);
   for(i=2;i<=n/2;i++)
    {myfile.FMergeSort(fna,2*i-1);
     myfile.FMergeSort(fna,2*i);}
   myfile.FMergeSort(fna,n/2);}
 else
  {myfile.FMergeSort(fna,2);
   for(i=2;i<=n/2;i++)
    {myfile.FMergeSort(fna,2*i-1);
     myfile.FMergeSort(fna,2*i);}
   myfile.FMergeSort(fna,n/2+1);}
 cout<<"文件排序后的结果:\n";
 myfile.Print(fna);fna.close();
 cin.get();cin.get();}
