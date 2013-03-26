//图的相关运算的测试graph1M.cpp
#include<iostream.h>
#include<iomanip.h>
#include "graph1.cpp"
void main()
{cout<<"graph1M.cpp运行结果:\n";
 char a[]={'A','B','C','D','E','F','G'};
 RCW rcw[]={{0,1,1},{0,2,1},{1,3,1},{1,4,1},{2,5,1},
  {2,6,1},{1,0,1},{2,0,1},{3,1,1},{4,1,1},{5,2,1},{6,2,1}};
 //定义图的点数及搜索起始点序号等
 int n,k,i,j;
 //k1为0则无向否则为有向,k2为0则无权否则为有权
 int k1,k2;
 //标记已访问过的点
 bool *vis;
 cout<<"输入图的点数n=";cin>>n;
 vis=new bool[n];
 if(!vis) {cout<<"申请堆内存失败!\n";exit(1);}
 for(i=0;i<n;i++) vis[i]=false;
 cout<<"输入选择无向(权)与有向(权)图的值k1,k2:";
 cin>>k1>>k2;
 edgenode **gl=new edgenode*[n];
 AdjAdjoin B(gl,n);
 B.CreatGraph(a,n,rcw,12);
 cout<<"创建邻接表:\n";
 B.CreateAdjoin(n,k1,k2,rcw);
 cout<<"出发点Vk的序号=";cin>>k;
 cout<<"当前的顶点数为:"<<B.NumV()<<endl;
 cout<<"当前的边数为:"<<B.NumEdges()<<endl;
 cout<<"表的深度优先搜索顺序:\n";
 B.dfsAdjoin(vis,k,n);cout<<endl;
 cout<<"表的广度优先搜索顺序:\n";
 for(i=0;i<n;i++) vis[i]=false;
 B.bfsAdjoin(vis,k,n);cout<<endl;

 B.DeleteEdge(0,2);
 B.DeleteEdge(2,0);
 cout<<"当前的顶点数为:"<<B.NumV()<<endl;
 cout<<"当前的边数为:"<<B.NumEdges()<<endl;
 cout<<"表的深度优先搜索顺序:\n";
 B.dfsAdjoin(n);cout<<endl;
 cout<<"表的广度优先搜索顺序:\n";
 for(i=0;i<n;i++) vis[i]=false;
 B.bfsAdjoin(n);cout<<endl;
 B.DeleteAdjoin(n);
 cin.get();cin.get();
}
