//二叉搜索树的类型测试BSTree1M.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<conio.h>
#include "BSTree1.h"
TNode<char> *q;
void main()
{cout<<"BSTree1M.cpp运行结果:\n";
 int i;
 char test[50]="abxycdMNefgzkl";
 BSTree<char> t(q);
 //cout<<"input data:\n";
 //gets(test);
 for(i=0;test[i]!='\0';i++)
  t.BSTInsert(q,test[i]);
 cout<<"中序遍历二叉搜索树:\n";
 t.Inorder(q);
 cout<<"\n二叉搜索树的结点数="<<t.BSTSize()<<endl;
 cout<<"二叉搜索树的结点数="<<t.BSTreeCount(q)<<endl;
 cout<<"二叉搜索树的深度="<<t.BSTreeDepth(q)<<endl;
 cout<<"二叉搜索树的叶子结点数="<<t.BSTreeLeafCount(q)<<endl;
 cout<<"Press any key and delete 'd'\n";
 getch();
 t.BSTDelete(q,'d');
 cout<<"中序遍历二叉搜索树:\n";
 t.Inorder(q);
 cout<<"\n二叉搜索树的结点数="<<t.BSTSize()<<endl;
 cout<<"二叉搜索树的结点数="<<t.BSTreeCount(q)<<endl;
 cout<<"二叉搜索树的深度="<<t.BSTreeDepth(q)<<endl;
 cout<<"二叉搜索树的叶子结点数="<<t.BSTreeLeafCount(q)<<endl;
 getch();
 t.FreeBST(q);
}

