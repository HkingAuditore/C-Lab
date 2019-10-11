//
// Created by HkingAuditore on 2019/10/11.
//

#ifndef C_LAB_EVENTMANAGER_H
#define C_LAB_EVENTMANAGER_H

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "SystemBase.h"

//对象
typedef struct object {
    int Id;
    int Level;
    /*Maybe more property...*/
} Object;


//事件
typedef struct event {
    Object EventObject;
    int RegisterTime;
    /*Maybe more property...*/
} Event;

//typedef Event DataEnum;
typedef Event DataEnum;
//单个队列节点
typedef struct queueNode {
    DataEnum Data;    //    数据存储
    struct queueNode *Next;    //    下一节点指针
} QueueNode;

//队列
typedef struct queue {
    QueueNode *Head;    //    头
    QueueNode *CurPos;    //    当前位置
    int Length;    //    队列长度
} Queue;


DataEnum _EmptyEnum = {{0, 0}, 0};

//初始化结点
static QueueNode *GenerateNode(DataEnum _data) {
    QueueNode *node = (QueueNode *) malloc(sizeof(QueueNode));
    if (!node) {
        return NULL;
    }
    node->Data = _data;
    node->Next = NULL;
    return node;
}

//初始化队列
static Queue *GenerateQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if (!queue) {
        return NULL;
    }
    queue->Head = GenerateNode(_EmptyEnum);
    queue->CurPos = queue->Head;
    queue->Length = 0;
    return queue;
}

//添加结点
static int Push(Queue *_queue, DataEnum _data) {
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
static int IsEmptyQueue(const Queue *_queue) {
    if (!_queue->Head->Next) {
        return 1;
    } else {
        return 0;
    }
//    if (_queue->Length==0) {
//        return 1;
//    } else {
//        return 0;
//    }
}

//输出结点
static DataEnum Pop(Queue *_queue) {
    if (IsEmptyQueue(_queue)) {
        return (DataEnum) {{-1,-1}, 0};
    }
    DataEnum result = _queue->Head->Next->Data;
    QueueNode *node2Pop = _queue->Head->Next;
    _queue->Length--;
    _queue->Head->Next = _queue->Head->Next->Next;
    free(node2Pop);
    if(_queue->Head->Next==NULL){
        _queue->CurPos=_queue->Head;
    }
    return result;
}

// 销毁队列
static int Destroy(Queue *_queue) {
    while (Pop(_queue).EventObject.Id != -1);
    free(_queue);
    return 0;
}

//获取随机的间隔时间
static void PassRandomTime(int *_time, int _min, int _max) {
    *_time += (GetRandom(_max - _min) + _min);
}


//生成一个随机事件
static Event GenerateEvent(int _id, int _maxLevel, int* _time, int _min, int _max) {
    Object instanceObj = {_id, GetRandom(_maxLevel)};
    PassRandomTime(_time,_min,_max);
    Event instanceEvent = {instanceObj, *_time};
    return instanceEvent;
}

//向事件流注册一个随机事件
static int RegisterEvent(Queue *_eventFlow, int _id, int _maxLevel, int* _Time, int _min, int _max) {
    return Push(_eventFlow, GenerateEvent(_id, _maxLevel, _Time, _min, _max));
}

#endif //C_LAB_EVENTMANAGER_H
