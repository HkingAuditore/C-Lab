#pragma	 once
#include <stdio.h>
#include <stdlib.h>
#define  STACKMAXSPACE 20


typedef int StackEnum;

typedef struct stack{
	int			StackTop;
	StackEnum*	StackArray;
}Stack;
//生成栈

static int GenerateStack(Stack* _stack)
{
	_stack->StackArray = (StackEnum*)malloc(sizeof(StackEnum)*STACKMAXSPACE);
	_stack->StackTop = 0;
	return 0;
}
//进栈
static int Push(Stack* _stack,StackEnum _data)
{
	_stack->StackArray[_stack->StackTop++] = _data;
	return 0;
}

//出栈
static StackEnum Pop(Stack* _stack)
{
	return (_stack->StackArray[--_stack->StackTop]);
}

//获取栈长度
static int GetStackLength(Stack _stack)
{
	return (_stack.StackTop);
}

//是否为空栈
static int IsEmptyStack(Stack _stack)
{
	return (_stack.StackTop ? 0 : 1);
}


