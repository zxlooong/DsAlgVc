//Ë³ÐòÕ»µÄÊµÏÖstack.cpp
#include "stack.h"
Status SqStack::InitStack(SqStack **S)
{ (*S)=(SqStack *) malloc(sizeof(SqStack));
  (*S)->base=(SElemType *)malloc(STACKSIZE *sizeof(SElemType));
  if(!(*S)->base)exit(OVERFLOW);
  (*S)->top=(*S)->base;
  (*S)->stacksize=0;
  return 1;}

Status SqStack::DestroyStack()
{free(base);return 1;}

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
   {cerr<<"¿ÕÕ»!\n";exit(1);}
  return *(top-1);
}
Status SqStack::Push(SElemType e)
{ *(top++)=e;stacksize++;
  return 1;
}
SElemType SqStack::Pop(SElemType *e)
{ if(top==base)
   {cerr<<"¿ÕÕ»!\n";exit(1);}
  *e=*--top;
  stacksize--;
  return *e;
}
void SqStack::StackTraverse(void (*visit)(SElemType *))
{while(top!=base){
   stacksize--;visit(--top);}}


