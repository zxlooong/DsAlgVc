//À≥–Ú’ªµƒ µœ÷stack2.cpp
#include "stack2.h"
SqStack::SqStack()
{ base=new SElemType[STACKSIZE *sizeof(SElemType)];
  if(!base) exit(OVERFLOW);
  top=base;
  stacksize=0;
}
Status SqStack::DestroyStack()
{delete base;return 1;}

Status SqStack::ClearStack()
{stacksize=0;return 1;}

bool SqStack::StackEmpty()
{ if(stacksize==0) return true;
  else return false;
}
int SqStack::StackLength()
{ return stacksize;}
SElemType SqStack::GetTop()
{ if(top==base)
   {cerr<<"ø’’ª!\n";exit(1);}
  return *(top-1);
}
Status SqStack::Push(SElemType e)
{ *(top++)=e;stacksize++;
  return 1;
}
SElemType SqStack::Pop(SElemType *e)
{ if(top==base)
   {cerr<<"ø’’ª!\n";exit(1);}
  *e=*--top;
  stacksize--;
  return *e;
}
void SqStack::StackTraverse(void (*visit)(SElemType *))
{while(top!=base){
   stacksize--;visit(--top);}}
