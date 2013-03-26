//单行编辑LINEEDIT.CPP
#include<iostream.h>
#include<iomanip.h>
#include<malloc.h>
#include<conio.h>
#define EOFILE '`'
typedef char Status;
typedef char SElemType;
#include "stack.cpp"
void LineEdit()
{ SqStack *S,*T;
  char str[1000];
  int strlen=0;
  char e;
  char ch;
  S->InitStack(&S);
  T->InitStack(&T);
  ch=getchar();
  while(ch!=EOFILE)
   {while(ch!=EOFILE&&ch!='\n')
     { switch(ch){
	case '#':
	  S->Pop(&ch);
	  break;
	case '@':
	  S->ClearStack();
	  break;
	default:
	  S->Push(ch);
          break;}
       ch=getchar();
     }
    if(ch=='\n') S->Push(ch);
      while(!S->StackEmpty())
       {S->Pop(&e);
        T->Push(e);}
      while(!T->StackEmpty())
       { T->Pop(&e);
         str[strlen++]=e;}
    if(ch!=EOFILE) ch=getchar();
   }
  cout<<"输出编辑后字符串:\n";
  str[strlen]='\0';
  cout<<'\n'<<str;
  S->DestroyStack();
  T->DestroyStack();
}
void main()
{cout<<"LINEEDIT.CPP运行结果:\n";
 cout<<"输入字符串,以输入字符`作为结束:\n";
 LineEdit();
 getch();}
