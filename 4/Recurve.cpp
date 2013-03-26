//递归运算(栈的应用)Recurve.cpp
#include <iostream.h>
#include <iomanip.h>
class list;
class listnode{
  friend class list;
  int data;
  listnode *link;
  listnode(int value,listnode *zz):data(value),link(zz)
   {}
};
class list{
  listnode *first;
  //累加和
  long sum(listnode *p);
  //计数器
  long count(listnode *p);
public:
  list():first(NULL){}
  //生成栈
  void add(int value);
  //显示栈中数据
  void display();
  //获取累加和
  long get_sum(){return sum(first);}
  //获取数据个数
  long get_count(){return count(first);}
  //求平均
  float get_avg()
  {return (float)sum(first)/count(first);}
};
void list::add(int value){
  listnode *p=new listnode(value,first);
  if(p!=NULL) first=p;
  else cerr <<"Memory Error!" <<endl;
}
void list::display(){
  cout<<"数据域的各个值:";
  for(listnode *p=first;p!=NULL;p=p->link)
    cout<<setw(2)<<p->data;
  cout <<endl;
}
long list::sum(listnode *p){
  if(p->link==NULL) return p->data;
  else return p->data+sum(p->link);
}
long list::count(listnode *p){
  long n=1;
  if(p->link==NULL){return 1;}
  else{return count(p->link)+n;}
}
void main()
{cout<<"Recurve.cpp运行结果:\n";
 list a;
 a.add(1);
 a.add(2);
 a.add(3);
 a.add(4);
 a.display();
 cout<<"累加和sum="<<a.get_sum()<<endl;
 cout<<"数据个数count="<<a.get_count()<<endl;
 cout<<"平均值avg="<<a.get_avg()<<endl;
 cin.get();}

