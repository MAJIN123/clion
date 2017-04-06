#include <iostream>
using namespace std;
#include<stack>
bool IsPopOrder(int *pPush,int *pPop,int length){
    bool Possible=false;
    if(pPop!=NULL&&pPush!=NULL&&length>0){
        const int* pNextPush=pPush;
        const int* pNextPop=pPop;
        stack<int> stackData;
        while(pNextPop-pPop<length){
            while(stackData.empty()||stackData.top()!=*pNextPop){
                if(pNextPush-pPush==length)
                    break;
                stackData.push(*pNextPush);
                pNextPush++;
            }
            if(stackData.top()!=*pNextPop)
                break;
            stackData.pop();
            pNextPop++;
        }
        if(stackData.empty()&&pNextPop-pPop==length)
            Possible=true;
    }
    return Possible;
}
int main() {
    int a[]={1,2,3,4,5};
    int b[]={5,4,3,2,1};
    cout<<IsPopOrder(a,b,5);
    return 0;
}