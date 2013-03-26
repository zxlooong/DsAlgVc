//广义表的类定义guangyi.h
#include<string.h>
#include<stdio.h>
#include<math.h>
typedef enum{INTGR,CH,LST}ElemTag;
class GList
{public:
  ElemTag utype;
  GList *first;
  union
  { int intinfo;
    char charinfo;
    GList *hlink;
  };
//构造函数
  GList(){}
//返回由elem指示的表元素的值
  GList &Info(GList *&elem);
//返回表元素elem的元素值的数据类型
  int nodetype(GList *elem) {return elem->utype;}
//将由elem指示的表元素的值修改为x
  GList &setInfo(GList *&elem,GList &x);
//判断广义表是否相等的重载函数
  int operator ==(GList &m);
//判断广义表是否相等
  int equal(GList *s,GList *t);
//返回由ls指示的广义表的第一个元素的值
  GList &Head(GList *&ls);
//返回广义表除第一个元素以外其它元素组成的表
  GList *Tail();
//返回广义表的第一个元素
  GList *First();
//返回由elem指示的表元素的直接后继元素
  GList *Next(GList *elem);
//返回一个以x为头,由ls指示的广义表为尾的新表
  GList *Addon(GList *ls,GList &x);
//由ls指示的广义表的复制
  GList *Copy(GList *ls);  
//求由ls指示的非递归表的深度
  int depth(GList *&ls);
//判断广义表是否为空
  bool GlistEmpty() {return first==NULL;}
//将广义表的头元素重置为x
  void setHead(GList *&ls,GList &x);
//将elem2插到表中元素elem1后
  void setNext(GList *elem1,GList *elem2);
//将x定义为由ls指示的广义表的尾
  void setTail(GList *&ls,GList &x);
//插入元素x作为由ls指示的广义表的第一元素
  GList *InsertGL(GList *&ls,GList &x);
//删除广义表中含数x或结点x的操作
  GList *delvalue(GList *&ls,int x);
//删除广义表中含数x或结点x的操作
  GList *delvalue(GList *&ls,char x);
//S是广义表的书写形式串,由S创建广义表GL
  GList *CreateGList(char *&s);
//建立广义表时调用的过程
  int sever(char *&str1,char *&hstr1);
//广义表的输出
  void prtGlist(GList *h);
};
