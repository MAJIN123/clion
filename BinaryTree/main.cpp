#include <iostream>
using namespace std;
template <class T>
struct BinTreeNode{
    T data;
    BinTreeNode<T> *leftChild,*rightChild;
    BinTreeNode():leftChild(NULL),rightChild(NULL){}
    BinTreeNode(T x,BinTreeNode<T> *l=NULL,BinTreeNode<T> *r=NULL)
            :data(x),leftChild(l),rightChild(r){}
};
template <class T>
class BinaryTree{
protected:
    BinTreeNode<T> *root;
    T RefValue;             //数据输入停止标签
    void destroy(BinTreeNode<T>* &subTree);       //删除
    int Height(BinTreeNode<T> *subTree);
    int Size(BinTreeNode<T> *subTree);
    BinTreeNode<T>* Parent(BinTreeNode<T>* subTree,BinTreeNode<T>* current);
public:
    BinaryTree():root(NULL){}               //构造函数
    BinaryTree(T value):RefValue(value),root(NULL){}        //构造函数
    BinaryTree(BinaryTree<T> &s);
    ~BinaryTree(){destroy(root);}
    int Height(){return Height(root);}
    int Size(){return Size(root);}
    BinTreeNode<T>* Parent(BinTreeNode<T> *current){
        return(root==NULL||root==current)?NULL:Parent(root,current);
    }
    BinTreeNode<T>* LeftChild(BinTreeNode<T> *current){
        return (current!=NULL)?current->leftChild:NULL;
    }
    BinTreeNode<T>* RightChild(BinTreeNode<T> *current){
        return (current!=NULL)?current->rightChild:NULL;
    }
    BinTreeNode<T>* getRoot()const{return root;}

};
template <class T>
BinTreeNode<T>* BinaryTree<T>::Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current) {
    if(subTree==NULL)return NULL;
    if(subTree->leftChild==current||subTree->rightChild==current)
        return subTree;
    BinTreeNode<T> *p;
    if((p=Parent(subTree->leftChild,current))!=NULL)return p;
    else return Parent(subTree->rightChild,current);
}
template <class T>
int BinaryTree<T>::Size(BinTreeNode<T> *subTree) {
    if(subTree==NULL)
        return 0;
    else {
        return 1+Size(subTree->leftChild)+Size(subTree->rightChild);
    }
}
template <class T>
int BinaryTree::Height(BinTreeNode<T> *subTree) {
    if(subTree==NULL)
        return 0;
    else {
        int i=Height(subTree->leftChild);
        int j=Height(subTree->rightChild);
        return (i<j)?j+1:i+1;
    }


}
template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &s) {

}
template <class T>
void BinaryTree<T>::destroy(BinTreeNode<T>* &subTree) {
    if(subTree!=NULL){
        destroy(subTree->leftChild);
        destroy(subTree->rightChild);
        delete subTree;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}