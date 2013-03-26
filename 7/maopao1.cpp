//通用冒泡排序法(下沉)maopao1.cpp
#include<iostream.h>
#include<iomanip.h>
#define N 10
typedef int(*isgreat)(void *this_num,void *next_num);
void gensort(void *base,int n,int elemsize,isgreat great)
{int i,j,k;
 for(i=1;i<n;i++)
  for(j=0;j<n-i;j++)
  {char *this_num=(char *)base+j*elemsize;
   char *next_num=this_num+elemsize;
   if(great(this_num,next_num)>0)
    for(k=0;k<elemsize;k++)
    {char temp=this_num[k];
     this_num[k]=next_num[k];
     next_num[k]=temp;
    }
  }
}
int greatint(void *first,void *second)
 {return (*(int *)first>*(int *)second);}
int greatfloat(void *first,void *second)
 {return (*(float *)first>*(float *)second);}
void main()
{cout<<"maopao1.cpp运行结果:\n";
 int ai[N],i,m;
 for(i=0;i<N;i++)
  ai[i]=random(101+i)%100;
 cout<<"排序前数组:\n";
 for(i=0;i<N;i++)
  cout<<setw(4)<<ai[i];
 cout<<endl;
 gensort(ai,sizeof(ai)/sizeof(int),sizeof(int),greatint);
 cout<<"排序后数组:\n";
 for(i=0;i<N;i++)
   cout<<setw(4)<<ai[i];
 cout<<endl;
 float bf[N];
 for(i=0;i<N;i++)
   bf[i]=random(299+i)/200.0;
 cout<<setiosflags(ios::fixed);
 cout<<"排序前数组:\n";
 for(i=0;i<N;i++)
  cout<<setprecision(2)<<setw(6)<<bf[i];
 cout<<endl;
 gensort(bf,sizeof(bf)/sizeof(float),sizeof(float),greatfloat);
 cout<<"排序后数组:\n";
 for(i=0;i<N;i++)
  cout<<setprecision(2)<<setw(6)<<bf[i];
 cout<<endl;cin.get();}






