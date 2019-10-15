//
// Created by HkingAuditore 2019/10/15.
//

#include "String.h"

int main(){
    String* str =GenerateString("I love AMD AMD AMD AMD AMD AMD,AMD YES!");
    WriteString(*str);
    printf("length is %d\n",str->Length);
    Add2String(str,"AMD YES!");
    WriteString(*str);
    printf("length is %d\n",str->Length);
    Replace(str,"AMD","NVIDIA");
    WriteString(*str);
    printf("length is %d\n",str->Length);

}