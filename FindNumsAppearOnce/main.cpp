#include <iostream>
using namespace std;
int FindFirsbitIs1(int &num){
    int index=0;
    while(((num&1)==0)&&(index<8*sizeof(int))){
        num=num>>1;
        index++;
    }
    return index;
}
bool IsBit1(int num,int index){
    num=num>>index;
    return (num&1);
}
void FindNumsAppearOnce(int *data,int length,int &num1,int &num2){
    if(data==NULL||length<2)
        return;
    int tmp=0;
    for(int i=0;i<length;++i)
        tmp^=data[i];
    int index=FindFirsbitIs1(tmp);
    num1=num2=0;
    for(int i=0;i<length;++i){
        if(IsBit1(data[i],index))
            num1^=data[i];
        else
            num2^=data[i];
    }
}
int main() {
    //数组只有两个数出现一次，其他的数出现两次，找出出现一次的数
    int a[]={2,4,3,6,3,2,5,5};
    int x,y;
    FindNumsAppearOnce(a,8,x,y);
    cout<<x<<endl;
    cout<<y<<endl;

    return 0;
}