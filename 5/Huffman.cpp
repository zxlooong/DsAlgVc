//Huffman.cpp
//赫夫曼树与赫夫曼编码
#include<iostream.h>
#include<iomanip.h>
const int MaxV=1000;//初始设定的最大权值
const int MaxBit=10;//初始设定的最大编码位数
const int MaxN=10;//初始设定的最大结点数
//赫夫曼树的结点结构
typedef struct
  {int weight;//权值
   int flag;  //标记
   int parent;//双亲结点下标
   int left;//左孩子下标
   int right;//右孩子下标
  }HuffNode;
  typedef struct
  {int bit[MaxN];//存放编码数组
   int start;//编码的起始下标
   int weight;//字符的权值
  }Code;
//类定义
class HuffmanT
{public:
  //构造函数
  HuffmanT(HuffNode *&,Code *&,int);
  //创建叶结点个数为n,权值数组为weight的赫夫曼树HuffTree
  void MakeHufm(int weight[],int n);
  //由n个结点的赫夫曼树HuffTree构造赫夫曼编码huffCode
  void HuffCode(int n);
 private:
  HuffNode *HuffTree;
  Code *huffCode;
};
HuffmanT::HuffmanT(HuffNode *&huffnode,Code *&huCode,int n)
{huffnode=new HuffNode[2*n+1];
 huCode=new Code[n];
 HuffTree=huffnode;
 huffCode=huCode;
}
void HuffmanT::MakeHufm(int weight[],int n)
{int j,m1,m2,x1,x2,i;
 //赫夫曼树HuffTree的初始化
 for(i=0;i<2*n-1;i++)
 {if(i<n) HuffTree[i].weight=weight[i];
  else HuffTree[i].weight=0;
  HuffTree[i].parent=0;
  HuffTree[i].flag=0;
  HuffTree[i].left=-1;
  HuffTree[i].right=-1;
 }
 //构造赫夫曼树HuffTree的n-1个非叶结点
 for(i=0;i<n-1;i++)
 {m1=m2=MaxV;
  x1=x2=0;
  for(j=0;j<n+i;j++)
  {if(HuffTree[j].weight<m1&&HuffTree[j].flag==0)
    {m2=m1;
     x2=x1;
     m1=HuffTree[j].weight;
     x1=j;
    }
   else if(HuffTree[j].weight<m2&&HuffTree[j].flag==0)
    {m2=HuffTree[j].weight;
     x2=j;
    }
  }
  //将找出的两棵权值最小的子树合并为一棵子树
  HuffTree[x1].parent=n+i;
  HuffTree[x2].parent=n+i;
  HuffTree[x1].flag=1;
  HuffTree[x2].flag=1;
  HuffTree[n+i].weight=HuffTree[x1].weight+HuffTree[x2].weight;
  HuffTree[n+i].left=x1;
  HuffTree[n+i].right=x2;
 }
}
void HuffmanT::HuffCode(int n)
{Code *cd=new Code;
 int child,parent;
 //求n个叶结点的赫夫曼编码
 for(int i=0;i<n;i++)
 {cd->start=n-1;//不等长编码的最后一位为n-1
  cd->weight=HuffTree[i].weight;//取得编码对应权值的字符
  child=i;
  parent=HuffTree[child].parent;
  //由叶结点向上直到根结点
  while(parent!=0)
  {if(HuffTree[parent].left==child)
    cd->bit[cd->start]=0;//左孩子结点编码0
   else
    cd->bit[cd->start]=1;//右孩子结点编码1
   cd->start--;
   child=parent;
   parent=HuffTree[child].parent;
  }
  //保存每个叶结点的编码和不等长编码的起始位
  for(int j=cd->start+1;j<n;j++)
   huffCode[i].bit[j]=cd->bit[j];
  huffCode[i].start=cd->start;
  huffCode[i].weight=cd->weight;//记住编码对应权值的字符
 }
}
//赫夫曼编码问题的测试
void main()
{cout<<"Huffman.cpp运行结果:\n";
 int i,j,n=4;
 int weight[]={1,3,5,7};
 HuffNode *myHuffTree;
 Code *myHuffCode;
 HuffmanT t(myHuffTree,myHuffCode,n);
 if(n>MaxN)
 {cout<<"n越界,修改MaxN!\n";exit(1);}
 t.MakeHufm(weight,n);
 t.HuffCode(n);
 //输出每个叶结点的赫夫曼编码
 for(i=0;i<n;i++)
 {cout<<"weight="<<myHuffCode[i].weight<<"  Code=";
  for(j=myHuffCode[i].start+1;j<n;j++)
   cout<<myHuffCode[i].bit[j];
  cout<<endl;
 }
 cin.get();
}

