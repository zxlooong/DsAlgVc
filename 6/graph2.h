//利用普里姆算法求出用邻接
//矩阵表示的图的最小生成树
//图的相关数据类型的定义graph2.h
//最多顶点数
const int MaxV=10;
//最大权值
const int MaxValue=99;
//定义边集数组中的元素类型
struct RCW
{int row,col;
 int weight;
}; 
//类定义
class adjMList
{private:
  int numE;//当前边数
  int GA[MaxV][MaxV];//定义邻接矩阵
 public:
  //构造函数,初始化图的邻接矩阵与边集数组
  adjMList(RCW GE[],int n,int e);
  //建立无向带权图的邻接矩阵
  void CreateMatrix(int n,int &e,RCW r[]);
  //输出边集数组中的每条边
  void OutputEdgeSet(RCW ge[],int e);
  //根据图的邻接矩阵生成图的边集数组
  void ChangeEdgeSet(RCW GE[],int n,int e);
  //按升序排列图的边集数组
  void SortEdgeSet(RCW GE[],int e);
  //利用普里姆算法从顶点v0出发求出用邻接矩阵GA表
  //示的图的最小生成树,最小生成树的边集存于数组CT中
  void Prim(RCW CT[],int n);
  //检查输入的边序号是否越界,若越界则重输
  void Check(int n, int& i, int& j);
};
