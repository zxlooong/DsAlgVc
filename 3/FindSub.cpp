//串模式匹配的类定义FindSub.cpp
#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
class String {
 private:
  char *str;
  int len;
 public:
   friend class string;
   String(char S[]);
   ~String(){delete []str;}
   int IndexBF(char T[],int pos);
   void GetNext(int next[]);
   int IndexKMP(char T[],int next[],int pos);
};
String::String(char S[])
{len=strlen(S);
 str=new char[len];
 if(str==NULL) exit(1);
 for(int i=0;i<len;i++) str[i]=S[i];
 str[len]='\0';
}
int String::IndexBF(char T[],int pos)
{int i,j,r,n;
 i=pos;j=0;
 n=strlen(T);
 while((i<len-1||j<n-1)&&str[j]!='\0'&&T[j]!='\0')
  {if(str[i]==T[j])
    {++i;++j;}
   else {i=i-j+1;j=0;}
  }
 if(j>=n-1) r=i-n+1;
 else r=-1;
 return r;
}
void String::GetNext(int next[])
{int j=0,k=-1;next[0]=-1;
 while(j<len-1)
 {if(k==-1||str[j]==str[k])
  {j++;k++;next[j]=k;}
  else k=next[k];
 }
 for(j=0;j<len;j++)
 {cout<<"next["<<j<<"]="<<next[j]<<' ';
  if((j+1)%5==0) cout<<endl;}
 cout<<endl;
}
int String::IndexKMP(char T[],int next[],int pos)
{int i,j,r,n;
 i=pos;j=0;
 n=strlen(T);T[n]='\0';
 while((i<len-1||j<n-1)&&str[j]!='\0'&&T[j]!='\0')
  {if(j==0||str[i]==T[j])
    {++i;++j;}
   else j=next[j];
  }
 if(j>=n-1) r=i-n+1;
 else r=-1;
 return r;
}
//串模式匹配的测试
void main()
{cout<<"FindSub.cpp运行结果:\n";
 int Index,next[30]={0};
 char s1[30],t1[28];
 cout<<"GetNext-IndexKMP的结果:\n";
 cout<<"输入主串s1:";gets(s1);
 cout<<"输入模式串t1:";gets(t1);
 String s(s1),t(t1);
 cout<<"主串s1长="<<strlen(s1);
 cout<<" 模式串t1长="<<strlen(t1)<<endl;
 t.GetNext(next);
 Index=s.IndexKMP(t1,next,0);
 if(Index!=-1)
  cout<<"模式串在主串的位置从第"<<Index<<"个字符开始\n";
 else cout<<"主串s中不含模式串t\n";
 cout<<"IndexBF的结果:\n";
 Index=s.IndexBF(t1,0);
 if(Index)
  {cout<<"模式串t在主串s中的位置从第";
   cout<<Index<<"个字符开始\n";}
 else cout<<"主串s中不含模式串t\n";
 cin.get();}


