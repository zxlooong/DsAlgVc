//稀疏矩阵相关操作的测试xishuM.cpp
#include<conio.h>
#include<iostream.h>
#include<iomanip.h>

typedef int ElemType;
#define L 6
#define N 7
const int MROW=3;
const int MCOL=4;
#include "xishu.h"
//三元组顺序表的输出
void print(TSMatrix a)
{cout<<"   i   j   e\n";
 for(int k=0;k<a.tu;k++)
  {cout<<setw(4)<<a.data[k].ii;
   cout<<setw(4)<<a.data[k].jj;
   cout<<setw(4)<<a.data[k].e<<endl;}
}
void  main()
{cout<<"xishuM.cpp运行结果:\n";
 int b[N][L],i,j,k=0;
 int a[L][N]={0,12,9,0,0,0,0,0,0,0,0,0,0,0,-3,0,0,0,0,14,0,
    0,0,24,0,0,0,0,0,18,0,0,0,0,0,15,0,0,-7,0,0,0};
 TSMatrix a1,b1,c1;
 a1.mu=L;a1.nu=N;a1.tu=0;
 cout<<"稀疏矩阵a1:\n";
 for(i=0;i<L;i++)//输出数组a1
  {for(j=0;j<N;j++)
    cout<<setw(3)<<a[i][j];
    cout<<'\n';}
 //创建三元组顺序表
 for (i=0;i<L;i++)
  for (j=0;j<N;j++)
   if (a[i][j]!=0)
    { a1.data[k].ii=i;
      a1.data[k].jj=j;
      a1.data[k].e=a[i][j];
      a1.tu++;k++;}
 cout<<"原三元组顺序表a1:\n";
 print(a1);
 cout<<"按任意键继续...\n";getch();
 a1.TrMatrix(c1);
 for (i=0;i<N;i++)//初始化数组
  for (j=0;j<L;j++) b[i][j]=0;
 for (k=0;k<c1.tu;k++)
   b[c1.data[k].ii][c1.data[k].jj]=c1.data[k].e;
 cout<<"转置矩阵 c1:\n";
 for (i=0;i<N;i++)
  { for (j=0;j<L;j++)
     cout<<setw(3)<<b[i][j];
    cout<<'\n';}
 cout<<"转置矩阵三元组顺序表:\n";
 print(c1);
 cout<<"按任意键继续...\n";getch();
 a1.FastTrMatrix(b1);
 for (i=0;i<N;i++)//initial array_b
  for (j=0;j<L;j++) b[i][j]=0;
 for (k=0;k<b1.tu;k++)
   b[b1.data[k].ii][b1.data[k].jj]=b1.data[k].e;
 cout<<"转置矩阵 b1:\n";
 for (i=0;i<N;i++)
  { for (j=0;j<L;j++)
     cout<<setw(3)<<b[i][j];
    cout<<'\n';}
 int p[3][4]={{10,0,5,7},{2,1,0,0},{3,0,4,0}};
 int w[4][2]={{2,0},{4,8},{0,14},{3,5}};
 TSMatrix aa,bb,cc;
 aa.mu=3;aa.nu=4;aa.tu=0;
 bb.mu=4;bb.nu=2;bb.tu=0;
 //创建三元组顺序表
 for (k=0,i=0;i<3;i++)
  for (j=0;j<4;j++)
   if (p[i][j]!=0)
    { aa.data[k].ii=i;aa.data[k].jj=j;
      aa.data[k].e=p[i][j];
      aa.tu++;k++;}
 //创建三元组顺序表
 for (k=0,i=0;i<4;i++)
  for (j=0;j<2;j++)
   if (w[i][j]!=0)
    { bb.data[k].ii=i;bb.data[k].jj=j;
      bb.data[k].e=w[i][j];
      bb.tu++;k++;}
 aa.mulmatrix(bb,cc);
 cout<<"乘积矩阵三元组顺序表:\n";
 print(cc);
 cout<<"创建的稀疏矩阵:\n";
 TSMatrix ff(MROW,MCOL,4);
 cout<<"按任意键结束!\n";getch();}
