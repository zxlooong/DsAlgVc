//线索二叉树类相关操作的测试TBSTree2M.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<conio.h>
#include "TBSTree2.h"
#include "ITBSTree2.h"
void main()
{cout<<"TBSTree2M.cpp运行结果:\n";
 THNode<char> *q,*p;
 q=MakeCharT(q,2);
 ITBSTree<char> t(q);
 t.CreatInThread();
 cout<<"二叉树的中序正向遍历序列为:\n";
 t.First();
 cout<<"\n二叉树的中序反向遍历序列为:\n";
 t.Last();
 p=MakeCharT(p,1);
 ITBSTree<char> d(p);
 d.CreatInThread();
 cout<<"\n二叉树的中序正向遍历序列为:\n";
 d.First();
 cout<<"\n二叉树的中序反向遍历序列为:\n";
 d.Last();
 getch();
}










