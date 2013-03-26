//图的相关数据类型的定义graph1.h
//最多顶点数
const int MaxV=10;
//定义邻接表中的边结点类型
struct edgenode {
 int adjvex;     //邻接点域
 int weight;     //权值域
 edgenode* next; //指向下一个边结点的链域
 edgenode(){}
 edgenode(int d,int w):adjvex(d),weight(w),next(NULL){}
};
struct Top //顶点数组的元素类型
{char data;//顶点数据
 edgenode *adj;//邻接表指针
};
struct RCW
{int row;
 int col;
 int weight;
};
//邻接表的类定义
class AdjAdjoin
{private:
  Top g[MaxV];//顶点数组
  int size;   //顶点个数
  int numE;   //当前边的条数
 public:
  edgenode **GL;//定义邻接表
  //构造函数
  AdjAdjoin() {}
  //构造函数,初始化图的邻接表
  AdjAdjoin(edgenode **gl,int n);
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
  void InsertV(const char &V);
  //插入弧<v1,v2>,权为weight
  void InsertEdge(const int v1,const int v2,int weight);
  //删除顶点i与顶点i相关的所有边
  void DeleteVE(const int v);
  //删除弧<v1,v2>
  void DeleteEdge(const int v1,const int v2);
  //删除图的邻接表
  void DeleteAdjoin(int n);
  //建立图
  void CreatGraph(char V[],int n,RCW E[],int e);
  //建立图的邻接表
  void CreateAdjoin(int n,int k1,int k2,RCW rcw[]);
  //从初始点vi出发深度优先搜索由邻接表GL表示的图
  void dfsAdjoin(bool*& visited,int i,int n);
  //从初始点vi出发广度优先搜索由邻接表GL表示的图
  void bfsAdjoin(bool*& visited,int i,int n);
  //检查输入的边序号是否越界,若越界则重输
  void Check(int n,int& i,int& j);
   //对非连通图进行深度优先搜索
  void dfsAdjoin(int n);
  //对非连通图进行广度优先搜索
  void bfsAdjoin(int n);
};

