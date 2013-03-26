//最短路径(狄克斯特拉算法)PshortP1.cpp
//从一个顶点到其余各顶点的最短路径
#include<iostream.h>
#include<iomanip.h>
#include "graph.cpp"
void PShortPath(AdjMatrix G,int v0,int dist[],int path[])
//网G从下标v0到其他顶点的最短距离dist和最短路径下标path
{int n=G.NumV();
 int *s=new int[n];
 int mindis,i,j,u;
 for(i=0;i<n;i++)
 {dist[i]=G.GetWeight(v0,i);
  s[i]=0;
  if(i!=v0&&dist[i]<MaxValue) path[i]=v0;
  else path[i]=-1;
 }
 s[v0]=1;//标记顶点v0已从集合T加入到集合S中
 //在当前还未找到最短路径的顶点集中选取具有最短距离的顶点u
 for(i=1;i<n;i++)
 {mindis=MaxValue;
  for(j=0;j<n;j++)
   if(s[j]==0&&dist[j]<mindis)
    {u=j;
     mindis=dist[j];
    }
  //当已不再存在路径时算法结束;此语句对非连通图是必需的
  if(mindis==MaxValue) return;
  s[u]=1;//标记顶点u已从集合T加入到集合S中
  //修改从v0到其他顶点的最短距离和最短路径
  for(j=0;j<n;j++)
   if(s[j]==0&&G.GetWeight(u,j)<MaxValue&&
    dist[u]+G.GetWeight(u,j)<dist[j])
   {//顶点v0经顶点u到其他顶点的最短距离和最短路径
    dist[j]=dist[u]+G.GetWeight(u,j);
    path[j]=u;
   }
 }
}
//算法测试
void main()
{cout<<"PShortP1.cpp运行结果:\n";
 int n=6,k1=1,k2=1;
 AdjMatrix g(n,k2);
 g.CreateMatrix(n,k1,k2);
 g.Creatgraph(n,k2);
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
 cin.get();cin.get();}
