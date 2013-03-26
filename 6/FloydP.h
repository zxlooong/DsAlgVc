//最短路径(弗洛伊德算法)FloydP.h
//所有顶点之间的最短路径
void Floyd(AdjMatrix &G,int dist[6][6],int path[6][6])
//求图G中每对顶点之间的最短距离dist和最短路径的顶点序号path
{int i,j,k;
 int n=G.NumV();
 for(i=0;i<n;i++)//初始化
  for(j=0;j<n;j++)
  {dist[i][j]=G.GetWeight(i,j);
   if(i!=j&&dist[i][j]!=MaxValue) path[i][j]=i;
   else
    if(i==j) path[i][j]=0;
    else path[i][j]=-1;
  }
  for(k=0;k<n;k++)
   for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {if(dist[i][j]>(dist[i][k]+dist[k][j]))
      {dist[i][j]=dist[i][k]+dist[k][j];
       path[i][j]=path[k][j];
}}}