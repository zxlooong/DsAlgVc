//最短路径SShortP1.cpp
//所有顶点之间的最短路径
#include<iostream.h>
#include<iomanip.h>
#include "graph.cpp"
#include "PShortP.h"
template<class T>
void Make2DArray(int **&a,int row,int col)
//定义二维动态数组a,其行数为row,列数为col
{a=new T*[row];//a为指针数组,长度为row
 for(int i=0;i<row;i++)
  a[i]=new T[col];//每个指针指向一个一维数组,长度为col
}
void SShortPath(AdjMatrix &G,int **dist,int **path)
{int n=G.NumV();
 for(int i=0;i<n;i++)
  PShortPath(G,i,dist[i],path[i]);
}
//算法测试
void main()
{cout<<"SShortP1.cpp运行结果:\n";
 int n=6,k1=1,k2=1,i,j;
 AdjMatrix g(n,k2);
 g.CreateMatrix(n,k1,k2);
 cout<<"输出邻接矩阵相应图的顶点:\n";
 g.Creatgraph(n,k2);
 
 int m=g.NumV();
 int **dist,**path;
 Make2DArray<int>(dist,m,m);
 Make2DArray<int>(path,m,m);
 SShortPath(g,dist,path);
 for(i=0;i<m;i++)
 {cout<<"从顶点"<<g.GetValue(i)
      <<"到其他各顶点的最短距离为:\n";
  for(j=0;j<m;j++)
   cout<<"到顶点"<<g.GetValue(j)
       <<"的最短距离为:"<<dist[i][j]<<endl;
   cout<<"从顶点"<<g.GetValue(i)
       <<"到其他各顶点的最短路径的前一顶点为:\n";
   for(j=0;j<m;j++)
    if(path[i][j]!=-1)
     cout<<"到顶点"<<g.GetValue(j)<<"的前一顶点为:"
         <<g.GetValue(path[i][j])<<endl;
 }
 cin.get();cin.get();}
