//稀疏矩阵的类定义与操作xishu.h
//假设非0元个数的最大值为100
#define MAXSIZE 100
//三元组顺序表
class TSMatrix;
class Triple
{public:
  int ii,jj;//行号和列号
  ElemType e;
  friend class TSMatrix;
};
class TSMatrix
{public:
   //构造函数
   TSMatrix( ) {}
  //构造函数
  //创建一个Mrow行,Mcol列且非零元个数为t的稀疏矩阵
  TSMatrix(int Mrow,int Mcol,int t);
  //求稀疏矩阵的转置矩阵
  void TrMatrix(TSMatrix &);
  //快速转置
  void FastTrMatrix(TSMatrix &);
  //稀疏矩阵相乘
  void mulmatrix(TSMatrix &,TSMatrix &);
  Triple data[MAXSIZE];//非0三元组表
  int mu,nu,tu;//稀疏矩阵的行数、列数和非零元个数
};
//创建一个Mrow行,Mcol列且非零元个数为t的稀疏矩阵
TSMatrix::TSMatrix(int Mrow,int Mcol,int t)
{ int m,n,i,j,f0=0;
  if(t<=0) exit(0);
  ElemType (*A)[MCOL]=new ElemType[MROW][MCOL];
  if(!A){cerr<<"内存分配失败!\n";exit(-1);}
  for(i=0;i<Mrow;i++)
   for(j=0;j<Mcol;j++) A[i][j]=0;
  while(f0<=t)
   {m=random(11);
    n=random(7);
    if(m>=0&&m<Mrow&&n>=0&&n<Mcol)
     {A[m][n]=random(6);
      if(A[m][n]!=0) f0++;
   }}
 for(i=0;i<Mrow;i++)
 {for(j=0;j<Mcol;j++)
   cout<<setw(3)<<A[i][j];
  cout<<endl;}
}
//求稀疏矩阵的转置矩阵
void TSMatrix::TrMatrix(TSMatrix &T)
{int p,q,col;
 T.mu=nu;T.nu=mu;T.tu=tu;
 if(T.tu){ //如果T的非0元个数不为0
  q=0;
  for(col=0;col<nu;++col)
   for(p=0;p<tu;++p)
     if(data[p].jj==col){
       T.data[q].ii = data[p].jj;
       T.data[q].jj = data[p].ii;
       T.data[q].e = data[p].e;
       ++q;}}
}
//快速转置
void TSMatrix::FastTrMatrix(TSMatrix &T)
{int col,p,q,t,num[N],cpot[N];
 T.mu=nu;T.nu=mu;T.tu=tu;
 if(T.tu){
  for(col=0;col<nu;++col)  num[col] = 0;
    //先置M每列非0元个数均为0
  for(t=0;t<tu;++t)  ++num[data[t].jj];
    //求M中每一列非0元个数
  cpot[0]=0; //M中第一列第一个非元在T中的序号为1
  for(col=1;col<nu;++col)
    cpot[col]=cpot[col-1]+num[col-1];
    //求M中第col列中第一个非0元在T中的序号
  for(p=0;p<tu;++p){
   col=data[p].jj; //记下M中第p个元素的列号
   q=cpot[col];     //该列中第一个非0元在T中的序号
   T.data[q].ii=data[p].jj;
   T.data[q].jj=data[p].ii;
   T.data[q].e=data[p].e;//行、列交换,并赋值
   ++cpot[col];}} //该列下一个非0元序号=上一个序号+1
}
//稀疏矩阵相乘
void TSMatrix:: mulmatrix(TSMatrix &b,TSMatrix &c)
{int i,colB,colA,rowA;
 if(nu!=b.mu){
   cerr<<"error\n"; exit(0);}
 if(tu*b.tu!=0){
  int *rowSize=new int[b.mu];
  int *rowStart=new int[b.mu+1];
  ElemType *temp=new ElemType[b.nu];
  for(i=0;i<b.mu;i++) rowSize[i]=0;
  for(i=0;i<b.tu;i++) rowSize[b.data[i].ii]++;
  rowStart[0]=0;
  for(i=1;i<=b.mu;i++) rowStart[i]=rowStart[i-1]+rowSize[i-1];
  int current=0,lastInresult=-1;
  while(current<tu)
  {rowA=data[current].ii;
   for(i=0;i<b.nu;i++) temp[i]=0;
   while(current<tu&&data[current].ii==rowA)
   {colA=data[current].jj;
    for(i=rowStart[colA];i<rowStart[colA+1];i++)
    {colB=b.data[i].jj;
     temp[colB]+=data[current].e*b.data[i].e;}
     current++;}
     for(i=0;i<b.nu;i++)
     if(temp[i]!=0)
      {lastInresult++;
       c.data[lastInresult].ii=rowA;
       c.data[lastInresult].jj=i;
       c.data[lastInresult].e=temp[i];
      }
    }
 c.mu=mu;c.nu=b.nu;c.tu=lastInresult+1;
 delete []rowSize;delete []rowStart;delete []temp;
}}
