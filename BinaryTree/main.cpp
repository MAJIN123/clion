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
    BinTreeNode<T> *copy(BinTreeNode<T> *root);
    BinTreeNode<T>* Parent(BinTreeNode<T>* subTree,BinTreeNode<T>* current);
    void PreOrder(BinTreeNode<T> *root);            //前序遍历
    void InOrder(BinTreeNode<T> *root);              //中序便利
    void PostOrder(BinTreeNode<T> *root);           //后序便利
    void Travers(BinTreeNode<T>* subTree,ostream& out); //前序遍历输出
    friend ostream& operator<<(ostream& out,BinaryTree<T> &Tree){
        //重载输出
        out<<"二叉树前序遍历输出：\n";
        Tree.Travers(Tree.root,out);
        out<<endl;
        return out;
    }

public:
    BinaryTree():root(NULL){}               //构造函数
    BinaryTree(T value):RefValue(value),root(NULL){}        //构造函数
    BinaryTree(BinaryTree<T> &s);                   //复制构造函数
    ~BinaryTree(){destroy(root);}                   //析构函数
    int Height(){return Height(root);}
    int Size(){return Size(root);}
    void PreOrder(){PreOrder(root);}
    void InOrder(){InOrder(root);}
    void PostOrder(){PostOrder(root);}
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
void BinaryTree<T>::Travers(BinTreeNode<T> *subTree, ostream &out) {
    if(subTree){
        out<<subTree->data<<" ";
        Travers(subTree->leftChild,out);
        Travers(subTree->rightChild,out);
    }
}
template <class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T> *root) {
    if(!root)
        return;
    cout<<root->data<<" ";
    PreOrder(root->leftChild);
    PreOrder(root->rightChild);
}
template <class T>
void BinaryTree<T>::InOrder(BinTreeNode<T> *root) {
    if(root){
        InOrder(root->leftChild);
        cout<<root->data<<" ";
        InOrder(root->rightChild);
    }
}
template <class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T> *root) {
    if(root){
        PostOrder(root->leftChild);
        PostOrder(root->rightChild);
        cout<<root->data<<" ";
    }
}
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
        root=copy(s.root);
}
template <class T>
BinTreeNode<T>* BinaryTree<T>::copy(BinTreeNode<T> *root) {
    if(!root)
        return NULL;
    BinTreeNode<T> *p=new BinTreeNode<T>;
    p->data=root->data;
    p->leftChild=copy(root->leftChild);
    p->rightChild=copy(root->rightChild);
    return p;
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