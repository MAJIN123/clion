#include <iostream>
using namespace std;
int GetFirstK(int *a,int length,int k,int start,int end){
    if(start>end)
        return -1;
    int midIndex=(start+end)/2;
    int midData=a[midIndex];
    if(midData==k){
        if(midIndex>0&&a[midIndex-1]!=k||midIndex==0)
            return midIndex;
        else
            end=midIndex-1;
    }
    else if(midData>k){
        end=midIndex-1;
    }
    else
        start=midIndex+1;
    return GetFirstK(a,length,k,start,end);
}
int GetLastK(int *a, int length,int k,int start,int end){
    if(start>end)
        return -1;
    int midIndex=(start+end)/2;
    int midData=a[midIndex];
    if(midData==k){
        if(midIndex<end&&a[midIndex+1]!=k||midIndex==end)
            return midIndex;
        else
            start=midIndex+1;
    }
    else if(midData>k)
        end=midIndex-1;
    else
        start=midIndex+1;
    return GetLastK(a,length,k,start,end);
}
int GetNumberOfK(int *a,int length,int k){
    int number;
    if(a&&length>0) {
        int p = GetFirstK(a, length, k, 0, length - 1);
        int q = GetLastK(a, length, k, 0, length - 1);
        if (q >= -1 && q >= -1)
            number = q - p + 1;
    }
    return number;
}
int main() {
    //数组有序，对于给定的K，得到在数组中出现的次数
    int a[10]={1,2,3,3,3,5,5,7,7,7};
    cout<<GetNumberOfK(a,10,5);
    return 0;
}