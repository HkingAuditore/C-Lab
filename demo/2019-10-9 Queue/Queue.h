#include <stdio.h>
#include <stdlib.h>

//数据元素
typedef int DataEnum;

//单个队列节点
typedef struct queueNode {
//    数据存储
    DataEnum Data;
//    下一节点指针
    struct queueNode *Next;
} QueueNode;

//队列
typedef struct queue {
//    头
    QueueNode *Head;
//    当前位置
    QueueNode *CurPos;
//    队列长度
    int Length;
} Queue;

//初始化结点
QueueNode *GenerateNode(DataEnum _data) {
    QueueNode *node = (QueueNode *) malloc(sizeof(QueueNode));
    if (!node) {
        return NULL;
    }
    node->Data = _data;
    node->Next = NULL;
    return node;
}

//初始化队列
Queue *GenerateQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if (!queue) {
        return NULL;
    }
    queue->Head = GenerateNode(0);
    queue->CurPos = queue->Head;
    queue->Length = 0;
    return queue;
}

//添加结点
int Push(Queue *_queue, DataEnum _data) {
    QueueNode *newNode = GenerateNode(_data);
    if (!newNode) {
        return 1;
    }
    _queue->CurPos->Next = newNode;
    _queue->CurPos = newNode;
    _queue->Length++;
    return 0;
}
//是否为空队列
int IsEmptyQueue(const Queue* _queue ){
    if(!_queue->Head){
        return 1;
    }else{
        return 0;
    }
}
//输出结点
DataEnum Pop(Queue *_queue) {
    if(IsEmptyQueue(_queue)){
        return -9999;
    }
    int result = _queue->Head->Next->Data;
    QueueNode* node2Pop = _queue->Head->Next;
    _queue->Length--;
    _queue->Head->Next = _queue->Head->Next->Next;
    free(node2Pop);
    return result;
}