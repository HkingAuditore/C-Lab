#pragma	 once
#include <stdio.h>
#include <stdlib.h>
#define  STACKMAXSPACE 20


typedef int StackEnum;

typedef struct stack{
	int			StackTop;
	StackEnum*	StackArray;
}Stack;
//����ջ

static int GenerateStack(Stack* _stack)
{
	_stack->StackArray = (StackEnum*)malloc(sizeof(StackEnum)*STACKMAXSPACE);
	_stack->StackTop = 0;
	return 0;
}
//��ջ
static int Push(Stack* _stack,StackEnum _data)
{
	_stack->StackArray[_stack->StackTop++] = _data;
	return 0;
}

//��ջ
static StackEnum Pop(Stack* _stack)
{
	return (_stack->StackArray[--_stack->StackTop]);
}

//��ȡջ����
static int GetStackLength(Stack _stack)
{
	return (_stack.StackTop);
}

//�Ƿ�Ϊ��ջ
static int IsEmptyStack(Stack _stack)
{
	return (_stack.StackTop ? 0 : 1);
}


