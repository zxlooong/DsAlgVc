//图的相关运算的实现graph1.cpp
#include"graph1.h"
//构造函数,初始化图的邻接表
AdjAdjoin::AdjAdjoin(edgenode **gL,int n)
{GL=gL;
 for(int i=0;i<n;i++)
  {g[i].adj=GL[i]=NULL;}
 size=numE=0;
}
//建立图的邻接表
void AdjAdjoin::CreateAdjoin(int n,int k1,int k2,RCW rcw[])
{int i,j,k,e,w;
 cout<<"输入图的总边数:";
  cin>>e;
 if(k1==0 && k2==0) {  //建立无向无权图
   cout<<"输入"<<e
       <<"条无向无权边的起点和终点序号!"<<endl;
   for(k=1; k<=e; k++) {
    cin>>i>>j;
    Check(n,i,j);
   //向序号i的单链表的表头插入一个边结点
   edgenode *p=new edgenode;
   p->adjvex=j; p->weight=1;
   p->next=GL[i];
   GL[i]=p;//向序号j的单链表的表头插入一个边结点
   p=new edgenode;
   p->adjvex=i; p->weight=1;
   cout<<'('<<p->adjvex<<','<<j<<','<<p->weight<<")\n";
   p->next=GL[j];
   GL[j]=p;}
 }
 else if(k1==0 && k2!=0) {  //建立无向有权图
   cout<<"输入"<<e
       <<"条无向带权边的起点和终点序号及权值!"<<endl;
   for(k=0; k<e; k++) {
    i=rcw[k].row;j=rcw[k].col;w=rcw[k].weight;
    //cin>>i>>j>>w;
    Check(n,i,j);
   //向序号i的单链表的表头插入一个边结点
   edgenode *p=new edgenode;
   p->adjvex=j; p->weight=w;
   p->next=GL[i];
   GL[i]=p;
   //向序号j的单链表的表头插入一个边结点
   p=new edgenode;
   p->adjvex=i;p->weight=w;
   p->next=GL[j];
   GL[j]=p;}
 }
 else if(k1!=0&&k2==0) {  //建立有向无权图
   cout<<"输入"<<e<<"条有向无权边的起点和终点序号!"<<endl;
   for(k=1; k<=e; k++) {
    cin>>i>>j;
    Check(n,i,j);
    //向序号i的单链表的表头插入一个边结点
    edgenode* p=new edgenode;
    p->adjvex=j; p->weight=1;
    p->next=GL[i];
    GL[i]=p;}
 }
 else if(k1!=0&&k2!=0) {  //建立有向有权图
   cout<<"输入"<<e
       <<"条有向有权边的起点和终点序号及权值!"<<endl;
   for(k=1; k<=e; k++) {
    cin>>i>>j>>w;
    Check(n,i,j);
    edgenode* p=new edgenode;
    p->adjvex=j; p->weight=w;
    p->next=GL[i];
    GL[i]=p;}}
 numE=e;size=n;   
}
//从初始点vi出发深度优先搜索由邻接表GL表示的图
void AdjAdjoin::dfsAdjoin(bool*& visited,int i,int n)
{cout<<g[i].data<<':'<<i<<"  ";
 visited[i]=true;
 //取vi邻接表的表头指针
 edgenode *p=GL[i];
 //依次搜索vi的每个邻接点
 while (p!=NULL) {
   int j=p->adjvex;//j为vi的一个邻接点序号
   if(!visited[j])
   dfsAdjoin(visited,j,n);
   p=p->next;  //使p指向vi单链表的下一个边结点
}}
//从初始点vi出发广度优先搜索由邻接表GL表示的图
void AdjAdjoin::bfsAdjoin(bool*& visited,int i,int n)
{const int  MaxLength=30;
 //定义一个队列q,其元素类型应为整型
 int q[MaxLength]={0};
 //定义队首和队尾指针
 int front=0, rear=0;
 //访问初始点vi
 cout<<g[i].data<<':'<<i<<"  ";
 //标记初始点vi已访问过
 visited[i]=true;
 //将已访问过的初始点序号i入队
 q[++rear]=i;
 //当队列非空时进行循环处理
 while(front!=rear) {
  //删除队首元素，第一次执行时k的值为i
  front=(front+1)%MaxLength;
  int k=q[front];
  //取vk邻接表的表头指针
  edgenode* p=GL[k];
  while(p!=NULL)
    {//依次搜索vk的每一个邻接点
     int j=p->adjvex;  //vj为vk的一个邻接点
     if(!visited[j]) { //若vj没有被访问过则进行处理
       cout<<g[j].data<<':'<<j<<"  ";
       visited[j]=true;
       rear=(rear+1)%MaxLength;//顶点序号j入队
       q[rear]=j;}
       p=p->next; //使p指向vk邻接表的下一个边结点
}}}
//检查输入的边序号是否越界,若越界则重输
void AdjAdjoin::Check(int n,int& i,int& j)
{while(1) {
  if(i<0||i>=n||j<0||j>=n)
    cout<<"输入有误,请重输!";
  else return;
  cin>>i>>j;
 }
}
//取顶点i的值
char AdjAdjoin::GetValue(const int i)
{if(i<0||i>size)
  {cerr<<"参数i越界!\n";exit(1);}
 return g[i].data;
}
//取弧<v1,v2>的权
int AdjAdjoin::GetWeight(const int v1,const int v2)
{if(v1<0||v1>size||v2<0||v2>size)
  {cerr<<"参数v1或v2越界!\n";exit(1);}
 edgenode *p=g[v1].adj;
 while(p!=NULL&&p->adjvex<v2) p=p->next;
 if(v2!=p->adjvex)
  {cerr<<"边<v1,v2>不存在!\n";exit(1);}
 return p->weight; 
}
//在位置pos处插入顶点V
void AdjAdjoin::InsertV(const char &V)
{g[size].data=V;
 size++; 
}
//插入弧<v1,v2>,权为weight
void AdjAdjoin::InsertEdge(const int v1,const int v2,int weight)
{if(v1<0||v1>size||v2<0||v2>size)
  {cerr<<"参数v1或v2越界!\n";exit(1);}
 edgenode *q=new edgenode(v2,weight);
 //q->adjvex=v2;q->weight=weight;
 if(g[v1].adj==NULL) //第一次插入
  g[v1].adj=q;
 else                //非第一次插入
  {edgenode *curr=g[v1].adj,*pre=NULL;
   while(curr!=NULL&&curr->adjvex<v2)
   {pre=curr;
    curr=curr->next;
   }
   if(pre==NULL)    //在第一个结点前插入
    {q->next=g[v1].adj;
     g[v1].adj=q;
    }
   else            //在其他位置插入
    {q->next=pre->next;
     pre->next=q;
    }
  }
 numE++; 
}
//删除顶点v与顶点v相关的所有边
void AdjAdjoin::DeleteVE(const int v)
{edgenode *pre,*curr;
 for(int i=0;i<size;i++)
 {pre=NULL;       //删除顶点v的入边
  curr=g[i].adj;
  while(curr!=NULL&curr->adjvex<v)
  {pre=curr;
   curr=curr->next;
  }
  if(pre==NULL&&curr->adjvex==v)
   {g[i].adj=curr->next; //该出边结点是链表的第一结点时
    delete curr;
    numE--;
   }
  else if(curr!=NULL&&curr->adjvex==v)
   {pre->next=curr->next;//该出边结点是链表的其他结点时
    delete curr;
    numE--;
   }
 }
 edgenode *p=g[v].adj,*q;
 for(int i=v;i<size-1;i++)
  g[i]=g[i+1]; //删除数组的顶点v元素
 numE--;
 while(p!=NULL)//删除顶点v的所有出边
 {q=p->next;
  delete p;    //释放空间
  p=q;
  numE--;
 }
}
//删除弧<v1,v2>
void AdjAdjoin::DeleteEdge(const int v1,const int v2)
{if(v1<0||v1>size||v2<0||v2>size||v1==v2)
  {cerr<<"参数v1或v2出错!\n";exit(1);}
 edgenode *curr=g[v1].adj,*pre=NULL;
  while(curr!=NULL&curr->adjvex<v2)
  {pre=curr;
   curr=curr->next;
  }
  if(pre==NULL&&curr->adjvex==v2)//要删除的结点是链表的第一结点
   {g[v1].adj=curr->next;
    delete curr;
    numE--;
   }
  else if(curr!=NULL&&curr->adjvex==v2)//不是链表的第一结点
   {pre->next=curr->next;
    delete curr;
    numE--;
   }
  else
   {cerr<<"边<v1,v2>不存在!\n";exit(1);}
}
//删除图的邻接表
void AdjAdjoin::DeleteAdjoin(int n)
{int i;
 edgenode* p;
 for(i=0;i<n;i++)
 {p=GL[i];
  while(p!=NULL)
   {GL[i]=p->next;
    delete p;p=GL[i];
   }
 }
 delete []GL;
}
//对非连通图进行深度优先搜索
void AdjAdjoin::dfsAdjoin(int n)
{bool *vis=new bool[NumV()];
 for(int i=0;i<NumV();i++) vis[i]=false;
 for(int i=0;i<NumV();i++)
  if(!vis[i]) dfsAdjoin(vis,i,n);
 delete []vis;
}
//对非连通图进行广度优先搜索
void AdjAdjoin::bfsAdjoin(int n)
{bool *vis=new bool[NumV()];
 for(int i=0;i<NumV();i++) vis[i]=false;
 for(int i=0;i<NumV();i++)
  if(!vis[i]) bfsAdjoin(vis,i,n);
 delete []vis;
}
void AdjAdjoin::CreatGraph(char V[],int n,RCW E[],int e)
{for(int i=0;i<n;i++) InsertV(V[i]);
 for(int k=0;k<e;k++)
  InsertEdge(E[k].row,E[k].col,E[k].weight);
 cout<<"输出建立的图:\n";
 for(int i=0;i<n;i++)
  cout<<g[i].data<<"  ";
 cout<<endl;  
}  
