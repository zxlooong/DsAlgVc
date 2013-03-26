//图的相关运算的实现graph0.cpp
#include"graph0.h"
//构造函数,初始化图的邻接矩阵
AdjMatrix::AdjMatrix(int n,int k2)
{int i,j;
 if(k2==0){//初始化无(有)向无权图
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    GA[i][j]=0;}
 else {//初始化无(有)向有权图
  for(i=0;i<n;i++)
   for(j=0;j<n;j++)
    if(i==j) GA[i][j]=0;
    else GA[i][j]=MaxValue;}
 size=numE=0;
}
//建立图的邻接矩阵
void AdjMatrix::CreateMatrix(int n,int k1,int k2,RCW r[])
//k1为0则无向否则为有向,k2为0则无权否则为有权
{int i,j,k,e,w;
 cout<<"输入图的总边数:";
   cin>>e;
 if(k1==0 && k2==0) { //建立无向无权图
  cout<<"输入"<<e<<"条无向无权边的起点和终点序号!"<<endl;
  for(k=1; k<=e; k++) {
   cin>>i>>j;
   Check(n,i,j);
   GA[i][j]=GA[j][i]=1;}
  }
 else if(k1==0 && k2!=0) { //建立无向有权图
   cout<<"输入"<<e<<"条无向带权边的起点和终点序号及权值!"<<endl;
   for(k=0; k<e; k++) {
    i=r[k].row;j=r[k].col;w=r[k].weight;
    //cin>>i>>j>>w;
    Check(n,i,j);
    GA[i][j]=GA[j][i]=w;}
  }
  else if(k1!=0 && k2==0) { //建立有向无权图
    cout<<"输入"<<e<<"条有向无权边的起点和终点序号!"<<endl;
    for(k=1; k<=e; k++) {
     cin>>i>>j;
     Check(n,i,j);
     GA[i][j]=1;}
  }
  else if(k1!=0 && k2!=0) { //建立有向有权图
    cout<<"输入"<<e<<"条有向有权边的起点和终点序号及权值!"<<endl;
    for(k=0; k<e; k++) {
     i=r[k].row;j=r[k].col;w=r[k].weight;
     //cin>>i>>j>>w;
     Check(n,i,j);
     GA[i][j]=w;}}
  cout<<"创建后的邻接矩阵:\n";   
  for(i=0;i<n;i++)
  {for(j=0;j<n;j++)
    cout<<setw(4)<<GA[i][j];
   cout<<endl;}
}
//从初始点vi出发深度优先搜索由邻接矩阵表示的图
void AdjMatrix::dfsMatrix(bool*& visited,int i,int n,int k2)
{cout<<g[i]<<':'<<i<<"  ";
 visited[i]=true;        //标记vi已被访问过
 for(int j=0; j<n; j++)  //依次搜索vi的每个邻接点
  if(k2==0)
   {if(i!=j&&GA[i][j]!=0&&!visited[j])
     dfsMatrix(visited,j,n,k2);}
  else
   if(i!=j&&GA[i][j]!=MaxValue&&!visited[j])
     dfsMatrix(visited,j,n,k2);
}
//从初始点vi出发广度优先搜索由邻接矩阵表示的图
void AdjMatrix::bfsMatrix(bool*& visited,int i,int n,int k2)
{const int MaxLength=30;
 //定义一个队列q,其元素类型应为整型
 int q[MaxLength]={0};
 //定义队首和队尾指针
 int front=0,rear=0;
 //访问初始点vi
 cout<<g[i]<<':'<<i<<"  ";
 //标记初始点vi已访问过
 visited[i]=true;
  //将已访问过的初始点序号i入队
 q[++rear]=i;
  //当队列非空时进行循环处理
 while(front!=rear) {
  //删除队首元素,第一次执行时k的值为i
  front=(front+1)%MaxLength;
  int k=q[front];
  //依次搜索vk的每一个可能的邻接点
  for(int j=0;j<n;j++)
   if(k2==0)
    {if(k!=j&&GA[k][j]!=0&&!visited[j])
     {//访问一个未被访问过的邻接点vj
      cout<<g[j]<<':'<<j<<"  ";
      visited[j]=true;     //标记vj已访问过
      rear=(rear+1)%MaxLength;//顶点序号j入队
      q[rear]=j;
     }
    }
   else
    if(k!=j&&GA[k][j]!=MaxValue&&!visited[j])
     {//访问一个未被访问过的邻接点vj
      cout<<g[j]<<':'<<j<<"  ";
      visited[j]=true;   //标记vj已访问过
      rear=(rear+1)%MaxLength;//顶点序号j入队
      q[rear]=j;
     }
}}
//检查输入的边序号是否越界,若越界则重输
void AdjMatrix::Check(int n,int& i,int& j)
{while(1) {
  if(i<0||i>=n||j<0||j>=n)
    cout<<"输入有误,请重输!";
  else return;
  cin>>i>>j;
 }
}
//由图的邻接矩阵得到图的邻接表
void AdjMatrix::graphChange(adjlist &GL,int n,int k2)
{int i,j;
 if(k2==0)
 {for(i=0;i<n;i++){
  for(j=0;j<n;j++)
    if(GA[i][j]!=0) {
     edgenode* p=new edgenode;
     p->adjvex=j;
     p->next=GL[i];GL[i]=p;
     cout<<'('<<i<<','<<p->adjvex<<") ";}
  cout<<endl;}}
 else {
  for(i=0;i<n;i++){
   for(j=0;j<n;j++)
    if(GA[i][j]!=0 && GA[i][j]!=MaxValue) {
     edgenode* p=new edgenode;
     p->adjvex=j;p->weight=GA[i][j];
     p->next=GL[i];GL[i]=p;
     cout<<'('<<i<<','<<p->adjvex<<','<<p->weight<<") ";}
   cout<<endl;}
}}
//创建图
void AdjMatrix::Creatgraph(int n,int e,RCW r[])
{int i,k;
 for(i=0;i<n;i++) InsertV('A'+i,i);
 for(k=0;k<e;k++)
   InsertEdge(r[k].row,r[k].col,r[k].weight);
}
//取顶点i的值
char AdjMatrix::GetValue(const int i)
{if(i<0||i>size)
  {cerr<<"参数i越界!\n";exit(1);}
 return g[i];
}
//取弧<v1,v2>的权
int AdjMatrix::GetWeight(const int v1,const int v2)
{if(v1<0||v1>size||v2<0||v2>size)
  {cerr<<"参数v1或v2越界!\n";exit(1);}
 return GA[v1][v2]; 
}
//在位置pos处插入顶点V
void AdjMatrix::InsertV(const char &V,int pos)
{int i;
 if(size==MaxV)
  {cerr<<"表已满,无法插入!\n";exit(1);}
 if(pos<0||pos>size)
  {cerr<<"参数pos越界!\n";exit(1);}
 for(i=size;i>pos;i--) g[i]=g[i-1];
 g[pos]=V;
 size++; 
}
//插入弧<v1,v2>,权为weight
void AdjMatrix::InsertEdge(const int v1,const int v2,int weight)
{if(v1<0||v1>size||v2<0||v2>size)
  {cerr<<"参数v1或v2越界!\n";exit(1);}
 GA[v1][v2]=weight;
 numE++; 
}
//删除顶点v与顶点v相关的所有边
char AdjMatrix::DeleteVE(const int v)
{for(int i=0;i<size;i++)
  for(int j=0;j<size;j++)
   if((i==v||j==v)&&GA[i][j]>0&&GA[i][j]<MaxValue)
    {GA[i][j]=MaxValue;
     numE--;}
 if(size==0)
  {cerr<<"表已空,无元素可删!\n";exit(1);}
 if(v<0||v>size-1)
  {cerr<<"参数v越界!\n";exit(1);}
 char temp=g[v];
 for(int i=v;i<size-1;i++) g[i]=g[i+1];
 size--;
 g[size]='\0';
 return temp;
}
//删除弧<v1,v2>
void AdjMatrix::DeleteEdge(const int v1,const int v2)
{if(v1<0||v1>size||v2<0||v2>size||v1==v2)
  {cerr<<"参数v1或v2出错!\n";exit(1);}
 GA[v1][v2]=MaxValue;
 numE--;
}
//对非连通图进行深度优先搜索
void AdjMatrix::dfsMatrix(int n,int k2)
{bool *vis=new bool[NumV()];
 for(int i=0;i<NumV();i++) vis[i]=false;
 for(int i=0;i<NumV();i++)
  if(!vis[i]) dfsMatrix(vis,i,n,k2);
 delete []vis;
}
//对非连通图进行广度优先搜索
void AdjMatrix::bfsMatrix(int n,int k2)
{bool *vis=new bool[NumV()];
 for(int i=0;i<NumV();i++) vis[i]=false;
 for(int i=0;i<NumV();i++)
  if(!vis[i]) bfsMatrix(vis,i,n,k2);
 delete []vis;
}

