//FloydP.cpp
#include<iostream.h>
#include<iomanip.h>
#include "graph0.cpp"
#include "FloydP.h"
//弗洛伊德算法测试
void main()
{cout<<"FloydP.cpp运行结果:\n";
 int i,j,e=9,n=6,k2=1;
 RCW rcw[9]={{0,2,5},{0,3,30},{1,0,2},{1,4,8},
  {2,1,15},{2,5,7},{4,3,4},{5,3,10},{5,4,18}};
 AdjMatrix g(n,k2); 
 g.CreateMatrix(n,1,k2,rcw);
 g.Creatgraph(n,e,rcw);
 int dist[6][6];
 int path[6][6];
 Floyd(g,dist,path);
 for(i=0;i<n;i++)
 {cout<<"从顶点"<<g.GetValue(i)
      <<"到其他各顶点的最短距离为:\n";
  for(j=0;j<n;j++)
   cout<<"到顶点"<<g.GetValue(j)
       <<"的最短距离为:"<<dist[i][j]<<endl;
   cout<<"从顶点"<<g.GetValue(i)
       <<"到其他各顶点的最短路径的前一顶点为:\n";
   for(j=0;j<n;j++)
    if(path[i][j]!=-1)
     cout<<"到顶点"<<g.GetValue(j)<<"的前一顶点为:"
         <<g.GetValue(path[i][j])<<endl;
 }
 cin.get();cin.get();}
