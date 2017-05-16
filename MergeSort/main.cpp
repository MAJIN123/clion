#include <iostream>
using namespace std;
void Merge(int *a,int l,int mid,int r,int *tmp);
void MergeSort(int *a,int l,int r,int *tmp);
void sort(int *a,int n);
template <class T>
int getArrayLen(T& array) {//使用模板定义一 个函数getArrayLen,该函数将返回数组array的长度
    return (sizeof(array) / sizeof(array[0]));
}

int main() {
    int a[] = {8, 4, 5, 9};
    cout << sizeof(a);
    int n = getArrayLen(a);
    sort(a, n);
    return 0;
}
/**
 *
    归并排序的时间复杂度是O(NLogN)，空间复杂度是O(N)。

    辅助数组是一个共用的数组。如果在每个归并的过程中都申请一个临时数组会造成比较大的时间开销。

    归并的过程需要将元素复制到辅助数组，再从辅助数组排序复制回原数组，会拖慢排序速度。
 * @param a
 * @param n
 */
void sort(int *a,int n) {
    int tmp[n];
    MergeSort(a, 0, n - 1, tmp);
}
void MergeSort(int *a,int l,int r,int *tmp) {

    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    MergeSort(a, l, mid, tmp);
    MergeSort(a, mid + 1, r, tmp);
    Merge(a, l, mid, r, tmp);
}
void Merge(int *a,int l,int mid,int r,int *tmp) {
    for (int i = l; i <= r; ++i)
        tmp[i] = a[i];
    int p = l, q = mid + 1;
    for (int i = l; i <= r; ++i) {
        if (p > mid)a[i] = tmp[q++];
        else if (q > r)a[i] = tmp[p++];
        else if (tmp[p] < tmp[q])a[i] = tmp[p++];
        else a[i] = tmp[q++];
    }
}