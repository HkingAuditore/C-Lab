//
// Created by HkingAuditore on 2019/12/5.
//

#ifndef C_LAB_INPUTCONTROLLER_H
#define C_LAB_INPUTCONTROLLER_H
#define EXITINPUT -128

#include "OutputController.h"

typedef enum inputMode{
    keyboard,file
}InputMode;

static int Read(InputMode _mode){
    if(_mode == 0){
        int result;
        WriteInputTip();
        if(scanf("%d",&result)){
            getchar();
            return result;
        }else{
            getchar();
            return EXITINPUT;
        }




    }
}









#endif //C_LAB_INPUTCONTROLLER_H
