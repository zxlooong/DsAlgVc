//对磁盘文件进行排序的测试WSortM.cpp
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>
#include "WSort.h"
void main()
{cout<<"WSortM.cpp运行结果:\n";
 int m=10;
 char *fa=".\\fa1.dat";
 ElemType d[10];
 fstream fna(fa,ios::out|ios::in|ios::dec|ios::trunc);
 cout<<"文件未排序前的结果:\n";
 LoadFile myfile(fa,m);
 myfile.Print(fna);
 cout<<"文件排序后的结果:\n";
 myfile.FMergeSort(fna,d,m);
 myfile.Print(fna);
 fna.close();cin.get();}