//二叉搜索树的类定义与实现BSTREE1.h
template<class T> class BSTree;
template<class T> struct TNode
{private:
  TNode<T>  *left;//左子树指针
  TNode<T> *right;//右子树指针
 public:
  friend class BSTree<T>;
  T data;//数据域
  //构造函数
  TNode():left(NULL),right(NULL){ }
  TNode(T item,TNode<T> *left1,TNode<T> *right1)
   :data(item),left(left1),right(right1){ }
};
template<class T> class BSTree
{private:
  int size;
 public:
  //构造函数,把树根指针置空
  BSTree(TNode<T> *&root){root=NULL;size=0;}
  //被ClearBST()所调用的函数
  void DeleteTree(TNode<T> *&root);
  //释放空间
  void FreeBST(TNode<T> *&root);
  //求二叉搜索树中所有结点数
  int BSTSize();
  //判断二叉搜索树是否为空
  int BSTEmpty(TNode<T> *&root);
  //取根指针
  TNode<T> *GetRoot(TNode<T> *&root);
  //从二叉搜索树中查找元素
  TNode<T> *BSTLocate(TNode<T> *&root,T item);
  //向二叉搜索树中插入元素
  void BSTInsert(TNode<T> *&root,T item);
  //从二叉搜索树中删除元素
  void BSTDelete(TNode<T> *&root,T item);
  //中序遍历输出二叉搜索树中的所有结点
  void Inorder(TNode<T> *&root);
  //求二叉搜索树的深度
  int BSTreeDepth(TNode<T> *&root);
  //求二叉搜索树中所有结点数
  int BSTreeCount(TNode<T> *&root);
  //求二叉搜索树中所有叶子结点数
  int BSTreeLeafCount(TNode<T> *&root);
  //清除二叉搜索树，使之变为一棵空树
  void ClearBSTree(TNode<T> *&root);
};
//二叉搜索树类的实现
template<class T>
void BSTree<T>::DeleteTree(TNode<T> *&root)
{if(root==NULL)	return;
 if(root->left!=NULL)
   DeleteTree(root->left);
 if(root->right!=NULL)
   DeleteTree(root->right);
 free(root);
}
template<class T>
void BSTree<T>::FreeBST(TNode<T> *&root)
	{DeleteTree(root);
	}
template<class T>
int BSTree<T>::BSTSize()
{return(size);}

template<class T>
int BSTree<T>::BSTEmpty(TNode<T> *&root)
{if(root==NULL)
   return(1);
 else
   return(0);
}
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
      if(item<t->data)
	t=t->left;
      else
	t=t->right;
   }
 return(t);
}
template<class T>
void BSTree<T>::BSTInsert(TNode<T> *&root,T item)
{TNode<T> *t,*p,*newN;
 newN=new TNode<T>;
 newN->data=item;
 if(root==NULL)
   {root=newN;
    size++;
    return;
   }
 t=root;
 p=NULL;
 while(t!=NULL)
   {p=t;
    if(item<t->data)
      t=t->left;
    else
      t=t->right;
   }
 if(item<p->data)
   p->left=newN;
 else
   p->right=newN;
 size++;
}
template<class T>
void BSTree<T>::BSTDelete(TNode<T> *&root,T item)
{TNode<T> *t,*p,*r,*pr;
 t=root;
 p=NULL;
 while(t!=NULL)
   {if(item==t->data)
      break;
    else
      {p=t;
       if(item<t->data)
	 t=t->left;
       else
	 t=t->right;
      }
   }
 if(t==NULL)
   return;
 if(t->left==NULL)
   {if(p==NULL)
      root=t->right;
    else if(p->left==t)
	   p->left=t->right;
	 else
	   p->right=t->right;
    free(t);
   }
 else
   {pr=t;
    r=t->left;
    while(r->right!=NULL)
      {pr=r;
       r=r->right;
      }
    t->data=r->data;
    if(pr==t)
      pr->left=r->left;
    else
      pr->right=r->left;
    free(r);
   }
  size--;
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
{if(root==NULL) return 0;//对于空树,返回0并结束递归
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
void BSTree<T>::ClearBSTree(TNode<T> *&root)
{DeleteTree(root);
 root=NULL;
 size=0;
}
