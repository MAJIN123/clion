#include <iostream>
using namespace std;
#include<assert.h>
void Permutation(char *pStr,char *pBegin){
    assert(pBegin&&pStr);
    if(*pBegin == '\0')
        printf("%s\n",pStr);
    else
    {
        for(char* pCh = pBegin; *pCh != '\0'; pCh++)
        {
            swap(*pBegin,*pCh);
            Permutation(pStr, pBegin+1);
            swap(*pBegin,*pCh);
        }
    }
}

int main() {
    char str[]="abc";
    Permutation(str,str);
    return 0;
}