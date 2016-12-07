//
// Created by jinm32 on 16-12-7.
//

#ifndef HUFFMAN_MIN_HEAP_H
#define HUFFMAN_MIN_HEAP_H

#include<iostream>
using namespace std;
template<class T>
class MinHeap{
    int maxSize;    //最大个数
    int size;       //有效元素个数
    T *heap;    //底层数组
    void shiftUp(int index);//从index节点位置，往根节点调整堆
    void shiftDown(int begin,int end);//从begin节点开始向下调整到end节点
public:
    //构造函数
    MinHeap(int MaxSize=20):maxSize(MaxSize),size(NULL){heap=new T[maxSize];}
    ~MinHeap(){delete []heap;}//析构
    void print();//输出堆
    bool createMinHeap(T a[],int length);//根据指定数组创建最小堆
    bool insert(T val);//插入元素
    bool remove(T &val);//删除堆顶元素，用val带出,一般不推荐这种办法，可以设置一个gettop()函数
};
template <class T>
void MinHeap<T>::print() {
    for(int i=0;i<size;++i){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
template <class T>
void MinHeap<T>::shiftUp(int index) {
    T value=heap[index];    //插入节点的值
    while(index>0){
        int indexParent=(index-1)/2;//父节点位置
        if(heap[indexParent]<=value)
            break;
        else {
            heap[index]=heap[indexParent];
            index=indexParent;
        }
    }
    heap[index]=value;//节点最后插入的位置
}
template <class T>
void MinHeap<T>::shiftDown(int begin, int end) {
    T value=heap[begin];
    int i=begin;
    int j=2*i+1;//左子女位置
    while(j<=end){
        if(j<end&&heap[j]>heap[j+1])++j;//j指向小的子女节点
        if(heap[j]>=value)break;
        else{
            heap[i]=heap[j];i=j;j=2*i+1;
        }
    }
    heap[i]=value;
}
template <class T>
bool MinHeap<T>::remove(T &val) {
    if(size==NULL)return false;
    val=heap[0];
    heap[0]=heap[size-1];
    size--;
    shiftDown(0,size-1);
    return true;
}
template <class T>
bool MinHeap<T>::createMinHeap(T *a, int length) {
    if(length>maxSize)return false;
    for(int i=0;i<length;++i)
        insert(a[i]);
    return true;
}
template <class T>
bool MinHeap<T>::insert(T val) {
    if(maxSize<=size)return false;
    heap[size]=val;
    shiftUp(size);
    ++size;
    return true;
}
#endif //HUFFMAN_MIN_HEAP_H
