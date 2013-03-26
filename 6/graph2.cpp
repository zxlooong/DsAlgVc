//图的运算的实现文件graph2.cpp
#include"graph2.h"
//构造函数,初始化图的邻接矩阵与边集数组
adjMList::adjMList(RCW GE[],int n,int e)
{int i,j;
 for(i=0; i<n; i++)
 for(j=0; j<n; j++)
  if(i==j) GA[i][j]=0;
  else GA[i][j]=MaxValue;
 for(i=0;i<e;i++) GE[i].weight=0;
 numE=0;
}
//输出边集数组中的每条边
void adjMList::OutputEdgeSet(RCW ge[],int e)
{int i,k=0;
 cout<<"{";
 for(i=0; i<=e-2; i++)
  if(ge[i].weight>0){k++;
   cout<<'('<<ge[i].row<<','<<ge[i].col;
   cout<<','<<ge[i].weight<<") ";
   if(k%5==0) cout<<endl;}
  if(e>0&&ge[i].weight>0) {
   cout<<'('<<ge[e-1].row<<','<<ge[e-1].col;
   cout<<','<<ge[e-1].weight<<')';}
   cout<<'}'<<endl;
}
//建立无向带权图的邻接矩阵
void adjMList::CreateMatrix(int n,int &e,RCW r[])
{int i,j,k=0,w;
 cout<<"依次输入无向带权图的每条边的起点和终点"<<endl;
 cout<<"序号及权值!直到输入权值为0的边为止!"<<endl;
 do {i=r[k].row;j=r[k].col;w=r[k].weight;
     //cin>>i>>j>>w;
     Check(n,i,j);
     if(k==e-1) break;
     GA[i][j]=GA[j][i]=w;k++;
   }while(1);
 numE=e=k;
 cout<<"邻接矩阵:\n";
 for(i=0;i<n;i++)
 {for(j=0;j<n;j++)
   cout<<setw(4)<<GA[i][j];
   cout<<endl;}
}
//检查输入的边序号是否越界,若越界则重输
void adjMList::Check(int n, int& i, int& j)
{while(1) {
   if(i<0 || i>=n ||j<0 || j>=n)
    cout<<"输入有误,请重输!";
   else return;
  cin>>i>>j;}
}
//根据图的邻接矩阵生成图的边集数组
void adjMList::ChangeEdgeSet(RCW GE[],int n,int e)
{//假定只考虑无向图的情况
 int i,j,k=0;
 for(i=0; i<n; i++)
 for(j=i+1; j<n; j++)
  if(GA[i][j]!=0 && GA[i][j]!=MaxValue)
   {if(k==e) {cout<<"数组GE下标越界!\n";
     exit(1);}
    GE[k].row=i;
    GE[k].col=j;
    GE[k].weight=GA[i][j];
    k++;
   }
}
//按升序排列图的边集数组
void adjMList::SortEdgeSet(RCW GE[],int e)
{int i,j;
 RCW x;
 for(i=1; i<=e-1; i++)
  {x=GE[i];
   for(j=i-1; j>=0; j--)
    if(x.weight<GE[j].weight) GE[j+1]=GE[j];
    else break;
   GE[j+1]=x;
  }
}
//利用普里姆算法从顶点v0出发求出用邻接矩阵GA表示
//的图的最小生成树,最小生成树的边集存于数组CT中
void adjMList::Prim(RCW CT[],int n)
{int i,j, k, min, t, m, w;
  //给CT赋初值，对应为v0依次到其余各顶点的边
 for(i=0; i<n-1; i++)
  {CT[i].row=0;
   CT[i].col=i+1;
   CT[i].weight=GA[0][i+1];}
   //进行n-1次循环，每次求出最小生成树中的第k条边
 for(k=1; k<n; k++)
  {//从CT[k-1]~CT[n-2]中查找最短边CT[m]
   min=MaxValue;
   m=k-1;
   for(j=k-1; j<n-1; j++)
    if(CT[j].weight<min) {
     min=CT[j].weight;
     m=j;}
  //把最短边对调到第k-1下标位置
  RCW temp=CT[k-1];
  CT[k-1]=CT[m];
  CT[m]=temp;
  //把新并入最小生成树T中的顶点序号赋给j
  j=CT[k-1].col;
  //修改有关边，使T中到T外的每一个顶点各保持
  //一条到目前为止最短的边
  for(i=k; i<n-1; i++) {
   t=CT[i].col;
   w=GA[j][t];
   if(w<CT[i].weight) {
    CT[i].weight=w;
    CT[i].row=j;
}}}}

