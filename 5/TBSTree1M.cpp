//线索二叉树类相关操作的测试TBSTree1M.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<conio.h>
#include "TBSTree1.h"

void main()
{cout<<"TBSTree1M.cpp运行结果:\n";
 THNode<char> *q,*p;
 TBSTree<char> t;
 q=t.MakeCharT(q,2);
 cout<<"线索二叉树的中序正向遍历序列为:\n";
 t.InThread(q);
 t.ThInorder(q);
 TBSTree<char> d;
 p=d.MakeCharT(p,1);
 cout<<"\n线索二叉树的中序正向遍历序列为:\n";
 d.InThread(p);
 d.ThInorder(p);
 getch();
}










