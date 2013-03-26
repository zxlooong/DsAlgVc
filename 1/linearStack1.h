//顺序堆栈的类定义linearStack1.h
const int LEN=40;
class Stack
{private:
  ElemType stack[LEN];
  int top;
 public:
//构造函数
  Stack(){top=0;}
//析构函数
  ~Stack(){}
//创建有序或无序栈
  void CreateStack(int m=LEN,int mark=0);
//清空栈
  void ClearStack();
//检查栈是否为空
  bool StackEmpty();
//读取栈顶元素
  ElemType Peek();
//向栈中插入元素
  void Push(const ElemType&,int m=LEN);
//从栈中删除元素
  ElemType Pop();
//检查栈是否已满
  bool StackFull(int m=LEN);
//栈的输出
  void StackPrint(int m=LEN);
};
