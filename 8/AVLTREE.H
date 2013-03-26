//平衡二叉搜索树类定义与实现AVLTREE.h
template<class T> class BSTree;
//平衡二叉搜索树的结点类型定义
template<class T> struct TNode
{private:
  TNode<T>  *left;//左子树指针
  TNode<T> *right;//右子树指针
 public:
  int balance;//平衡因子
  T data;//数据域
  friend class BSTree<T>;
  //构造函数
  TNode():left(NULL),right(NULL),balance(0){ }
  TNode(T item,TNode<T> *left1,TNode<T> *right1)
   :balance(0),data(item),left(left1),right(right1){ }
};
template<class T> class BSTree
{private:
  int size;
 public:
  //构造函数
  BSTree(TNode<T> *&root):size(0){root=NULL;}
  //被ClearBST()所调用的函数
  void DeleteTree(TNode<T> *&root);
  //LL型调整操作
  void LL(TNode<T> **a,TNode<T> **b);
  //RR型调整操作
  void RR(TNode<T> **a,TNode<T> **b);
  //LR型调整操作
  void LR(TNode<T> **a,TNode<T> **b);
  //RL型调整操作
  void RL(TNode<T> **a,TNode<T> **b);
  //释放空间
  void FreeBST(TNode<T> *&root);
  //求平衡二叉搜索树中所有结点数
  int BSTSize();
  //判断平衡二叉搜索树是否为空
  int BSTEmpty(TNode<T> *&root);
  //取根指针
  TNode<T> *GetRoot(TNode<T> *&root);
  //从平衡二叉搜索树中查找元素
  TNode<T> *BSTLocate(TNode<T> *&root,T item);
  //向平衡二叉搜索树中插入元素
  void BSTInsert(TNode<T> *&root,T item);
  //中序遍历平衡二叉搜索树中的所有结点
  void Inorder(TNode<T> *&root);
  //求平衡二叉搜索树的深度
  int BSTreeDepth(TNode<T> *&root);
  //求平衡二叉搜索树中所有结点数
  int BSTreeCount(TNode<T> *&root);
  //求平衡二叉搜索树中所有叶子结点数
  int BSTreeLeafCount(TNode<T> *&root);
  //清除平衡二叉搜索树，使之变为一棵空树
  void ClearBST(TNode<T> *&root);
  //初始化平衡二叉搜索树
  void SetTNode(TNode<T> *&root,T item);
  //获取设置的平衡二叉搜索树的一个结点
  TNode<T> *GetTNode(T item,TNode<T> *left,TNode<T> *right);
};
//平衡二叉搜索树的类实现
template<class T>
void BSTree<T>::DeleteTree(TNode<T> *&root)
{if(root==NULL) return;
 if(root->left!=NULL)
  DeleteTree(root->left);
 if(root->right!=NULL)
  DeleteTree(root->right);
 free(root);
}
template<class T>
void BSTree<T>::LL(TNode<T> **a,TNode<T> **b)
{(*a)->balance=0;
 (*a)->left=(*b)->right;
 (*b)->balance=0;
 (*b)->right=(*a);
}
template<class T>
void BSTree<T>::RR(TNode<T> **a,TNode<T> **b)
{(*a)->balance=0;
 (*a)->right=(*b)->left;
 (*b)->balance=0;
 (*b)->left=(*a);
}
template<class T>
void BSTree<T>::LR(TNode<T> **a,TNode<T> **b)
{TNode<T> *c;
 c=(*b)->right;//c是插入结点
 (*a)->left=c->right;
 (*b)->right=c->left;
 c->left=(*b);
 c->right=(*a);
 switch(c->balance)
  {case 0:(*a)->balance=0;
          (*b)->balance=0;
          break;
   case 1:(*a)->balance=-1;//插入的结点在c的左子树
          (*b)->balance=0;
          break;
   case -1:(*a)->balance=0;//插入的结点在c的右子树
          (*b)->balance=1;
          break;}
 c->balance=0;
 (*b)=c;//使b指向调整后的子树的根
}
template<class T>
void BSTree<T>::RL(TNode<T> **a,TNode<T> **b)
{TNode<T> *c;
 c=(*b)->left; //c是插入结点
 (*a)->right=c->left;
 (*b)->left=c->right;
 c->right=(*b);
 c->left=(*a);
 switch(c->balance)
  {case 0:(*a)->balance=0;
          (*b)->balance=0;
          break;
   case 1:(*a)->balance=0;//插入的结点在c的左子树
          (*b)->balance=-1;
          break;
   case -1:(*a)->balance=1;//插入的结点在c的右子树
           (*b)->balance=0;
          break;}
 c->balance=0;
 (*b)=c;//使b指向调整后的子树的根
}
template<class T>
void BSTree<T>::FreeBST(TNode<T> *&root)
{DeleteTree(root);}
template<class T>
int BSTree<T>::BSTSize()
{return(size);}
template<class T>
int BSTree<T>::BSTEmpty(TNode<T> *&root)
{if(root==NULL) return(1);
 else return(0);}
template<class T>
TNode<T> *BSTree<T>::GetRoot(TNode<T> *&root)
{return(root);}
template<class T>
TNode<T> *BSTree<T>::BSTLocate(TNode<T> *&root,T item)
{TNode<T> *t;
 t=root;
 while(t!=NULL)
  {if(item==t->data) break;
   else
    if(item<t->data) t=t->left;
    else t=t->right;}
 return(t);
}
template<class T>
void BSTree<T>::BSTInsert(TNode<T> *&root,T item)
{int d;
 TNode<T> *t,*p,*newN,*a,*b,*f;
 newN=new TNode<T>;
 newN->data=item;
 if(root==NULL)
  {root=newN;
   size++;
   return;}
 t=root;p=NULL;
 a=t;f=p;
 while(t!=NULL)
  {if(t->balance!=0)
    {a=t;f=p;}
   p=t;
   if(item<t->data) t=t->left;
   else t=t->right;}
 if(item<p->data) p->left=newN;
 else p->right=newN;
  size++;
 if(item<a->data)
  {b=t=a->left;}
 else {b=t=a->right;}
 while(t!=NULL&&t->data!=item)
  {if(item<t->data)
    {t->balance=1;
     t=t->left;}
   else {t->balance=-1;t=t->right;}}
 if(a->balance==0)
  {if(item<a->data) a->balance=1;
   else a->balance=-1;
   return;}
 else
  if(item<a->data&&a->balance==-1||
    item>a->data&&a->balance==1)
   {a->balance=0;return;}
  else
   {if(a->balance==1)
     if(b->balance==1)
      LL(&a,&b);
     else LR(&a,&b);
    else
     if(b->balance==-1) RR(&a,&b);
     else RL(&a,&b);}
    if(f==NULL) root=b;
    else
     {if(f->left==a) f->left=b;
      else f->right=b;}
}
template<class T>
void BSTree<T>::Inorder(TNode<T> *&root)
{if(root!=NULL) {
  Inorder(root->left);
  cout<<setw(2)<<root->data;
  Inorder(root->right);}
}
template<class T>
int BSTree<T>::BSTreeDepth(TNode<T> *&root)
{if(root==NULL) return 0;
 else
  {  //计算左子树的深度
   int dep1=BSTreeDepth(root->left);
     //计算右子树的深度
   int dep2=BSTreeDepth(root->right);
     //返回树的深度
   if(dep1>dep2) return dep1+1;
   else return dep2+1;}
}
template<class T>
int BSTree<T>::BSTreeCount(TNode<T> *&root)
{if(root==NULL) return 0;
 else 
  return BSTreeCount(root->left)+BSTreeCount(root->right)+1;
}
template<class T>
int BSTree<T>::BSTreeLeafCount(TNode<T> *&root)
{if(root==NULL) return 0;
 else
  if(root->left==NULL && root->right==NULL) return 1;
  else
   return BSTreeLeafCount(root->left)+BSTreeLeafCount(root->right);
}
template<class T>
void BSTree<T>::ClearBST(TNode<T> *&root)
{DeleteTree(root);
 root=NULL;
 size=0;
}
template<class T>
void BSTree<T>::SetTNode(TNode<T> *&root,T item)
{root->data=item;
 root->balance=0;
 root->left=NULL;
 root->right=NULL;
}
template<class T>
TNode<T>* BSTree<T>::GetTNode(T item,TNode<T> *left,TNode<T> *right)
{TNode<T> *ptr;
 ptr=new TNode<T>;
 ptr->data=item;
 ptr->balance=0;
 ptr->left=left;
 ptr->right=right;
 return(ptr);
}
