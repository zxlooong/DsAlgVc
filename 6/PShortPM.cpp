//最短路径算法PshortPM.cpp
#include<iostream.h>
#include<iomanip.h>
#include "graph0.cpp"
#include "PshortP.h"
//狄克斯特拉算法测试
void main()
{cout<<"PShortPM.cpp运行结果:\n";
 int n=6,e=9,k2=1;
 RCW rcw[]={{0,2,5},{0,3,30},{1,0,2},{1,4,8},
  {2,1,15},{2,5,7},{4,3,4},{5,3,10},{5,4,18}};
 AdjMatrix g(n,k2);
 g.Creatgraph(n,e,rcw);
 int m=g.NumV();
 int *dist=new int[m];
 int *path=new int[m];
 int v0=0;
 PShortPath(g,v0,dist,path);
 cout<<"从顶点"<<g.GetValue(v0)
     <<"到其他各顶点的最短距离为:\n";
 for(int i=0;i<m;i++)
  cout<<"到顶点"<<g.GetValue(i)
      <<"的最短距离为:"<<dist[i]<<endl;
 cout<<"从顶点"<<g.GetValue(v0)
     <<"到其他各顶点的最短路径的前一顶点为:\n";
 for(int i=0;i<m;i++)
  if(path[i]!=-1)
   cout<<"到顶点"<<g.GetValue(i)<<"的前一顶点为:"
       <<g.GetValue(path[i])<<endl;
 cin.get();}
 
