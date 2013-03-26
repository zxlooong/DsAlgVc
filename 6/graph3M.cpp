//图的相关运算的测试graph3M.cpp
#include<iostream.h>
#include<iomanip.h>
#include "graph3.cpp"
void main()
{cout<<"graph3M.cpp运行结果:\n";
 int n,k;//定义图的点数及边数等
 RCW rcw[20]={{0,1,50},{1,0,50},{0,2,60},{2,0,60},
  {1,3,65},{3,1,65},{1,4,40},{4,1,40},{2,3,52},
  {3,2,52},{2,6,45},{6,2,45},{3,4,50},{4,3,50},
  {3,5,30},{5,3,30},{3,6,42},{6,3,42},{4,5,70},{5,4,70}};
 static RCW AE[30],BE[30];//定义边集数组
 cout<<"输入图的点数n=";cin>>n;
 cout<<"输入图的边数k=";cin>>k;
 adjMList B(AE,n,k);
 B.CreateMatrix(n,k,rcw);
 //由图的邻接矩阵生成图的边集数组
 B.ChangeEdgeSet(AE,n,k);
 cout<<"输出邻接矩阵生成图的边集数组:\n";
 B.OutputEdgeSet(AE,k);
 cout<<"输出最小生成树的边集数组:\n";
 B.Kruskal(AE,BE,n,k);
 B.OutputEdgeSet(BE,k);
 cin.get();cin.get();}
