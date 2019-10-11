//
// Created by HkingAuditore on 2019/10/11.
//
#include <stdlib.h>
#include <stdio.h>
#include "EventManager.h"

int _MaxItem = 20;
static int _Clock = 0;

//是否满足游戏人数条件
int IsPlayerEnough(Queue* _gameQueue,int _maxPlayer){
    if(_gameQueue->Length == _maxPlayer){
        return 1;
    }else{
        return 0;
    }
}
//输出玩家等待时间
void PrintPlayerInfo(Event _player){
    printf("No.%d LEVEL:%d Wait %d TIME\n",_player.EventObject.Id,_player.EventObject.Level,_Clock-_player.RegisterTime);
}
//组队成功与排出队列
int GameStart(Queue* _gameQueue,int _maxPlayer){
    for (int i = 0; i < _maxPlayer; ++i) {
        PrintPlayerInfo(Pop(_gameQueue));
//        printf("now time:%d now length:%d\n",_Clock,_gameQueue->Length);
    }
    printf("---------START--------\n");
}

int main() {
    InitRandSeed();
    Queue *gameQueue = GenerateQueue();

    for (int i = 0; i < 10; i++) {
//        printf("now at %d\n",i);
        RegisterEvent(gameQueue, i, _MaxItem, &_Clock, 1, 5);
        if(IsPlayerEnough(gameQueue,5)){
            GameStart(gameQueue,5);
        }
    }
//    while (!IsEmptyQueue(gameQueue)){
//        Event temp = Pop(gameQueue);
//        printf("No.%d LEVEL :%d  ,instanced at : %d TIME\n",temp.EventObject.Id,temp.EventObject.Level,temp.RegisterTime);
//    }


}