//
// Created by HkingAuditore on 2019/12/5.
//

#ifndef C_LAB_OUTPUTCONTROLLER_H
#define C_LAB_OUTPUTCONTROLLER_H

static void WriteInputTip(){
    printf("����������(���������Ϊ�˳�)��\n");
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
            printf("ǰ������ǣ�\n");
            break;
        case 1:
            printf("��������ǣ�\n");
            break;
        case 2:
            printf("��������ǣ�\n");
            break;
        default:
            printf("û�����ֱ�����ʽ\n");
            break;
    }
}




#endif //C_LAB_OUTPUTCONTROLLER_H
