//
// Created by HkingAuditore on 2019/10/9.
//
#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    printf("Test!\n");
    Queue* queuetest = GenerateQueue();
    printf("Input:");
    for(int i=0;i<10;i++){
        printf("%d ",i);
        Push(queuetest,i);
    }
    printf("\nOutput:");
    for(int i=0;i<10;i++){
        printf("%d ",Pop(queuetest));
    }
}