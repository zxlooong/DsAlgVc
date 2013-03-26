//利用克鲁斯卡尔方法求边集数组所示图的最小生成树
//图的相关数据类型的定义graph3.h
//最多顶点数
const int MaxV=10;
//最大权值
const int MaxValue=99;
//定义邻接表中的边结点类型
struct edgenode {
  int adjvex;     //邻接点域
  int weight;     //权值域
  edgenode* next; //指向下一个边结点的链域
};
//定义邻接表类型
typedef edgenode** adjlist;
//定义边集数组中的元素类型
struct RCW
{int row,col;//行列号
 int weight;//权值
};
//类定义
class adjMList
{private:
  int numE;//当前边数
  int GA[MaxV][MaxV];//定义邻接矩阵
 public:
  //构造函数,初始化图的邻接矩阵与边集数组
  adjMList(RCW GE[],int n,int e);
  //初始化图的邻接表
  void InitGAdjoin(adjlist& GL,int n);
  //删除图的邻接表
  void DeleteAdjoin(adjlist GL,int n);
  //建立带权图的邻接矩阵
  void CreateMatrix(int n,int &e,RCW r[]);
  //输出边集数组中的每条边
  void OutputEdgeSet(RCW ge[],int e);
  //根据图的邻接矩阵生成图的边集数组
  void ChangeEdgeSet(RCW GE[],int n,int e);
  //利用克鲁斯卡尔方法求边集数组GE所示图
  //的最小生成树,树中每条边依次存于数组C中
  void Kruskal(RCW GE[],RCW C[],int n,int e);
  //检查输入的边序号是否越界,若越界则重输
  void Check(int n, int& i, int& j);
};
