//
// Created by HkingAuditore on 2019/12/23.
//

#include "BalancedBinaryTree.h"
#include "TreeBasic.h"
#include "InputController.h"

TreeNode* _NIL;

typedef enum situationInsert
{
	BlackFather,
	RedFatherRedUncle,
	RedFatherBlackUncle_Node_FatherFirst,
	RedFatherBlackUncle_Node_FatherSecond,
	RedFatherBlackUncle_NodeSecondFatherFirst,
	RedFatherBlackUncle_NodeFirstFatherSecond
} SituationInsert;

typedef enum situationDelete
{
	/*NO CHILD*/
	NoChild_Red, NoChild_Black_Root, NoChild_Black_NonRoot,
	/*ONE CHILD*/
	OneChild_Red, OneChild_Black
} SituationDelete;

SituationInsert JudgeInsertSituation(TreeNode* _node);
void Stablize_BRTree(TreeNode* _node, SituationInsert _situation, Tree* _tree);
TreeNode* InsertNode(Tree* _tree, ElementType _data);

// �����ڱ��ڵ�
TreeNode* GenerateNIL()
{
	_NIL = GenerateNode(-2565);
	_NIL->Color = Black;
}

// ���ɺ�����½ڵ�
TreeNode* GenerateRBTreeNode(ElementType _data)
{
	TreeNode* node = GenerateNode(_data);
	node->LeftChild = node->RightChild = _NIL;
	node->Color = Red;
	return node;
}

//���ڲ����������ݴ�С����λ��
Side GetComparedSide_RBTree(TreeNode* _node, TreeNode* _follow)
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
TreeNode* GetValidPosition_RBTree(Tree* _tree, TreeNode* _node)
{
	TreeNode* _position = _tree->Root;
	Side side;
	while (_position != _NIL && _position)
	{
		side = GetComparedSide_RBTree(_position, _node);
		if (side == Left)
		{
			if (_position->LeftChild && _position->LeftChild != _NIL)
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
			if (_position->RightChild && _position->RightChild != _NIL)
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

// ���ɺ����
Tree* GenerateRBTree()
{
	Tree* tree = GenerateTree(Read(Keyboard));
	tree->Root->LeftChild = tree->Root->RightChild = _NIL;
	tree->IsRBTree = 1;
	tree->Root->Color = Black;
	tree->Root->Parent = _NIL;
	ElementType data;
	while ((data = Read(Keyboard)) != EXITINPUT)
	{
		InsertNode(tree, data);
	}
	return tree;
}

// ��ת
void Stablize_BRTree(TreeNode* _node, SituationInsert _situation, Tree* _tree)
{
	
	if (_node == _tree->Root)
	{
		if (_node->Color != Black)
		{
			_node->Color = Black;
		}
		return;
	}
	TreeNode* uncle = GetSideChild(_node->Parent->Parent, GetChildSide(_node->Parent->Parent, _node->Parent) == Left ? Right : Left);
	switch (_situation)
	{
		// �ڸ�//
	case BlackFather:
		return;
		break;
		// �츸//
		// �츸����
	case RedFatherRedUncle:
		_node->Parent->Color = uncle->Color = Black;
		if (_node->Parent->Parent)
		{
			_node->Parent->Parent->Color = Red;
			Stablize_BRTree(_node->Parent->Parent, JudgeInsertSituation(_node->Parent->Parent), _tree);
		}
		break;
		//// �츸����////
		// ��Ϊ����
	case RedFatherBlackUncle_Node_FatherFirst:
		StabilizeNode(LL, _node->Parent->Parent, _tree, _NIL);
		_node->Parent->Color = Black;
		_node->Parent->RightChild->Color = Red;
		break;
		// ��Ϊ����
	case RedFatherBlackUncle_Node_FatherSecond:
		StabilizeNode(RR, _node->Parent->Parent, _tree, _NIL);
		_node->Parent->Color = Black;
		_node->Parent->LeftChild->Color = Red;
		break;
		// �ڵ���ӣ����׳���
	case RedFatherBlackUncle_NodeSecondFatherFirst:
		StabilizeNode(LR, _node->Parent->Parent, _tree, _NIL);
		_node->Color = Black;
		_node->RightChild->Color = Red;
		break;
		// �ڵ㳤�ӣ����״���
	case RedFatherBlackUncle_NodeFirstFatherSecond:
		StabilizeNode(RL, _node->Parent->Parent, _tree, _NIL);
		_node->Color = Black;
		_node->LeftChild->Color = Red;
		break;
	default:
		return;
	}
}

// �жϲ�������
SituationInsert JudgeInsertSituation(TreeNode* _node)
{
	printf("%d:", _node->Data);
	if (_node->Parent->Color == Black)
	{
		printf("BF!\n");

		return BlackFather;
	}
	else
	{
		Side side = GetChildSide(_node->Parent->Parent, _node->Parent) == Left ? Right : Left;
		TreeNode* uncle = GetSideChild(_node->Parent->Parent, side);
		printf("uncle:%d,color:%s\n", uncle->Data, uncle->Color == Red ? "Red" : "Black");
		if (uncle != _NIL && uncle->Color == Red)
		{
			printf("RFRU!\n");
			return RedFatherRedUncle;
		}
		else
		{
			Side nodeSide = GetChildSide(_node->Parent, _node);
			Side fatherSide = GetChildSide(_node->Parent->Parent, _node->Parent);
			if (nodeSide == Left && fatherSide == Left)
			{
				printf("RFBU_NFF!\n");

				return RedFatherBlackUncle_Node_FatherFirst;
			}
			else if (nodeSide == Right && fatherSide == Right)
			{
				printf("RFBU_NFS!\n");

				return RedFatherBlackUncle_Node_FatherSecond;
			}
			else if (nodeSide == Right && fatherSide == Left)
			{
				printf("RFBU_NSFF!\n");

				return RedFatherBlackUncle_NodeSecondFatherFirst;
			}
			else
			{
				printf("RFBU_NFFS!\n");

				return RedFatherBlackUncle_NodeFirstFatherSecond;
			}
		}
	}
}

TreeNode* InsertNode(Tree* _tree, ElementType _data)
{
	TreeNode* node = GenerateRBTreeNode(_data);
	TreeNode* validPos = GetValidPosition(_tree, node, _NIL);
	if (GetComparedSide(validPos, node) == Left)
	{
		validPos->LeftChild = node;
	}
	else
	{
		validPos->RightChild = node;
	}
	node->Parent = validPos;
	_tree->NumOfNodes++;
	Stablize_BRTree(node, JudgeInsertSituation(node), _tree);
	return node;
}

// ����ڸ�
int CountBlackHeight(TreeNode* _node)
{
	
	int left = _node->LeftChild->BlackHeight + (_node->LeftChild->Color == Black ? 1 : 0);
	int right = _node->RightChild->BlackHeight + (_node->RightChild->Color == Black ? 1 : 0);
	if (left != right)
	{
		/*����Ӧ����һЩ���������׳��쳣*/
		return -1;
	}
	else
	{
		_node->BlackHeight = left;
		return left;
		
	}
}