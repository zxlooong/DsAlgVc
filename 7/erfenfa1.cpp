//二分查找法(递归调用)erfenfa1.cpp
#include<iostream.h>
#include<iomanip.h>
float a[]={1.1,1.3,1.5,1.7,1.9,2.1,2.3,2.5,2.7,2.9};
void binsrch(int s,int r,float x)
{int m;
 m=(s+r)/2;
 if(a[m]==x)
  {cout<<x<<"在序列中找到!\n";}
 else if(s>r)
   {cout<<x<<"在序列中未找到!\n";
    cin.get();cin.get();exit(-1);}
 else if(x>a[m])
    binsrch(m+1,r,x);
 else binsrch(s,m-1,x);
}
void main()
{cout<<"erfenfa1运行结果:\n";
 float x=2.3;
 int s=0,r=9;
 cout<<"输入x:";cin>>x;
 cout<<"查找结果:\n";
 binsrch(s,r,x);
 cin.get();cin.get();}


