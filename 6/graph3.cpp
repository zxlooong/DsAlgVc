//图的运算的实现文件graph3.cpp
#include"graph3.h"
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
//初始化图的邻接表
void adjMList::InitGAdjoin(adjlist& GL,int n)
{GL=new edgenode*[n];
 for(int i=0; i<n; i++) GL[i]=NULL;
}
//删除图的邻接表
void adjMList::DeleteAdjoin(adjlist GL,int n)
{int i;
 edgenode* p;
 for(i=0;i<n;i++) {
   p=GL[i];
   while(p!=NULL) {GL[i]=p->next;
    delete p;p=GL[i];}}
 delete []GL;
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
//建立带权图的邻接矩阵
void adjMList::CreateMatrix(int n,int &e,RCW r[])
{int i,j,k=0,w;
 cout<<"依次输入带权图的每条边的起点和终点"<<endl;
 cout<<"序号及权值!直到输入权值为0的边为止!"<<endl;
 do {i=r[k].row;j=r[k].col;w=r[k].weight;
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
//利用克鲁斯卡尔方法求边集数组GE所示图的
//最小生成树,树中每条边依次存于数组C中
void adjMList::Kruskal(RCW GE[],RCW C[],int n,int e)
{int i,j;
 RCW x;
 //按权weight升序排列图的边集数组
 for(i=1; i<=e-1; i++)
  {x=GE[i];
   for(j=i-1; j>=0; j--)
    if(x.weight<GE[j].weight) GE[j+1]=GE[j];
    else break;
   GE[j+1]=x;
  }
 edgenode* p;
 //定义邻接表s作为集合使用,其中每一个单链表s[i]用来表示一个集合
 adjlist s;
 //初始化邻接表s
 InitGAdjoin(s,n);
 //初始化s集合,使每一个顶点分属于不同的集合
 for(i=0; i<n; i++)
  {p=new edgenode;
   p->adjvex=i;p->next=NULL;
   s[i]=p;}
   int k=1; //k表示待获取的最小生成树中的边数,初值为1
   int d=0; //d表示GE中待扫描边元素的下标位置,初值为0
   //m1和m2用来分别记录一条边的两个顶点所在集合的序号
   int m1,m2;
  //进行n-1次循环,得到最小生成树中的n-1条边
  while(k<n)
   {//求边GE[d]的两个顶点所在集合的序号m1和m2
    for(i=0; i<n; i++)
     {p=s[i];
      while(p!=NULL) {
       if(p->adjvex==GE[d].row) m1=i;
       if(p->adjvex==GE[d].col) m2=i;
	 p=p->next;}
     }
   //若两集合序号不等,则表明GE[d]是
   //生成树中的一条边,应将它加入到数组C中
  if(m1!=m2)
   {C[k-1]=GE[d];
    k++;
    //合并两个集合,并将另一个置为空集
    p=s[m1];
    while(p->next!=NULL) p=p->next;
    p->next=s[m2];
    s[m2]=NULL;
   }
  //d后移一个位置,以便扫描GE中的下一条边
  d++;}
  //删除邻接表s
 DeleteAdjoin(s,n);
}
