#include <iostream>
using namespace std;
int FindFirstBitIs1(int x){
    int index=0;
    while((x&1)==0&&index<8*sizeof(int)){
        x=x>>1;
        ++index;
    }
    return index;
}
bool IsBit1(int x,int index){
    x=x>>index;
    return (x&1);
}
void FindNumsAppearOnce(int *data,int length,int &num1,int &num2){
    if(data==NULL||length<2)
        return;
    int result=0;
    for(int i=0;i<length;++i)
        result=result^data[i];
    int indexOf1=FindFirstBitIs1(result);
    for(int j=0;j<length;++j){
        if(IsBit1(data[j],indexOf1))
            num1^=data[j];
        else
            num2^=data[j];
    }
}

int main() {
    int a[10]={1,2,3,3,5,5,6,7,7,6};
    int x=0;
    int y=0;
    FindNumsAppearOnce(a,10,x,y);
    cout<<x<<y;
    return 0;
}