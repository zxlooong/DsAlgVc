//二叉搜索树相关操作的测试BSTreeM.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include "BSTree.h"
#include "BSTree.cpp"
void main()
{cout<<"BSTreeM.cpp运行结果:\n";
 char b[50]="abxycdMNefgzkl";
 BSTree<char> t,*B;
 int n,m=14;
 t.InitBSTree(B);
 t.CreateBSTree(B,b,m);
 n=t.BSTreeCount(B);
 cout<<"二叉搜索树的所有结点数="<<n<<endl;
 if(!t.BSTreeEmpty(B))
   cout<<"二叉搜索树非空!\n";
 else
   cout<<"二叉搜索树为空!\n";
 cout<<"中序遍历二叉搜索树:\n";
 t.Inorder(B);cout<<endl;
 n=t.BSTreeDepth(B);
 cout<<"二叉搜索树的深度="<<n<<endl;
 n=t.BSTreeLeafCount(B);
 cout<<"二叉搜索树的所有叶子结点数="<<n<<endl;
 cout<<"按二叉搜索树的广义表输出二叉搜索树:\n";
 t.PrintBSTree(B);cout<<endl;
 if(t.Find(B,'d')) cout<<"查找成功!\n";
 else cout<<"查找不成功!\n";
 if(t.Update(B,'d','D')) cout<<"更新成功!\n";
 else cout<<"更新不成功!\n";
 cout<<"中序遍历二叉搜索树:\n";
 t.Inorder(B);cout<<endl;
 t.Insert(B,'m');
 cout<<"中序遍历二叉搜索树:\n";
 t.Inorder(B);cout<<endl;
 t.Insert(B,'n');
 cout<<"中序遍历二叉搜索树:\n";
 t.Inorder(B);cout<<endl;
 n=t.BSTreeDepth(B);
 cout<<"二叉搜索树的深度="<<n<<endl;
 if(t.Delete(B,'e')) cout<<"删除成功!\n";
 else cout<<"删除不成功!\n";
 cout<<"中序遍历二叉搜索树:\n";
 t.Inorder(B);cout<<endl;
 n=t.BSTreeDepth(B);
 cout<<"二叉搜索树的深度="<<n<<endl;
 cin.get();}



