//linklist3m.cpp
#include<iostream.h>
#include"linklist3.cpp"
void ff(int &a)//用于遍历的函数
{cout<<a<<",";}
void main()
{cout<<"linklist3m.cpp运行结果:\n";
 int init_size,xu;
 cout<<"\n首先请构造单链表list1";
 cout<<"\n初始化长度(1--30):";
 cin>>init_size;
 cout<<"是否排序:(=0不排序,=1升序,=-1降序):";
 cin>>xu;
 //构造单链表list1调用二个形参构造函数
 LinkList list1(init_size,xu);
 cout<<"\n单链表list1构造成功!"<<"\n它是:";
 list1.TraverseList(ff);
 cout<<"\n它为空吗?(1:是;0:不是):"<<list1.ListEmpty();
 cout<<"\n长度为:"<<list1.ListSize() ;
 int i;
 cout<<"\n请输入你想得到第几个元素的值(1--"<<init_size<<"):";
 cin>>i;
 cout<<"单链表list1中第"<<i<<"的值是"<<list1.GetElem(i);
 int it;
 cout<<"\n请输入你想删除第几个元素的值(1--"<<init_size<<"):";
 cin>>i;
 list1.DeleteList(it,i);
 cout<<"\n单链表list1删除第"<<i<<"个元素"<<"\'"<<it<<"\'"<<"后变为:";
 list1.TraverseList(ff); //对单链表list1每个数进行遍历.
 int news,olds;
 cout<<"\n请输入要被修改的元素:"; cin>>olds;
 cout<<"请输入修改后要变成的元素:"; cin>>news;
 list1.UpdateList(olds,news);
 cout<<"\n修改后单链表list1变为";
 list1.TraverseList(ff);
 cout<<"\n下面请构造单链表list2";
 cout<<"\n请输入单链表list2初始化长度(1--30):";
 cin>>init_size;
 cout<<"请选择是否排序:(=0不排序,=1 升序,=-1 降序):";
 cin>>xu;
 //构造单链表list2调用二个形参构造函数
 LinkList list2(init_size,xu);
 cout<<"\n单链表list2为:";
 list2.TraverseList(ff);
 LinkList list3;//构造单链表list3 调用一个形参构造函数
 list1.pailie(); //对单链表进行升序排列
 list2.pailie(); //对单链表进行升序排列
 list3.MergeList_L(list1,list2);//联合list1和list2
 cout<<"\nlist1和list2联合之后为list3:\n";
 list3.TraverseList(ff);
 cout<<"\n这时它为空吗?(1:是;0:不是):"<<list3.ListEmpty();
 cout<<"\n长度为:"<<list3.ListSize() ;
 list3.ClearList();//清空单链表list3
 cout<<"\n清空单链表list3\n";
 cout<<"\n按回车键结束...";
 cin.get();cin.get();}

