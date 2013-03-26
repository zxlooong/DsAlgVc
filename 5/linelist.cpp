//线性表的操作linelist.cpp
#include "linelist.h"
List::List(List *L)
{L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
 if(!L->elem) exit(OVERFLOW);
 L->length=0;
 L->listsize=LIST_INIT_SIZE;
}
int List::ListLength()
{return length;}
ElemType List::GetElem(int i,ElemType *e)
{*e=elem[i];return *e;}
bool List::ListInsert(int i,ElemType e)
{ ElemType *p,*q;
  if (i<0||i>length) return false;
  q=&elem[i];
  for(p=&elem[length];p>=q;--p)
    *(p+1)=*p;
  *q=e;
  ++length;
  return true;
}


