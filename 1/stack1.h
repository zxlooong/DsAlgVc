//顺序栈的类定义stack1.h
class Stack
{private:
  DataType *data;
  int maxSize;
  int top;
 public:
//创建空栈
  void SetStack(int n);
//栈存在则栈被销毁
  void FreeStack();
//栈存在则返回栈的元素个数,即栈的长度
  int StackSize();
//判断栈是否为空
  bool StackEmpty();
//判断栈是否为满
  bool StackFull();
//栈存在且非空则返回栈的栈顶元素
  DataType Peek();
//栈存在则插入元素item为新的栈顶元素
  void Push(DataType item);
//栈存在且非空则删除栈的栈顶元素并用e返回其值
  DataType Pop(DataType e);
//栈存在则清为空栈
  void ClearStack();
// 栈的遍历
  void StackTraverse(void (*visit)(DataType *));
};

