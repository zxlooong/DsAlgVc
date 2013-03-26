//IndexFM.cpp
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<iomanip.h>
#include "IndexF.cpp"
//索引文件的类实现的测试
void main()
{cout<<"IndexFM.cpp运行结果:\n";
 //定义保存记录的数组a并初始化
 ElemType a[15]={{13,"li"},{18,"liu"},{17,"wphp"},{37,"menrm"},
  {8,"ytong"},{22,"zhua"},{24,"push"},{48,"qian"},{34,"tang"},
  {57,"shdm"},{55,"kang"},{30,"liuli"},{25,"qiaoh"},
  {31,"dukun"},{17,"haiang"}};
 //定义保存记录关键字的数组b并初始化
 KeyType b[16]={12,18,15,32,6,23,21,48,36,57,45,29,25,38,14,9};
 //定义主文件和索引文件的名字，并由字符指针p1和p2所指向
 char *p1=".\\HFile1.dat",*p2=".\\HFile1.idx";
 int m;//记录个数
 InFile<IndexItem,ElemType> myfile;
 //利用键盘输入操作主文件、索引文件的插入、删除和查找
 while(1) {
    cout<<endl<<"功能号表:"<<endl;
    cout<<"1---向主文件插入若干记录"<<endl;
    cout<<"2---从主文件中删除若干记录"<<endl;
    cout<<"3---从主文件中查找若干记录"<<endl;
    cout<<"4---输出主文件fn1"<<endl;
    cout<<"5---输出索引文件fn2"<<endl;
    cout<<"6---结束运行"<<endl;
    char ch;
    cout<<"请输入你的选择(1-6): ";cin>>ch;
    switch (ch)
     {case '1':cout<<"输入待插入记录个数m:";
	   cin>>m;myfile.MFAppend(p1,p2,a,m);break;
      case '2':cout<<"输入待删除记录个数m:";
        cin>>m;myfile.MFDelete(p1,p2,b,m);break;
      case '3':cout<<"输入待查找记录个数m:";
        cin>>m;myfile.MFSearch(p1,p2,b,m);break;
      case '4':myfile.PrintMainFile(p1);break;
      case '5':myfile.PrintIndexFile(p2);break;
      case '6':return;
      default:cout<<"输入选择错误,请重输!"<<endl;
}}}

