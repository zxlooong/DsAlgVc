//图的相关运算的测试graph2M.cpp
#include<iostream.h>
#include<iomanip.h>
#include "graph2.cpp"
void main()
{cout<<"graph2M.cpp运行结果:\n";
 RCW rcw[20]={{0,1,50},{1,0,50},{0,2,60},{2,0,60},
  {1,3,65},{3,1,65},{1,4,40},{4,1,40},{2,3,52},
  {3,2,52},{2,6,45},{6,2,45},{3,4,50},{4,3,50},
  {3,5,30},{5,3,30},{3,6,42},{6,3,42},{4,5,70},{5,4,70}};
 int n,k;//定义图的点数及边数等
 cout<<"输入图的点数n=";cin>>n;
 cout<<"输入图的边数k=";cin>>k;
 static RCW AE[30],BE[30];//定义边集数组
 adjMList A(AE,n,k);
 A.CreateMatrix(n,k,rcw);
 cout<<"输出边集数组中的每条边:\n";
 A.ChangeEdgeSet(AE,n,k);
 A.OutputEdgeSet(AE,k);
 cout<<"输出按升序排列的图的边集数组:\n";
 A.SortEdgeSet(AE,k);
 A.OutputEdgeSet(AE,k);
 A.Prim(BE,n);
 cout<<"输出最小生成树的边集数组:\n";
 A.OutputEdgeSet(BE,k);
 cin.get();cin.get();}


