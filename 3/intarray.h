//建立一维,二维数组的类定义intarray.h
class IntArray1{
    int size;//数组个数
    int *data;//数组指针
    void init(int n);
    IntArray1():size(0),data(0){}
    friend class IntArray2;
public:
    //构造函数
    IntArray1(int n){ init(n);}
    //析构函数
    ~IntArray1(){ delete []data;}
    //下标操作符重载
    //定义为引用以保证既可取值也可赋值
    int &operator[](int i);
    //返回数组长度
    int size1()const{ return size;}
    //重新定义数组
    void ReArray(int si);
};
class IntArray2{
    int size;
    IntArray1 *data;
public:
    //构造函数
    IntArray2(int,int);
    //析构函数
    ~IntArray2(){ delete []data;}
    //下标操作符重载
    //定义为引用以保证既可取值也可赋值
    IntArray1 &operator[](int i);
    //返回二维数组行数
    int size1()const{ return size;}
    //返回二维数组列数
    int size2()const{ return data->size1();}
};


