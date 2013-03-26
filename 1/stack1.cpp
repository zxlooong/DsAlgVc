//顺序栈的实现stack1.cpp
//#include "stack1.h"
void Stack::SetStack(int n)
{data=new DataType[n];
 if(data==NULL)
  {cout<<"overflow!\n";exit(1);}
 maxSize=n;
 top=-1;
}
void Stack::FreeStack()
{free(data);}

int Stack::StackSize()
{return(top+1);}

bool Stack::StackEmpty()
{if(top==-1) return true;
 return false;
}
bool Stack::StackFull()
{if(top==maxSize-1) return true;
 return false;
}
DataType Stack::Peek()
{if(top==-1)
  {cerr<<"栈已空!\n";exit(1);exit(1);}
 return(data[top]);
}
void Stack::Push(DataType item)
{if(top==maxSize-1)
  {cerr<<"栈已满!\n";;exit(1);}
 top++;
 data[top]=item;
}
DataType Stack::Pop(DataType e)
{if(top==-1)
  {cerr<<"栈已空!\n";exit(1);}
 top--;
 return data[top+1];
}
void Stack::ClearStack()
{top=-1;}

void Stack::StackTraverse(void (*visit)(DataType *))
{while(top!=-1){
   visit(data);top--;}
}


