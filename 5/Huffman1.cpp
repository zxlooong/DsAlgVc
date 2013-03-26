//赫夫曼树与赫夫曼编码
//Huffman1.cpp
#include<iostream.h>
#include<iomanip.h>
const int MaxV=100;//初始设定的最大权值
const int MaxBit=15;//初始设定的最大编码位数
const int MaxN=15;//初始设定的最大结点数
//赫夫曼树的结点结构
typedef struct
  {int weight;//权值
   int parent;//双亲结点下标
   int left;//左孩子下标
   int right;//右孩子下标
  }HTNode,*HuffmanTree;
typedef char **HuffmanCode;
//创建权值数组为w的赫夫曼树HT,并求出n个字符的赫夫曼编码HC
void MakeHufm(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{int m,m1,m2,x1,x2,i,j,start,c,f;
 HuffmanTree p;
 //赫夫曼树HuffTree的初始化
 if(n<=1) return;
 m=2*n-1;
 HT=(HuffmanTree)malloc((2*n)*sizeof(HTNode));
 for(p=HT,i=0;i<n;++i,++p,++w)
  {p->weight=*w;p->parent=0;
   p->left=0;p->right=0;}
 for(;i<m;++i,++p)
  {p->weight=0;p->parent=0;
   p->left=0;p->right=0;}
 for(i=n;i<m;++i)//建赫夫曼树
 {m1=m1=MaxV;
  x1=x2=0;
  for(j=0;j<i;j++)
  {if(HT[j].weight<m1&&HT[j].parent==0)
    {m2=m1;
     x2=x1;
     m1=HT[j].weight;
     x1=j;
    }
   else if(HT[j].weight<m2&&HT[j].parent==0)
    {m2=HT[j].weight;
     x2=j;
    }
  }
  //将找出的两棵权值最小的子树合并为一棵子树
  HT[x1].parent=i;HT[x2].parent=i;
  HT[i].left=x1;HT[i].right=x2;
  HT[i].weight=HT[x1].weight+HT[x2].weight;
 }
 //从叶子到根逆向求每个字符的赫夫曼编码
 HC=(HuffmanCode)malloc((n+1)*sizeof(char *));//头指针
 //分配求编码的工作空间
 char *cd=(char *)malloc(n*sizeof(char));
 cd[n-1]='\0';//编码结束符
 for(i=0;i<=n;++i)//逐个字符求赫夫曼编码
 {start=n-1;//编码结束符位置
  //从叶子到根逆向求编码
  for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
   if(HT[f].left==c) cd[--start]='0';
   else cd[--start]='1';
  //为第i个字符编码分配空间
  HC[i]=(char *)malloc((n-start)*sizeof(char));
  strcpy(HC[i],&cd[start]);//复制编码
 }
 free(cd);  
}
//赫夫曼编码问题的测试
void main()
{cout<<"Huffman1.cpp运行结果:\n";
 int i,j,n=4,q[4]={1,3,5,7};
 HuffmanTree ht;
 char **hc;
 MakeHufm(ht,hc,q,n);
 //输出每个叶结点的赫夫曼编码
 for(i=0;i<n;i++)
 {cout<<"weight="<<ht[i].weight;
  cout<<"  Code="<<hc[i]<<'\n';
 }
 cin.get();
}

