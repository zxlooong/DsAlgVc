//线性表的类定义linelist.h
#ifndef LLIST
#define LLIST
#include<stdlib.h>
#define OVERFLOW -1
#define LIST_INIT_SIZE 30
#define LISTINCREMENT 10
typedef char ElemType;
//线性表的动态分配顺序存储结构
class List{
 private:
 ElemType *elem;//存储空间基址
 int length;   //当前长度
 int listsize;
//当前分配的存储容量以一数据元素存储长度为单位
 public:
  //无参构造函数
  List(){}
  //初始化顺序表
  List(List *);
  //删除顺序表
  void DestroyList(List &L) {free(&L);}
  //将顺序表置为空表
  void ClearList() {length=0;}
  //判断顺序表是否为空表
  bool ListEmpty()
  {if(length==0) return true;
   else return false;}
   //判断顺序表是否为满
  bool ListFull()
   {return length==listsize;}
  //返回顺序表的长度
  int ListLength();
  // 获取顺序表中第i 个元素
   ElemType GetElem(int,ElemType *);
  //顺序表的插入算法
  bool ListInsert(int,ElemType);
};
#endif

