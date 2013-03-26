//十字链表的类定义与相关操作xishuM2.cpp
#include<iostream.h>
#include<iomanip.h>
typedef int ElemType;
class CrossList;
class OLNode //十字链表
{public:
  int ii,jj; //非0元的行和列下标
  ElemType e;
  //该非0元所在的行表和列表的后继链域
  OLNode *right,*down;
  friend class CrossList;
};
typedef class OLNode *OLink;
class CrossList
{public:
  OLink *rHead,*cHead; //行指针和列指针
  int mu,nu,tu; //稀疏矩阵的行数、列数和非0元个数
  //创建稀疏矩阵,用十字链表存储表示
  void CreateOLSMatrix();
};
void CrossList::CreateOLSMatrix()
{int m,n,t,i,j,e,k,s;
 OLink p,q,w;
 cout<<"输入矩阵的行数、列数和非0元个数:";
 cin>>m>>n>>t;
 mu=m;nu=n;tu=t;
 s=m>n?m:n;
 rHead=new OLink[s];if(!rHead) exit(-1);
 cHead=new OLink[s];if(!cHead) exit(-1);
 for(int k=0;k<s;k++)
  rHead[k]=cHead[k]=NULL; //初始化行列头指针指向空链表
 cout<<"按任意次序输入M的行、列和非0元:\n";
 for(cin>>i>>j>>e;i!=-1;cin>>i>>j>>e)
  {p=new OLNode;if(!p) exit(-1);
   p->ii=i;p->jj=j;p->e=e; //生成结点
   p->right=NULL;p->down=NULL;
   if(rHead[i]==NULL) rHead[i]=p;
   else{  //寻找在行表中的插入位置
     for(q=rHead[i];(q->right)&&(q->right->jj<j);q=q->right)
       p->right=q->right;
     q->right=p; }//完成插入
   if(cHead[j]==NULL) cHead[j]=p;
   else{  //寻找在列表中的插入位置
     for(q=cHead[j];(q->down)&&(q->down->ii<i);q=q->down)
       p->down=q->down;
     q->down=p;}//完成插入
  }
 cout<<"按行输出矩阵元素:\n";
 cout<<"行数="<<mu<<"  列数="<<nu<<endl;
 cout<<"  i  j  e\n";
 for(i=0,p=rHead[0];i<tu;p=rHead[++i])
 {q=p;
  while(!(q==NULL))
  {cout<<setw(3)<<q->ii;
   cout<<setw(3)<<q->jj;
   cout<<setw(3)<<q->e<<endl;
   q=q->right;
 }}
}
//十字链表相关操作的测试
void main()
{cout<<"xishuM2.cpp运行结果:\n";
 CrossList dd;
 dd.CreateOLSMatrix();
 cin.get();cin.get();}
