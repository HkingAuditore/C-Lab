#ifndef C_LAB_QUEUE_H
#define C_LAB_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
//数据元素
typedef int DataEnum;

//初始化结点
static QueueNode *GenerateNode(DataEnum _data)
{
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));
    if (!node)
    {
        return NULL;
    }
    node->Data = _data;
    node->Next = NULL;
    return node;
}

//初始化队列
static Queue *GenerateQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (!queue)
    {
        return NULL;
    }
    queue->Head = GenerateNode(0);
    queue->CurPos = queue->Head;
    queue->Length = 0;
    return queue;
}

//添加结点
static int Push(Queue *_queue, DataEnum _data)
{
    QueueNode *newNode = GenerateNode(_data);
    if (!newNode)
    {
        return 1;
    }
    _queue->CurPos->Next = newNode;
    _queue->CurPos = newNode;
    _queue->Length++;
    return 0;
}
//是否为空队列
static int IsEmptyQueue(const Queue *_queue)
{
    if (!_queue->Head)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//输出结点
static DataEnum Pop(Queue *_queue)
{
    if (IsEmptyQueue(_queue))
    {
        return -9999;
    }
    int result = _queue->Head->Next->Data;
    QueueNode *node2Pop = _queue->Head->Next;
    _queue->Length--;
    _queue->Head->Next = _queue->Head->Next->Next;
    free(node2Pop);
    return result;
}

// 销毁队列
static int Destroy(Queue *_queue)
{
    while (Pop(_queue) != -9999)
    {
        continue;
    }
    free(_queue);
    return 0;
}
#endif //C_LAB_QUEUE_H