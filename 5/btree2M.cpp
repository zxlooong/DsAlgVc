//二叉树类相关操作的测试btree2M.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<strstrea.h>
#include "btree2.h"
#include "btree2.cpp"

void main()
{cout<<"btree2M.cpp运行结果:\n";
 int n;
 char b[80]="(a)(b),c(d),e(f),g(h),i(j),k(l),m(n),o@";
 BinaryTree<char> B;
 cout<<"创建的二叉树为:\n";
 B.CreateBTree(b);cout<<endl;
 if(!B.BTreeEmpty())
   cout<<"二叉树非空!\n";
 else
   cout<<"二叉树为空!\n";
 cout<<"先序遍历二叉树:\n";
 B.TraverseBTree(1);cout<<endl;
 cout<<"中序遍历二叉树:\n";
 B.TraverseBTree(2);cout<<endl;
 cout<<"后序遍历二叉树:\n";
 B.TraverseBTree(3);cout<<endl;
 cout<<"按层遍历二叉树:\n";
 B.TraverseBTree(4);cout<<endl;
 n=B.BTreeDepth();
 cout<<"二叉树的深度="<<n<<endl;
 n=B.BTreeCount();
 cout<<"二叉树的所有结点数="<<n<<endl;
 n=B.BTreeLeafCount();
 cout<<"二叉树的所有叶子结点数="<<n<<endl;
 cout<<"按二叉树的广义表输出:\n";
 B.PrintBTree();cout<<endl;
 cin.get();}



