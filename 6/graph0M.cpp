//图的相关运算的测试graph0M.cpp
#include<iostream.h>
#include<iomanip.h>
#include "graph0.cpp"
void main()
{cout<<"graph0M.cpp运行结果:\n";
 RCW rcw[]={{0,1,1},{0,2,1},{1,3,1},{1,4,1},
    {2,5,1},{2,6,1},{1,0,1},{2,0,1},{3,1,1},
    {4,1,1},{5,2,1},{6,2,1}};
 //定义图的点数及搜索起始点序号等
 int n,k,i,j,e=12;
 //k1为0则无向否则为有向,k2为0则无权否则为有权
 int k1,k2;
 //标记已访问过的点
 bool *vis;
 //定义邻接表
 adjlist AL;
 cout<<"输入图的点数n=";cin>>n;
 AL=new edgenode*[n];
 vis=new bool[n];
 if(!vis) {cout<<"申请堆内存失败!\n";exit(1);}
 for(i=0;i<n;i++)
  vis[i]=false;
 cout<<"输入选择无向(权)与有向(权)图的值k1,k2:";
 cin>>k1>>k2;
 //定义邻接矩阵
 AdjMatrix A(n,k2);
 A.CreateMatrix(n,k1,k2,rcw);
 cout<<"出发点Vk的序号=";cin>>k;
 cout<<"\n输出邻接矩阵相应图的每个顶点:\n";
 A.Creatgraph(n,e,rcw);
 cout<<"当前的顶点数为:"<<A.NumV()<<endl;
 cout<<"当前的边数为:"<<A.NumEdges()<<endl;

 cout<<"图的深度优先搜索顺序:\n";
 A.dfsMatrix(vis,k,n,k2);
 for(i=0;i<n;i++) vis[i]=false;
 cout<<"\n图的广度优先搜索顺序:\n";
 A.bfsMatrix(vis,k,n,k2);

 cout<<"\n输出邻接表的每个邻接点:\n";
 for(i=0;i<n;i++) vis[i]=false;
 A.graphChange(AL,n,k2);
 delete []vis;

 A.DeleteEdge(0,2);
 A.DeleteEdge(2,0);

 cout<<"当前的顶点数为:"<<A.NumV()<<endl;
 cout<<"当前的边数为:"<<A.NumEdges()<<endl;
 cout<<"图的深度优先搜索顺序:\n";
 A.dfsMatrix(n,k2);
 cout<<"\n图的广度优先搜索顺序:\n";
 A.bfsMatrix(n,k2);
 cin.get();cin.get();
}
