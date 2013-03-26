//图的相关数据类型的定义graph.h
//最多顶点数
const int MaxV=10;
//最大权值
const int MaxValue=99;
//定义邻接表中的边结点类型
struct edgenode {
 int adjvex;   //邻接点域
 int weight;   //权值域
 edgenode* next;//指向下一个边结点的链域
};
//定义邻接表类型
typedef edgenode** adjlist;
//邻接矩阵类定义
class AdjMatrix
{private:
  char g[MaxV];//顶点信息数组
  int size;//当前顶点数
  int GA[MaxV][MaxV];//定义邻接矩阵GA
  int numE;//当前边数
 public:
  //构造函数,初始化图的邻接矩阵
  AdjMatrix(int n,int k2);
  //判断图空否
  bool GraphEmpty() {return size==0;}
  //取当前顶点数
  int NumV() {return size;}
  //取当前边数
  int NumEdges() {return numE;}
  //取顶点i的值
  char GetValue(const int i);
  //取弧<v1,v2>的权
  int GetWeight(const int v1,const int v2);
  //在位置pos处插入顶点V
  void InsertV(const char &V,int pos);
  //插入弧<v1,v2>,权为weight
  void InsertEdge(const int v1,const int v2,int weight);
  //删除顶点i与顶点i相关的所有边
  char DeleteVE(const int i);
  //删除弧<v1,v2>
  void DeleteEdge(const int v1,const int v2);
  //建立图的邻接矩阵
  void CreateMatrix(int n, int k1,int k2);
  //k1为0则无向否则为有向,k2为0则无权否则为有权
  //从初始点vi出发深度优先搜索由邻接矩阵表示的图
  void dfsMatrix(bool*& visited,int i,int n,int k2);
  //从初始点vi出发广度优先搜索由邻接矩阵表示的图
  void bfsMatrix(bool*& visited,int i,int n,int k2);
  //由图的邻接矩阵得到图的邻接表
  void graphChange(adjlist &GL,int n,int k2);
  //检查输入的边序号是否越界,若越界则重输
  void Check(int n,int& i,int& j);
  //由图的邻接矩阵建立图
  void Creatgraph(int n,int k2);
  //对非连通图进行深度优先搜索
  void dfsMatrix(int n,int k2);
  //对非连通图进行广度优先搜索
  void bfsMatrix(int n,int k2);
};
