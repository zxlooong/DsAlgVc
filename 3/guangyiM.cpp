//广义表的相关操作的测试guangyiM.cpp
#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include "guangyi.h"
#include "guangyi.cpp"
static GList *GL,*GL1,*GL2,*GL3;
static GList GU,GU1,GU2,GU3,GU4;
void main()
{cout<<"guangyiM.cpp运行结果:\n";
 char *a="(A,(B),(3,5,7),(a,b),((C)),D)";
 char *b="(A,(B),(3,5),(a,b),7)";
 char *c="(9,(B),(3,5),(a,b))";
 GU3.utype=INTGR;GU3.intinfo=9;
 GU3.first=GL2;
 GL=GU.CreateGList(a);
 cout<<"返回的指针值GL="<<GL<<endl;
 cout<<"创建后的广义表=";
 GU.prtGlist(GL);
 cout<<"\n广义表GL的深度="<<GU.depth(GL);
 GL=GU.delvalue(GL,5);
 cout<<"\n删除5后的广义表GL=";GU.prtGlist(GL);
 GL=GU.delvalue(GL,'a');
 cout<<"\n删除a后的广义表GL=";GU.prtGlist(GL);
 cout<<"\n将GU3定义为由ls指示的广义表的尾:";
 GU.setTail(GL,GU3);GU.prtGlist(GL);
 cout<<"\n重置广义表的头元素后的广义表:";
 GU.setHead(GL,GU3);GU.prtGlist(GL);
 GL1=GU.Copy(GL);
 cout<<"\n复制后的广义表GL1=";
 GU.prtGlist(GL1);
 cout<<"\n广义表GU的第一个元素的值:\n";
 GU2=GU.Head(GL1);
 cout<<"GU2.utype="<<GU2.utype;
 if(GU2.utype==INTGR)
  cout<<",GU2.intinfo="<<GU2.intinfo<<endl;
 if(GU2.utype==CH)
  cout<<",GU2.charinfo="<<GU2.charinfo<<endl;
 GU=GU.Info(GL1);
 cout<<"广义表GU的第一个元素的值:\n";
 cout<<"GU.utype="<<GU.utype;
 if(GL1->utype==INTGR)
  cout<<",GU.intinfo="<<GU.intinfo<<endl;
 if(GL1->utype==CH)
  cout<<",GU.charinfo="<<GU.charinfo<<endl;
 GL2=GU1.CreateGList(b);
 if(GU.operator ==(GU1)) cout<<"广义表GU与GU1相等!\n";
 else cout<<"广义表GU与GU1不等!\n";
 cout<<"修改广义表GU1的表头后的广义表:";
 GL2=GU1.InsertGL(GL2,GU3);
 GU1.prtGlist(GL2);
 GU1=*GL2;
 cout<<"\n广义表GU1除第一个元素以外其它元素组成的表:";
 GL2=GU1.Tail();cout<<'(';
 GU1.prtGlist(GL2);cout<<endl;
 GL3=GU4.CreateGList(c);
 cout<<"创建后的广义表=";
 GU4.prtGlist(GL3);
 cout<<"\n以GU3为头,由GL3指示的广义表为尾的新表:";
 GU3.utype=CH;GU3.charinfo='F';
 GU3.first=NULL;
 GL3=GU4.Addon(GL3,GU3);cout<<'(';
 GU4.prtGlist(GL3);cout<<')';
 getch();
}








 