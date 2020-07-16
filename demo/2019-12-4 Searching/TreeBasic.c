//
// Created by HkingAuditore on 2019/12/8.
//

#include <stdio.h>
#include <stdlib.h>
#include "OutputController.h"

//��������
typedef int ElementType;

//λ��
typedef enum side
{
	NoValid,
	Left,
	Right
} Side;

// �����ɫ
typedef enum nodeColor
{
	Red,
	Black
} NodeColor;

//���
typedef struct treeNode
{
	ElementType Data;
	struct treeNode *LeftChild, *RightChild, *Parent;
	int BalanceFactor;
	int Height;
	int BlackHeight;
	NodeColor Color;
} TreeNode;

//��
typedef struct tree
{
	TreeNode* Root;
	int NumOfNodes;
	int IsRBTree;
} Tree;

//��ת����
typedef enum direction
{
	TurnLeft,
	TurnRight
} Direction;

//���ɽڵ�

TreeNode* GenerateNode(ElementType _rootData)
{
	TreeNode* leaf = (TreeNode*)malloc(1 * sizeof(TreeNode));
	if (leaf)
	{
		//      ��ʼ��
		leaf->Data = _rootData;
		leaf->LeftChild = leaf->RightChild = leaf->Parent = NULL;
		leaf->BalanceFactor = 0;
		leaf->Height = 0;
		leaf->Color = Red;
		leaf->BlackHeight = 0;
	}
	return leaf;
}

//���ɳ�ʼ��

Tree* GenerateTree(ElementType _rootData)
{
	Tree* tree = (Tree*)malloc(1 * sizeof(Tree));
	if (tree)
	{
		tree->Root = GenerateNode(_rootData);
	}
	tree->NumOfNodes = 0;
	tree->IsRBTree = 0;

	return tree;
}

//����֪�ڵ����Ҷ��

int AppendLeaf(TreeNode* _target, TreeNode* _leaf, Side _side)
{
	_leaf->Parent = _target;
	if (_side == Left)
	{
		_target->LeftChild = _leaf;
	}
	else if (_side == Right)
	{
		_target->RightChild = _leaf;
	}
	else
	{
		return 0;
	}
	return 1;
}

//��ȡ����λ��

Side GetValidSide(TreeNode* _node)
{
	if (!_node->LeftChild)
	{
		return Left;
	}
	else if (!_node->RightChild)
	{
		return Right;
	}
	else
	{
		return NoValid;
	}
}

//���ڲ����������ݴ�С����λ��
Side GetComparedSide(TreeNode* _node, TreeNode* _follow)
{
	if (_follow->Data > _node->Data)
	{
		return Right;
	}
	else
	{
		return Left;
	}
}

//��ȡ���ݴ�С�ó����½ڵ��ڲ������еĺ���λ��
TreeNode* GetValidPosition(Tree* _tree, TreeNode* _node, TreeNode* _crition)
{
	TreeNode* _position = _tree->Root;
	Side side;
	while (_position && _position != _crition)
	{
		side = GetComparedSide(_position, _node);
		if (side == Left)
		{
			if (_position->LeftChild && _position->LeftChild != _crition)
			{
				_position = _position->LeftChild;
				continue;
			}
			else
			{
				return _position;
			}
		}
		else
		{
			if (_position->RightChild && _position->RightChild != _crition)
			{
				_position = _position->RightChild;
				continue;
			}
			else
			{
				return _position;
			}
		}
	}
}

//���ڵ�����
int RotateNodeLeft(TreeNode* _pivot, Tree* _tree, TreeNode* _crition)
{
	Side pivotSide = NoValid;
	if (_pivot->Parent && _pivot->Parent != _crition)
	{
		pivotSide = _pivot->Parent->LeftChild == _pivot ? Left : Right;
	}
	else
	{
		_tree->Root = _pivot->RightChild;
	}
	if (pivotSide == Left)
	{
		_pivot->Parent->LeftChild = _pivot->RightChild;
	}
	else if (pivotSide == Right)
	{
		_pivot->Parent->RightChild = _pivot->RightChild;
	}
	_pivot->RightChild->Parent = _pivot->Parent;
	if (_pivot->RightChild->LeftChild && _pivot->RightChild->LeftChild != _crition)
	{
		_pivot->RightChild->LeftChild->Parent = _pivot;
	}
	_pivot->Parent = _pivot->RightChild;
	_pivot->RightChild = _pivot->RightChild->LeftChild;
	_pivot->Parent->LeftChild = _pivot;
	return 1;
}

//���ڵ�����
int RotateNodeRight(TreeNode* _pivot, Tree* _tree, TreeNode* _crition)
{
	Side pivotSide = NoValid;
	if (_pivot->Parent && _pivot->Parent != _crition)
	{
		pivotSide = _pivot->Parent->LeftChild == _pivot ? Left : Right;
	}
	else
	{
		_tree->Root = _pivot->LeftChild;
	}

	if (pivotSide == Left)
	{
		_pivot->Parent->LeftChild = _pivot->LeftChild;
	}
	else if (pivotSide == Right)
	{
		_pivot->Parent->RightChild = _pivot->LeftChild;
	}
	_pivot->LeftChild->Parent = _pivot->Parent;
	if (_pivot->LeftChild->RightChild && _pivot->LeftChild->RightChild != _crition)
	{
		_pivot->LeftChild->RightChild->Parent = _pivot;
	}
	_pivot->Parent = _pivot->LeftChild;
	_pivot->LeftChild = _pivot->LeftChild->RightChild;
	_pivot->Parent->RightChild = _pivot;
	return 1;
}

//��תPivot�ڵ�

int RotateNode(TreeNode* _pivot, Direction _dir, Tree* _tree, TreeNode* _crition)
{
	//    printf("in rotate!\n");
	if (_dir == TurnLeft)
	{
		RotateNodeLeft(_pivot, _tree, _crition);
	}
	else if (_dir == TurnRight)
	{
		RotateNodeRight(_pivot, _tree, _crition);
	}
	else
	{
		return 0;
	}
	return 1;
}

//����ڵ�
ElementType ProcessNode(TreeNode* _node, void* _function(TreeNode*))
{
	_function(_node);
	return _node->Data;
}

//����ڵ�
void WriteNode(const TreeNode* _node)
{
	WriteData("���ݣ�", _node->Data);
}

//������ʽ
typedef enum traversalMode
{
	DLR,
	LDR,
	LRD
} TraversalMode;

/*****************ǰ�����*****************/

//ǰ������ڵ�
static void TraversalNodeDLR(const TreeNode* _node, void* _function(TreeNode*), TreeNode* _crition)
{
	if (_node && _node != _crition)
	{
		ProcessNode(_node, _function);
		TraversalNodeDLR(_node->LeftChild, _function, _crition);
		TraversalNodeDLR(_node->RightChild, _function, _crition);
	}
}

//ǰ�������
static void TraversalDLR(const Tree* _tree, void* _function(TreeNode*), TreeNode* _crition)
{
	if (_tree && _tree->Root && _tree->Root != _crition)
	{
		TraversalNodeDLR(_tree->Root, _function, _crition);
	}
}

/*****************ǰ�����*****************/

/*****************�������*****************/
//��������ڵ�
static void TraversalNodeLDR(const TreeNode* _node, void* _function(TreeNode*), TreeNode* _crition)
{
	if (_node && _node != _crition)
	{
		TraversalNodeLDR(_node->LeftChild, _function, _crition);
		ProcessNode(_node, _function);
		TraversalNodeLDR(_node->RightChild, _function, _crition);
	}
}

//���������
static void TraversalLDR(const Tree* _tree, void* _function(TreeNode*), TreeNode* _crition)
{
	if (_tree && _tree->Root && _tree->Root != _crition)
	{
		TraversalNodeLDR(_tree->Root, _function, _crition);
	}
}

/*****************�������*****************/

/*****************�������*****************/
//��������ڵ�
static void TraversalNodeLRD(const TreeNode* _node, void* _function(TreeNode*), TreeNode* _crition)
{
	if (_node && _node != _crition)
	{
		TraversalNodeLRD(_node->LeftChild, _function, _crition);
		TraversalNodeLRD(_node->RightChild, _function, _crition);
		ProcessNode(_node, _function);
	}
}

//���������
static void TraversalLRD(const Tree* _tree, void* _function(TreeNode*), TreeNode* _crition)
{
	if (_tree && _tree->Root && _tree->Root != _crition)
	{
		TraversalNodeLRD(_tree->Root, _function, _crition);
	}
}

/*****************�������*****************/

//������
int TraversalTree(const Tree* _tree, TreeNode* _crition, TraversalMode _mode, void* _function(TreeNode*))
{
	switch (_mode)
	{
	case DLR:
		TraversalDLR(_tree, _function, _crition);
		return 1;
	case LDR:
		TraversalLDR(_tree, _function, _crition);
		return 1;
	case LRD:
		TraversalLRD(_tree, _function, _crition);
		return 1;
	default:
		return 0;
	}
	SwitchLine();
}

//���߶ȼ���
void NodeHeightCalculator(TreeNode* _node)
{
	int left = _node->LeftChild ? _node->LeftChild->Height : -1;
	int right = _node->RightChild ? _node->RightChild->Height : -1;
	int tempHeight = left > right ? left : right;
	_node->Height = left + right + 1 > 0 ? tempHeight + 1 : 0;
}

void NodeInfoOutput(TreeNode* _node)
{
	Write("�����Ϣ��");
	WriteData("����", _node->Data);
	WriteData("˫��", _node->Parent ? _node->Parent->Data : -9999);
	WriteData("����", _node->LeftChild ? _node->LeftChild->Data : -9999);
	WriteData("�Һ���", _node->RightChild ? _node->RightChild->Data : -9999);
	WriteData("�߶�", _node->Height);
	WriteData("ƽ����", _node->BalanceFactor);
	printf("��ɫ��%s\n", _node->Color == Red ? "Red" : "Black");
	SwitchLine();
}