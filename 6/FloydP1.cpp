//FloydP1.cpp
#include<iostream.h>
#include<iomanip.h>
#include "graph.cpp"
#include "FloydP.h"

//弗洛伊德算法测试
void main()
{cout<<"FloydP1.cpp运行结果:\n";
 int n=6,k1=1,k2=1,i,j;
 AdjMatrix g(n,k2);
 g.CreateMatrix(n,k1,k2);
 cout<<"输出邻接矩阵相应图的顶点:\n";
 g.Creatgraph(n,k2);
 
 int m=g.NumV();
 int dist[6][6],path[6][6];
 Floyd(g,dist,path);
 for(i=0;i<m;i++)
 {cout<<"从顶点"<<g.GetValue(i)
      <<"到其他各顶点的最短路径为:\n";
  for(j=0;j<m;j++)
   cout<<"到顶点"<<g.GetValue(j)
       <<"的最短路径为:"<<dist[i][j]<<endl;
   cout<<"从顶点"<<g.GetValue(i)
       <<"到其他各顶点的最短路径前一顶点为:\n";
   for(j=0;j<m;j++)
    if(path[i][j]!=-1)
     cout<<"到顶点"<<g.GetValue(j)<<"的前一顶点为:"
         <<g.GetValue(path[i][j])<<endl;
 }
 cin.get();cin.get();}
