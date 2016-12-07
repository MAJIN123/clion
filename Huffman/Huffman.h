//
// Created by jinm32 on 16-12-7.
//

#ifndef HUFFMAN_HUFFMAN_H
#define HUFFMAN_HUFFMAN_H

#include<iostream>
#include<Min_heap>


struct HuffmanNode{
    float data;
    HuffmanNode *Lchild,*Rchild,*Parent;
    HuffmanNode():Lchild(NULL),Rchild(NULL),Parent(NULL){}
};

#endif //HUFFMAN_HUFFMAN_H