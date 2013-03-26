//最短路径(狄克斯特拉算法)PshortP.h
//从一个顶点到其余各顶点的最短路径
void PShortPath(AdjMatrix &G,int v0,int dist[],int path[])
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
