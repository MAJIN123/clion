#include <iostream>
using namespace std;
//直接插入排序
//O(n^2) 稳定排序
void InsertSort1(int *a,int len){
    for(int i=1;i<len;++i){
        int temp=a[i];
        if(a[i]<a[i-1]){
            int count=0;
            while(i>0&&a[i-1]>temp){
                a[i]=a[i-1];
                a[i-1]=temp;
                i--;count++;
            }//end if
        i+=count;
        }//end for
    }
}
void InsertSort2(int *a,int len){
    int i,j;
    for(i=1;i<len;++i){
        if(a[i]<a[i-1]){
            int temp=a[i];
            for(j=i;j>0&&a[j]>temp;--j)
                a[j]=a[j-1];
            a[j+1]=temp;
        }
    }
}
int main() {
    int a[]={2,34,56,7,32,2,5,3};
    for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    InsertSort1(a,8);
    for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    InsertSort2(a,8);
    for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
    return 0;
}