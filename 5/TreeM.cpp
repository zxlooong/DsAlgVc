//树类相关操作的测试TreeM.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<conio.h>
#include "Tree.h"
#include "Tree.cpp"
void main()
{cout<<"TreeM.cpp运行结果:\n";
 int i;
 Tree<char> t;
 t.InsertChild('A');
 for(i=0;i<7;i++)
 {t.Root();
  if(i>=3&&i<5) t.FirstChild();
  t.InsertChild('B'+i);
 }
 cout<<"按后根遍历显示的结点次序为:\n";
 t.DisplayTree1();
 int k;
 cout<<"\n输入欲删除第几个结点(k):";cin>>k;
 if(t.DeleteChild1(k))
   cout<<"\n第"<<k<<"个孩子结点,删除成功!\n";
 else cout<<"\n第"<<k<<"个孩子结点,删除失败!\n";
 cout<<"按先根遍历显示的结点次序为:\n";
 t.DisplayTree();
 getch();
 cout<<endl<<"析构函数按后根遍历释放结点的次序为:\n";
}



