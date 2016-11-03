#include <iostream>
using namespace std;
//直接选择排序小到大（n 个数）
//在前n-1次循环中，每次找出最小的放到前面
//O(n^2),不稳定排序
void Select_sort(int *a,int len){
    for(int i=0;i<len-1;++i){
        int flag=i;
        for(int j=i;j<len;++j){
            if(a[i]>a[j])
                flag=j;
        }
        if(flag!=i){
            swap(a[i],a[flag]);
        }
    }
}
int main() {
    int a[]={2,3,62,43,2,95};
    for(int i=0;i<6;++i)
        cout<<a[i]<<" ";
    cout<<endl;
    Select_sort(a,6);
    for(int i=0;i<6;++i)
        cout<<a[i]<<" ";
    cout<<endl;

}