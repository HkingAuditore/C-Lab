//
// Created by HkingAuditore on 2019/12/5.
//

#ifndef C_LAB_OUTPUTCONTROLLER_H
#define C_LAB_OUTPUTCONTROLLER_H

static void WriteInputTip(){
    printf("请输入数据(输入非数字为退出)：\n");
}

static void SwitchLine(){
    printf("\n");
}

static void Write(char* _string){
    printf("%s",_string);
}

static void WriteData(char* _string,int _data){
    printf("%s:%d ",_string,_data);
}

static void WriteTraversalTip(int _mode){
    switch(_mode){
        case 0:
            printf("前序遍历是：\n");
            break;
        case 1:
            printf("中序遍历是：\n");
            break;
        case 2:
            printf("后序遍历是：\n");
            break;
        default:
            printf("没有这种便利方式\n");
            break;
    }
}




#endif //C_LAB_OUTPUTCONTROLLER_H
