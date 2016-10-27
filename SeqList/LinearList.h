//
// Created by jinm32 on 16-10-27.
//

#ifndef SEQLIST_LINEARLIST_H
#define SEQLIST_LINEARLIST_H

#endif //SEQLIST_LINEARLIST_H
template <class T>
class LinearList{
public:
    LinearList();
    LinearList(LinearList<T>& L);
    ~LinearList();
    virtual bool IsEmpty()=0;
    virtual bool IsFull()=0;
    virtual int Size()const=0;
    virtual int Length()const=0;
    virtual int Search(T& x)=0;
    virtual bool Remove(int i,T& x)=0;
    virtual bool Insert(int i,T& x)=0;
    virtual void input()=0;
    virtual void output()=0;
};