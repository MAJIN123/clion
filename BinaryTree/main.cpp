#include <iostream>
#include<fstream>
#include <stack>
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
    void Insert(BinTreeNode<T> *&root,T x);//插入
    void Norecursive_PreOrder(BinTreeNode<T>* root);//非递归前序遍历
   // void CreateBinaryTree(fstream& in,BinTreeNode<T>* &subTree);//建立二叉树
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
    void Norecursive_PreOrder(){Norecursive_PreOrder(root);}//非递归前序遍历
    void InOrder(){InOrder(root);}
    void PostOrder(){PostOrder(root);}
    void Insert(T x){Insert(root,x);}
    /*
    void CreateBinaryTree(fstream& in){
        CreateBinaryTree(in,root);
    }//建立二叉树
     */
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
/*
template <class T>
void BinaryTree<T>::CreateBinaryTree(fstream &in, BinTreeNode<T> * &subTree) {
    T item;
    if(!in.eof()){
        in>>item;
        if(item!=RefValue){
            subTree=new BinTreeNode<T>(item);
            CreateBinaryTree(in,subTree->leftChild);
            CreateBinaryTree(in,subTree->rightChild);
        }
        else subTree=NULL;

    }
}
 */
template <class T>
void BinaryTree<T>::Norecursive_PreOrder(BinTreeNode<T> *root) {
    /*
    stack<BinTreeNode<T> *>s;       //第一种方法
    s.push(NULL);
    BinTreeNode<T>* p=root;
    while(p){
        cout<<p->data<<" ";
        if(p->rightChild)s.push(p->rightChild);
        if(p->leftChild)p=p->leftChild;
        else {
            p=s.top();
            s.pop();
        }
    }
    cout<<endl;
    */
    stack<BinTreeNode<T> *> S;
    BinTreeNode<T> *p;
    S.push(root);
    while(S){
        p=S.top();
        S.pop();
        cout<<p->data<<" ";
        if(p->rightChild)S.push(p->rightChild);
        if(p->leftChild)S.push(p->leftChild);
    }
}
template<class T>
void BinaryTree<T>::Insert(BinTreeNode<T> *&root, T x) {
    if(root==NULL){
        BinTreeNode<T> *p=new BinTreeNode<T>(x);
        root=p;
    }
    else{
        if(Height(root->leftChild)>Height(root->rightChild)){
            Insert(root->rightChild,x);
        }
        else{
            Insert(root->leftChild,x);
        }
    }
}
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
int BinaryTree<T>::Height(BinTreeNode<T> *subTree) {
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
    BinaryTree<int> p;
    p.Insert(3);
    p.Insert(4);
    p.Insert(1);
    p.PreOrder();
    p.Norecursive_PreOrder();


}