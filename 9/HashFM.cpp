//散列文件的插入、删除和查找操作HashFM.cpp
#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<iomanip.h>
//m为散列表的长度,确定取值为16
  const int m=16;
//km为散列主文件中每个结点所含的元素个数，
//取值大于等于1,暂取为3
  const int km=3;  
//定义关键字类型为整型
  typedef int KeyType;
//索引主文件中的记录元素类型
struct ElemType {
 int key;    //关键字域
 char rest[10];//其他域,暂用字符数组表示
};
//索引主文件中的结点类型
struct FLNode {
  ElemType data[km];//值域
  int next; //指向下一个结点的指针域
};
//b1为索引表文件中的记录长度
  const int b1=sizeof(int);
//b2为索引主文件中的记录长度
  const int b2=sizeof(FLNode); 
//NullTag作为空关键字的标记,假定用-10表示
  const int NullTag=-10;
//散列文件的类定义
template<class T>
class HFile
{public:
  //构造函数,初始化散列表文件和主文件
  HFile(char* fn1,char* fn2);
  //把元素x插入到按桶散列的文件中
  void THFInsertA(char* fn1,char* fn2,T x);
  //把数组x中n个元素插入到按桶散列的文件中
  void THFInsertB(char* fn1,char* fn2,T x[],int n);
  //从按桶散列的文件中删除关键字为x.key的元素,
  //并由x带回该元素,若删除成功则返回1,否则返回0
  bool THFDelete(char* fn1, char* fn2, T& x);
  //从按桶散列的文件中查找关键字为x.key的元素,
  //并由x带回该元素,若查找成功则返回1,否则返回0
  bool THFSearch(char* fn1,char* fn2,T& x);
  //按单链表顺序打印出按桶散列主文件中每个结点的所有元素值
  void THFPrint(char* fn1,char* fn2);
};
//散列文件的类实现
//初始化散列表文件和主文件
template<class T>
HFile<T>::HFile(char* fn1,char* fn2)
{//以输出方式打开并建立空的散列表文件
 ofstream f1(fn1, ios::out|ios::binary);
 if(!f1) {
   cerr<<fn1<<' '<<"不能打开!"<<endl;
   exit(1);}
//以输出方式打开并建立空的散列主文件
 ofstream f2(fn2, ios::out|ios::binary);
 if(!f2) {cerr<<fn2<<' '<<"不能打开!"<<endl;
	  exit(1);}
//动态分配具有m+1个整型存储空间的数组A
 int* A=new int[m+1];
 if(!A){cerr<<"申请堆内存失败!"<<endl;
       	exit(1);}
//给数组A中的每个元素赋初值-1，表示空指针
 for(int i=0; i<m+1; i++)
   A[i]=-1;
//初始化散列表文件
  f1.write((char*)A, (m+1)*b1);
 //删除数组A并关闭文件
  delete [] A;
  f1.close();
  f2.close();
}
//把元素x插入到按桶散列的文件中
template<class T>
void HFile<T>::THFInsertA(char* fn1, char* fn2, T x)
{//以输入输出和不新建方式打开散列表文件
 fstream f1(fn1,ios::in|ios::out|ios::binary);
 if(!f1) {cerr<<fn1<<' '<<"不能打开!"<<endl;
      exit(1);}
 //以输入输出和不新建方式打开散列主文件
 fstream f2(fn2, ios::in|ios::out|ios::binary);
 if(!f2){cerr<<fn2<<' '<<"不能打开!"<<endl;
         exit(1);}
 //给数组A中的每个元素赋初值-1，表示空指针
 int* A=new int[m+1];
 if(!A) {cerr<<"申请堆内存失败!"<<endl;
	 exit(1);}
 //将散列表文件中的内容全部读入到数组A中
 f1.read((char*)A, (m+1)*b1);
 //以关键字x.key计算x的散列地址
 int d=x.key%m;
 //将x插入到d单链表的表头结点中
 int j;
 FLNode temp;
 if(A[d]!=-1)
  {f2.seekg(A[d]*b2);
   f2.read((char*)&temp, b2);
   for(j=0; j<km; j++)
    if(temp.data[j].key==NullTag) break;
    if(j<km) {
      temp.data[j]=x;
      f2.seekg(-b2, ios::cur);
      f2.write((char*)&temp, b2);
      goto END;  //插入表头结点后，转去做结束处理
  }}
  //当d单链表为空或头结点中没有空闲位置时向下执行
  //建立待插入d单链表表头的内存结点temp
  temp.data[0]=x;
  for(j=1; j<km; j++)
   temp.data[j].key=NullTag;
  temp.next=A[d];
  //将temp结点的值写入到f2文件尾并被链接到d单链表的表头
  if(A[m]==-1) {
  //将f2中的文件指针移至文件尾
   f2.seekg(0,ios::end);
  //计算出文件尾的结点位置序号
   int len=f2.tellg()/b2;
  //将temp结点的值写入文件尾
   f2.write((char*)&temp,b2);
  //使A[d]指向新插入的结点
   A[d]=len;}
  //将temp结点的值写入到f2文件的一个空闲结点中
  //并被链接到d单链表的表头
   else {//p指向空闲单链表的表头结点
     int p=A[m];
   //使空闲单链表的表头指针指向其下一个结点
     f2.seekg(p*b2);
     FLNode pn;
     f2.read((char*)&pn, b2);
     A[m]=pn.next;
   //使temp的值写入到p位置的结点上
     f2.seekg(-b2, ios::cur);
     f2.write((char*)&temp, b2);
   //使A[d]指向新插入的p结点
     A[d]=p;}
  //将数组A中的全部内容写回到散列表文件f1中
   f1.seekg(0);
   f1.write((char*)A, (m+1)*b1);
  //删除动态数组A和关闭所有文件
   END:
    delete [] A;
    f1.close();
    f2.close();
}
//把数组x中n个元素插入到按桶散列的文件中
template<class T>
void HFile<T>::THFInsertB(char* fn1,char* fn2,T x[],int n)
{fstream f1(fn1, ios::in|ios::out|ios::binary);
 if(!f1) {cerr<<fn1<<' '<<"不能打开!"<<endl;
	  exit(1);}
 fstream f2(fn2, ios::in|ios::out|ios::binary);
 if(!f2) {cerr<<fn2<<' '<<"不能打开!"<<endl;
          exit(1);}
 int* A=new int[m+1];
 if(!A) {cerr<<"申请堆内存失败!"<<endl;
	 exit(1);}
 f1.read((char*)A, (m+1)*b1);
 for(int i=0; i<n; i++)
  {int d=x[i].key%m;
   int j;
   FLNode temp;
   if(A[d]!=-1)
    {f2.seekg(A[d]*b2);
     f2.read((char*)&temp, b2);
     for(j=0; j<km; j++)
      if(temp.data[j].key==NullTag) break;
      if(j<km) {
       temp.data[j]=x[i];
       f2.seekg(-b2, ios::cur);
       f2.write((char*)&temp, b2);
       continue;}}
      temp.data[0]=x[i];
      for(j=1;j<km;j++)
	temp.data[j].key=NullTag;
      temp.next=A[d];
      if(A[m]==-1) {
       f2.seekg(0,ios::end);
       int len=f2.tellg()/b2;
       f2.write((char*)&temp,b2);
       A[d]=len;}
      else {int p=A[m];
	f2.seekg(p*b2);
	FLNode pn;
	f2.read((char*)&pn, b2);
	A[m]=pn.next;
	f2.seekg(-b2, ios::cur);
	f2.write((char*)&temp, b2);
	A[d]=p;}}
    f1.seekg(0);
    f1.write((char*)A, (m+1)*b1);
    delete [] A;
    f1.close();f2.close();
}
//从按桶散列的文件中删除关键字为x.key的元素,并由x带回该
//元素,若删除成功则返回1,否则返回0
template<class T>
bool HFile<T>::THFDelete(char* fn1,char* fn2,T& x)
{fstream f1(fn1,ios::in|ios::out|ios::binary);
 int k;
 if(!f1) {cerr<<fn1<<' '<<"不能打开!"<<endl;
	  exit(1);}
 fstream f2(fn2,ios::in|ios::out|ios::binary);
 if(!f2) {cerr<<fn2<<' '<<"不能打开!"<<endl;
	  exit(1);}
 int* A=new int[m+1];
 if(!A) {cerr<<"申请堆内存失败!"<<endl;
	 exit(1);}
 f1.read((char*)A, (m+1)*b1);
 int DeleteTag=0;  //用DeleteTag作为删除是否成功的标记
 int d=x.key%m;
 int p=A[d],i=0;  //用p保存d单链表的表头结点的位置序号，
 //用i保存该结点中被删除元素的下标或第一个空元素的下标
 FLNode temp;
 //从d单链表的表头结点中删除关键字为x.key的元素
 if(p!=-1)
  {f2.seekg(p*b2);
   f2.read((char*)&temp, b2);
   while(i<km && temp.data[i].key!=NullTag)
    if(temp.data[i].key==x.key) break;
    else i++;
    if(i<km && temp.data[i].key==x.key) {
     x=temp.data[i]; //由x带回被删除的元素值
    for(k=i+1; k<km; k++)
     if(temp.data[k].key!=NullTag)
       temp.data[k-1]=temp.data[k];
     else break;
   temp.data[k-1].key=NullTag;
   if(k-1==0) { //删除d单链表中表头空结点
    A[d]=temp.next;
    temp.next=A[m];
    A[m]=p;}
    f2.seekg(-b2, ios::cur);
    f2.write((char*)&temp, b2);
    DeleteTag=1;//被赋值1表示删除成功
    goto END;  //转去做结束处理
  }}
 //若d单链表为空,则转去做结束处理
  else goto END;
  //从d单链表的第二个结点起顺序查找被删除的元素
  int j,q;
  q=temp.next;  //q初始指向第二个结点
  FLNode tq;//用tq保存散列主文件中位置为q的结点
  while(q!=-1)
    {f2.seekg(q*b2);
     f2.read((char*)&tq, b2);
     for(j=0; j<km; j++)
       if(tq.data[j].key==x.key) {
	 x=tq.data[j];break;}
     if(j<km) break;
     q=tq.next;}
 //若找到了被删除的元素,则将第一个结点中的最后一个元素
 //移动到被删除元素的位置
  if(q!=-1) {tq.data[j]=temp.data[i-1];
    temp.data[i-1].key=NullTag;
    f2.seekg(q*b2);
    f2.write((char*)&tq, b2);
    if(i==1) {//把空的表头结点链接到空闲表的表头
     A[d]=temp.next;
     temp.next=A[m];
     A[m]=p;}
     f2.seekg(p*b2);
     f2.write((char*)&temp, b2);
     DeleteTag=1;}  //置删除成功标志
  //做删除操作的结束处理操作
  END:
   if(DeleteTag==1) {
     f1.seekg(0);
     f1.write((char*)A,(m+1)*b1);}
     delete [] A;
     f1.close();
     f2.close();
     if(DeleteTag==1) return true;
     else return false;
}
//从按桶散列的文件中查找关键字为x.key的元素,
//并由x带回该元素,若查找成功则返回1,否则返回0
template<class T>
bool HFile<T>::THFSearch(char* fn1,char* fn2,T& x)
{//以输入和不新建方式打开散列表文件
 ifstream f1(fn1, ios::in|ios::binary);
 if(!f1) {cerr<<fn1<<' '<<"不能打开!"<<endl;
       	exit(1);}
 //以输入和不新建方式打开散列主文件
 ifstream f2(fn2, ios::in|ios::binary);
 if(!f2) {cerr<<fn2<<' '<<"不能打开!"<<endl;
	exit(1);}
  //定义数组A并将f1文件读入A中
 int* A=new int[m+1];
 if(!A) {cerr<<"申请堆内存失败!"<<endl;
	exit(1);}
 f1.read((char*)A, (m+1)*b1);
  //计算x元素在散列表中的地址
 int i,d=x.key%m;
  //从d单链表中顺序查找关键字为x.key的元素
 int p=A[d];
  //从d单链表中顺序查找关键字为x.key的元素
 FLNode temp;
 while(p!=-1)
   {f2.seekg(p*b2);
    f2.read((char*)&temp, b2);
    for(i=0;i<km;i++)
     if(temp.data[i].key==x.key)
      {x=temp.data[i];//被查找到的元素由x带回
       	break;}
    if(i<km) break;
    else  p=temp.next;}
  //进行查找结束处理
 delete [] A;
 f1.close();f2.close();
 if(p==-1) return false; else return true;
}
//按单链表顺序打印出按桶散列主文件中每个结点的所有元素值
template<class T>
void HFile<T>::THFPrint(char* fn1, char* fn2)
{ifstream f1(fn1, ios::in|ios::binary);
 if(!f1) {cerr<<fn1<<' '<<"不能打开!"<<endl;
   exit(1);}
 ifstream f2(fn2, ios::in|ios::binary);
 if(!f2) {cerr<<fn2<<' '<<"不能打开!"<<endl;
   exit(1);}
  int* A=new int[m+1];
  if(!A) {cerr<<"申请堆内存失败!"<<endl;
   exit(1);}
  f1.read((char*)A, (m+1)*b1);
  int p;
  FLNode pn;
  for(int i=0; i<m+1; i++)
    {cout<<setw(2)<<i<<':';
     p=A[i];
     while(p!=-1) {
      f2.seekg(p*b2);
      f2.read((char*)&pn, b2);
      //输出结点的位置序号
      cout<<setw(2)<<p<<"->";
      //输出结点中每个元素的关键字，以此代替结点的值
      for(int j=0; j<km; j++)
        cout<<pn.data[j].key<<"  ";
      //使p指向下一个结点
	p=pn.next;}
     cout<<endl;}
}
//散列文件的类实现的测试
void main()
{ cout<<"HashFM.cpp运行结果:\n";
  //定义保存记录的数组a并初始化
  ElemType a[15]={{13,"li"},{18,"liu"},{17,"wphp"},{37,"menrm"},
  {8,"ytong"},{22,"zhua"},{24,"push"},{48,"qian"},{34,"tang"},
  {57,"shdm"},{55,"kang"},{30,"liuli"},{25,"qiaoh"},
  {31,"dukun"},{17,"haiang"}};
  //定义保存记录的数组b并初始化
  ElemType b[16]={{23,"tang"},{38,"suan"},{56,"kony"},
  {55,"shao"},{80,"caik"},{70,"ganwu"},{65,"dukun"},{42,"sini"},
  {29,"liuda"},{43,"xitu"},{71,"taoto"},{77,"shouw"},
  {93,"shum"},{69,"liyz"},{45,"xuyang"},{19,"wxy"}};
  //定义散列表文件和主文件的名字，并由字符指针p1和p2所指向
  char *p1=".\\HFile.idx", *p2=".\\HFile.dat";
  //初始化散列表文件和主文件	
  HFile<ElemType> myfile(p1,p2);
  //向散列文件插入数组a和b中保存的记录  
  myfile.THFInsertB(p1,p2,a,15);
  myfile.THFInsertB(p1,p2,b,16);
  //设mark用于保存删除或查找函数返回的值
  int mark;
  //定义x保存一个待插入的元素值或保存待删除或查找元素的关键字
  ElemType x;
  //利用键盘输入操作散列文件
  while(1) {
    cout<<endl<<"功能号表："<<endl;
    cout<<"1---向散列文件插入一个元素"<<endl;
    cout<<"2---从散列文件中删除一个元素"<<endl;
    cout<<"3---从散列文件中查找一个元素"<<endl;
    cout<<"4---输出散列主文件"<<endl;
    cout<<"5---结束运行"<<endl;
    char ch;
    cout<<"请输入你的选择(1-5): ";cin>>ch;
    switch (ch)
     {case '1':
	cout<<"输入待插入元素x的值(一个整数和一个字符串):";
	  cin>>x.key>>x.rest;
        myfile.THFInsertA(p1,p2,x);break;
      case '2':
        cout<<"输入待删除元素x的关键字:";
          cin>>x.key;
	mark=myfile.THFDelete(p1,p2,x);
        if(mark==1) cout<<"删除成功!"<<x.key<<' '<<x.rest<<endl;
	else cout<<"删除失败!"<<endl;break;
      case '3':cout<<"输入待查找元素x的关键字:";
	        cin>>x.key;
	mark=myfile.THFSearch(p1,p2,x);
        if(mark==1)
	  cout<<"查找成功!"<<x.key<<' '<<x.rest<<endl;
        else cout<<"查找失败!"<<endl;break;
      case '4':myfile.THFPrint(p1,p2);break;
      case '5':return;
      default:cout<<"输入选择错误,请重输!"<<endl;
}}}
