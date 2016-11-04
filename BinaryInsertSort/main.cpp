#include <iostream>
//稳定排序，O(nlogn)
using namespace std;
void BinaryInsertSort(int a[],int len){
    for(int i=1;i<len;++i){
        int low=0,high=i-1,temp;
        temp=a[i];
        while(low<=high){
            int middle=(low+high)/2;
            if(temp<=a[middle]){
                high=middle-1;
            }
            else low=middle+1;
        }
        int k;
        for(k=i-1;k>=low;--k){
            a[k+1]=a[k];
        }
        a[low]=temp;
    }
}
int main() {
    int a[]={1,4,3,8,1,3,5,44,3,2,32,4,2};
    for(int i=0;i<13;++i)
        cout<<a[i]<<" ";
    cout<<endl;
    BinaryInsertSort(a,13);
    for(int i=0;i<13;++i)
        cout<<a[i]<<" ";
    return 0;
}