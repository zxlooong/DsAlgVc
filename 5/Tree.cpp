//树类的实现Tree.cpp
template<class T>
void Tree<T>::DeleteSubTree(TreeNode<T> *&t)
{if(t==NULL) return;
 TreeNode<T> *q=t->firstChild,*p;
 while(q!=NULL)
 {p=q->nextSibling;
  DeleteSubTree(q);
  q=p;}
  cout<<"释放:"<<setw(2)<<t->data;
  delete t;
}
template<class T>
int Tree<T>::Current(TreeNode<T> *&t)
{if(t==NULL) return 0;
 curr=t;
 return 1;
}
template<class T>
int Tree<T>::Root()
{if(root==NULL)
  {curr=NULL;
   return 0;}
 return Current(root);
}
template<class T>
int Tree<T>::FirstChild()
{if(curr!=NULL&&curr->firstChild!=NULL)
  return Current(curr->firstChild);
 else return 0;
}
template<class T>
int Tree<T>::NextSibling()
{if(curr!=NULL&&curr->nextSibling!=NULL)
  return Current(curr->nextSibling);
 else return 0;
}
template<class T>
int Tree<T>::Parent()
{if(curr==NULL)
  {curr=root;
   return 0;}
 TreeNode<T> *p=SearchParent(root,curr);
 if(p==NULL) return 0;
 else return Current(p);
}
template<class T>
TreeNode<T> *Tree<T>::SearchParent(TreeNode<T> *&root,TreeNode<T> *&s)
{if(root==NULL) return NULL;
 if(root->FirstChild()==s||root->NextSibling()==s)
  return root;
 TreeNode<T> *p;
 if((p=SearchParent(root->FirstChild(),s))!=NULL) return p;
 if((p=SearchParent(root->NextSibling(),s))!=NULL) return p;
 return NULL;
}
template<class T>
void Tree<T>::InsertChild(T value)
{TreeNode<T> *newNode=new TreeNode<T> (value);
 if(root==NULL)  //当为空树时
  {root=curr=newNode;
   return;}
 if(curr->firstChild==NULL)//当当前结点无孩子时
  curr->firstChild=newNode;
 else                     //当当前结点有孩子时
  {TreeNode<T> *p=curr->firstChild;
   while(p->nextSibling!=NULL) p=p->nextSibling;
   p->nextSibling=newNode;
  }
  Current(newNode);//使新建立的结点成为当前结点
}      
template<class T>
int Tree<T>::DeleteChild(int i)
{TreeNode<T> *r=NULL;
 if(i==1)         //当删除当前结点的第一棵子树时
 {r=curr->firstChild;
  if(r==NULL) return 0;//要删除子树为空时返回
  curr->firstChild=r->nextSibling;//脱链要删除的子树
 }
 else {          //当删除当前结点的其他子树时
  int k=1;
  TreeNode<T> *p=curr->firstChild;
  while(p!=NULL&&k<=i-1)//寻找要删除子树的指针
  {p=p->nextSibling;
   k++;}
  if(p!=NULL)//寻找到要删除的子树的指针
  {r=p->nextSibling;
   if(r!=NULL)
    p->nextSibling=r->nextSibling;
   else return 0;
  }
  else return 0;
 }
 DeleteSubTree(r);
 return 1;
}
template<class T>
int Tree<T>::DeleteChild1(int i)
{if(root==NULL) return 0;//当为空树时
 TreeNode<T> *r=NULL,*q=root->firstChild;
 if(i==1&&q!=NULL) //当第一结点有孩子时
  {r=root->firstChild;
   root->firstChild=r->nextSibling;//脱链要删除的子树
  }
 else             //要删除第一结点外的其他子树时
  {int k=1;
   TreeNode<T> *p=root->firstChild;
   while(p!=NULL&&k<=i-1)//寻找要删除子树的指针
   {p=p->nextSibling;
    k++;
   }
  if(p!=NULL)    //寻找到要删除的子树的指针
   {r=p->nextSibling;
    if(r!=NULL)
     p->nextSibling=r->nextSibling;//脱链要删除的子树
    else return 0;}
  else return 0;
 }
 DeleteSubTree(r);//调用函数执行删除
 return 1;    
}
template<class T>
void Tree<T>::PreOrderTree(TreeNode<T> *&t)
{if(t==NULL) return;
 cout<<setw(2)<<t->data;//显示根结点数据
 if(t->firstChild!=NULL)//先根遍历子树
  PreOrderTree(t->firstChild);
 if(t->nextSibling!=NULL)
  PreOrderTree(t->nextSibling);
}
template<class T>
void Tree<T>::DisplayTree()
{PreOrderTree(root);}

template<class T>
void Tree<T>::DisplayTree1()
{PosOrderTree(root);}

template<class T>
void Tree<T>::PosOrderTree(TreeNode<T> *&t)
{if(t==NULL) return;
 if(t->firstChild!=NULL)//后根遍历子树
  PosOrderTree(t->firstChild);
 cout<<setw(2)<<t->data;//显示根结点数据
 if(t->nextSibling!=NULL)
  PosOrderTree(t->nextSibling);
}

