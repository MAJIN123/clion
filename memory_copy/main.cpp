#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;
/*内存拷贝，拷贝size长度*/
void* memcopy(void *des,const void *src,int size){
    assert(src&&des);
    char *Src=(char*)src;
    char *Des=(char*)des;
    int len=strlen(Src);
    //assert(size>0&&len>size);
    if(Des>Src&&Des<Src+size){
        //内存重叠
        Src=Src+size;
        Des=Des+size;
        while(size){
            *Des--=*Src--;
            --size;
        }
    }
    else{
        while(size){
            *Des++=*Src++;
            --size;
        }
    }
    return des;
}

int main() {
    char s[]="Hello world!";
    char t[30];
    int size=strlen(s);
    memcopy(&t,&s,size);
    cout<<t;
    return 0;
}