//
// Created by HkingAuditore on 2019/10/7.
//

#include <stdio.h>
#include <stdlib.h>
#include "2019-9-25 Stack/Stack.h"

//读取单个字符
int ReadSingleChar(char *_input) {
    scanf("%c", _input);
    //输入字符是否为数字
    if ((*_input - '0') >= 0 && (*_input - '0') <= 9) {
        return 0;
    } else if ((*_input == '(') || (*_input == ')')) { /*如果是括号*/
        return 1;
    } else if ((*_input == '+') || (*_input == '-') || (*_input == '*') || (*_input == '/')) {/*如果是运算符*/
        return 2;
    } else if (*_input == '\n') {
        return 3;
    }
    exit(0);
}

//连接多个字符
int ReadChar2Action(Stack *_stack) {
    char input;
    int judge = ReadSingleChar(&input);
    switch (judge) {
        case 0:
            return (input - '0');
        case 1:
            Push(_stack, -1);

            return -1;
        case 2:
            Push(_stack, input);
//            printf("2--*--IN:%d\n",input);
            return -2;
        default:
            return -3;
    }
}

//读取
int Read(Stack *_stack) {
    char read;
    int tempNum=0;
    while ((read = ReadChar2Action(_stack)) != -3) {
        if (read >= 0) {
            tempNum = 10 * tempNum + read;
        }else{
            Push(_stack,tempNum);
//            printf("IN:%d\n",tempNum);
            tempNum =0;
        }
    }
    Push(_stack,tempNum);
    return 0;
}
//输出
int Write(Stack* _stack){
    while (!IsEmptyStack(*_stack)) {
        printf("%d ", Pop(_stack));
    }
}

int main(){
    Stack saver;
    GenerateStack(&saver);
    printf("Input it\n");
    Read(&saver);
    Write(&saver);
}