//顺序栈的类定义stack.h
#define ERROR 0
#define EQUAL 1
#define OVERFLOW -1
#define STACKSIZE 100
#define STACKINCREMENT 10

class SqStack
{private:
  SElemType *base;
  SElemType *top;
  int stacksize;
 public:
//构造函数
  SqStack();
//栈存在则栈被销毁
  Status DestroyStack();
//栈存在则清为空栈
  Status ClearStack();
//栈存在则返回true,否则false
  bool StackEmpty();
// 栈存在则返回栈的元素个数,即栈的长度
  int StackLength();
//栈存在且非空则返回栈的栈顶元素
  SElemType GetTop();
// 栈存在则插入元素e为新的栈顶元素
  Status Push(SElemType e);
// 栈存在且非空则删除栈的栈顶元素并用e返回其值
  SElemType Pop(SElemType *e);
// 栈的遍历
  void StackTraverse(void (*visit)(SElemType *));
};

