//拓扑排序topSort.cpp
#include<iostream.h>
#include<iomanip.h>
typedef struct
{char w1,w2;
 float w;
}RCW;
#include"graph4.h"
typedef struct
{int *data;
 int max,top;
}Stack;
void TopSort(Graph *G)
{int i,j,n,d,count=0,*D;
 Stack S;
 if(G->size==0) return;
 n=G->size;
 S.data=new int[n];
 S.max=n;S.top=-1;
 D=new int[n];
 for(j=0;j<n;j++)
  {d=0;
   for(i=0;i<n;i++)
    if(G->edge[i][j]!=0) d++;
    D[j]=d;
    if(d==0)
     {if(S.top==S.max-1)
       {cout<<"Stack is full!\n";exit(1);}
      S.top++;
      S.data[S.top]=j;
     }
  }
 while(!(S.top==-1))
 {if(S.top==-1)
    {cout<<"Pop an empty stack!\n";exit(1);}
  S.top--;
  i=S.data[S.top+1];
  cout<<G->data[i]<<' ';
  count++;
  for(j=0;j<n;j++)
  if(G->edge[i][j]!=0)
  {D[j]--;
   if(D[j]==0)
    {if(S.top==S.max-1)
       {cout<<"Stack is full!\n";exit(1);}
      S.top++;
      S.data[S.top]=j;
 }}}
 if(count<n)
  cout<<"\nThere is a cycle.";
 free(D);
 free(S.data);
}
void main()
{cout<<"topSort.cpp运行结果:\n";
 Graph G;int n=6,e=8;//n为顶点数,e为边数
 RCW rcw[8]={{'a','b',1},{'a','d',1},{'a','e',1},{'b','f',1},
             {'c','b',1},{'c','f',1},{'e','d',1},{'e','f',1}};
 SetGraph(&G,n);
 MakeGraph(&G,rcw,n,e);
 TopSort(&G);
 free(G.data);//释放空间
 free(G.visited);
 for(int i=0;i<G.max;i++) free(G.edge[i]);
 free(G.edge);cin.get();}













            

