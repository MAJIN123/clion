//
// Created by jinm32 on 16-12-7.
//

#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H

#include<iostream>
#include"Min_Heap.h"

//树节点类定义
struct HuffmanNode{
    float data;
    HuffmanNode *Lchild,*Rchild,*Parent;
    HuffmanNode():Lchild(NULL),Rchild(NULL),Parent(NULL){}//构造函数
    HuffmanNode(float elem,HuffmanNode *L=NULL,HuffmanNode *R=NULL,HuffmanNode *P=NULL)
            :data(elem),Lchild(L),Rchild(R),Parent(P){}//构造函数
    bool operator<=(HuffmanNode *R){return data<=R->data;}
    bool operator>(HuffmanNode *R){return data>R->data;}
};

class Huffman{
protected:
    HuffmanNode *root;
    void delete_Tree(HuffmanNode *root);//删除以t为根的子树
    void PreOrder(HuffmanNode *root);//前序遍历输出
public:
    Huffman():root(NULL){}//构造函数
    Huffman(float w[],int len);//构造函数
    ~Huffman(){delete_Tree(root);}//析构函数
    void PreOrder(){PreOrder(root);}//前序遍历输出以root为根的Huffman树
    void merge(HuffmanNode &first,HuffmanNode &second,HuffmanNode *&Parent);//合并子树到parent
};
void Huffman::PreOrder(HuffmanNode *root) {
    cout<<"PreOrder:";
    while(root){
        cout<<root->data<<" ";
        PreOrder(root->Lchild);
        PreOrder(root->Rchild);
    }
    cout<<endl;
}
Huffman::Huffman(float *w, int len) {
    MinHeap<float> hp;         //定义一个最小堆
    HuffmanNode first,second;
    HuffmanNode *Parent;
    for(int i=0;i<len;++i){
        hp.insert(w[i]);
    }
    float s1,s2;
    for(int i=0;i<len-1;++i){
        hp.remove(s1);
        hp.remove(s2);
        first.data=s1;first.Rchild=first.Lchild=NULL;
        second.data=s2;second.Rchild=second.Lchild=NULL;
        merge(first,second,Parent);
        hp.insert((*Parent).data);
    }
    root=Parent;//建立根节点
}
void Huffman::merge(HuffmanNode &first, HuffmanNode &second, HuffmanNode *&Parent) {
    Parent=new HuffmanNode;
    Parent->Lchild=&first;
    Parent->Rchild=&second;
    Parent->data=first.data+second.data;
    first.Parent=second.Parent=Parent;
}
void Huffman::delete_Tree(HuffmanNode *root) {
    while(root){
        delete_Tree(root->Lchild);
        delete_Tree(root->Rchild);
        delete root;
    }
}

#endif //HUFFMAN_HUFFMAN_H