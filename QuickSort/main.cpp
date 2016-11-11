#include <iostream>
using namespace std;
void QuickSort(int a[],int left,int right){
    if(left>=right)
        return;
    int first=left;
    int last=right;
    int key=a[first];       /*用字表的第一个记录作为枢轴*/
    while (first<last){
        while(a[last]>key&&first<last)
            --last;
        a[first]=a[last];       /*将比第一个小的移到低端*/
        while(first<last&&a[first]<key)
            ++first;
        a[last]=a[first];      /*将比第一个大的移到高端*/
    }
    a[first]=key;           /*枢轴记录到位*/
    QuickSort(a,left,first-1);
    QuickSort(a,first+1,right);
}
void sort(int *a, int left, int right)
{
    if(left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];

    while(i < j)                               /*控制在当组内寻找一遍*/
    {
        while(i < j && key <= a[j])
            /*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
            序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/
        {
            j--;/*向前寻找*/
        }

        a[i] = a[j];
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
        a[left]，那么就是给key）*/

        while(i < j && key >= a[i])
            /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
            因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            i++;
        }

        a[j] = a[i];
    }

    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    sort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    sort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
    /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}
int main() {
    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};

    sort(a, 0, sizeof(a) / sizeof(a[0]) - 1);  /*这里第三个参数要减1否则内存越界*/

    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        cout << a[i] << " ";
    cout<<endl;
    QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);  /*这里第三个参数要减1否则内存越界*/

    for(int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        cout << a[i] << " ";
    return 0;
}