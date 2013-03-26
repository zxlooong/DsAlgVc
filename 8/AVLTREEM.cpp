//平衡二叉搜索树的类测试AVLTREEM.cpp
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include "AVLTREE.H"
TNode<char> *q;
void main()
{cout<<"AVLTREEM.cpp运行结果:\n";
 int i;
 char test[50]="abxyMNcdefg";
 BSTree<char> t(q);
 //cout<<"input data:\n";
 //gets(test);
 for(i=0;test[i]!='\0';i++)
  t.BSTInsert(q,test[i]);
 cout<<"平衡二叉搜索树的结点数="<<t.BSTSize()<<endl;
 cout<<"平衡二叉搜索树的结点数="<<t.BSTreeCount(q)<<endl;
 cout<<"平衡二叉搜索树的深度="<<t.BSTreeDepth(q)<<endl;
 cout<<"平衡二叉搜索树的叶子结点数="<<t.BSTreeLeafCount(q)<<endl;
 cout<<"中序遍历平衡二叉搜索树:\n";
 t.Inorder(q);
 getch();
 t.FreeBST(q);
}
