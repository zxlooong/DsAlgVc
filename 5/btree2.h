//二叉树类定义btree2.h
//定义二叉树结点类型
template<class T>class BinaryTree;
template<class T> struct BTreeNode {
 private:
  BTreeNode<T> *left;//左子树指针
  BTreeNode<T> *right;//右子树指针
 public:
  T data;//数据域
  //构造函数
  BTreeNode():left(NULL),right(NULL) { }
  BTreeNode(T item,BTreeNode<T> *left1=NULL,
    BTreeNode<T> *right1=NULL):data(item),
    left(left1),right(right1){ }
  BTreeNode<T> *&Left(){return left;}
  BTreeNode<T> *&Right(){return right;}
  friend class BinaryTree<T>;
};
//二叉树类定义
template<class T>class BinaryTree {
 private:
  BTreeNode<T> *root;
 public:
//构造函数,初始化二叉树为空
  BinaryTree() {root=NULL;}
//根据字符数组a的二叉树广义表建立对应的二叉树存储结构
  void CreateBTree(char* a);
//判断二叉树是否为空
  bool BTreeEmpty() {return root==NULL;}
//按任一种遍历次序输出二叉树中的所有结点
  void TraverseBTree(int mark);
//用于遍历的递归函数
  void Traverse(BTreeNode<T> *&BT,int mark);
//求二叉树的深度
  int BTreeDepth();
//用于求二叉树深度的递归函数
  int Depth(BTreeNode<T> *&BT);
//求二叉树中所有结点数
  int BTreeCount();
//用于求二叉树中所有结点数的递归函数
  int Count(BTreeNode<T> *&BT);
//求二叉树中所有叶子结点数
  int BTreeLeafCount();
//用于求二叉树中所有叶子结点数的递归函数
  int LeafCount(BTreeNode<T> *&BT);
//按照二叉树的一种表示方法输出整个二叉树
  void PrintBTree();
//用于输出整个二叉树的递归函数
  void Print(BTreeNode<T> *&BT);
//用于清除二叉树的递归函数
  void Clear(BTreeNode<T> *&BT);
//析构函数，清除二叉树
  ~BinaryTree();
};

