#include <iostream>
using namespace std;
template <class T>
struct LinkNode{
    T data;
    LinkNode<T> *link;
    LinkNode(LinkNode<T> *ptr=NULL){link=ptr;}
    LinkNode(T x,LinkNode<T> *ptr=NULL){link=ptr;data=x;}

};
template <class T>
class List{
protected:
    LinkNode<T> *first;
public:
    List(){first=new LinkNode<T>;}        //构造函数
    List(T x){first=new LinkNode<T>(x);}
    List(List<T>& L);                   //拷贝构造函数
    ~List(){makeEmpty();}                   //析构函数
    void makeEmpty();                       //清空
    LinkNode<T>* getHead()const{return first;}      //
    LinkNode<T>* Search(T x);               //查找元素X，返回元素节点位置
    LinkNode<T>* Locate(int i)const;             //定位
    bool Insert(int i,T x);             //将x插在第i个元素后
    bool getData(int i,T& x)const;
    void setData(int i,T x);
    bool Remove(int i,T& x);            //删第i个元素 用x 带出

};
template <class T>
bool List<T>::Remove(int i, T &x) {
    LinkNode<T>* current=Locate(i-1);
    if(current==NULL||current->link==NULL)return false;
    LinkNode<T>* del=current->link;
    current->link=del->link;
    x=del->data;
    delete del;
    return true;
}
template <class T>
void List<T>::setData(int i, T x) {
    LinkNode<T>* current=Locate(i);
    if(current==NULL)
        return ;
    current->data=x;
    return ;
}
template <class T>
bool List<T>::getData(int i, T &x) const {
    LinkNode<T>* current=Locate(i);
    if(current==NULL)return false;
    x=current->data;
    return true;
}
template <class T>
bool List<T>::Insert(int i, T x) {
    LinkNode<T>* current=Locate(i);
    if(!current)return false;
    LinkNode<T>* p=new LinkNode<T>(x);
    p->link=current->link;
    current->link=p;
    return true;
}
template <class T>
LinkNode<T>* List<T>::Locate(int i) const{
    if(i<1)return NULL;
    int k=1;
    LinkNode<T>* p=first;
    while(k<=i&&!p->link){
        p=p->link;
        k++;
    }
    return p;
}
template <class T>
LinkNode<T>* List<T>::Search(T x)  {
    LinkNode<T>* p=first->link;
    while(!p){
        if(p->data==x)
            return p;
        p=p->link;
    }
    return NULL;
}
template <class T>
List<T>::List(List<T> &L) {
    T value;
    LinkNode<T> *p=L.getHead();
    LinkNode<T> *q=first=new LinkNode<T>();
    while(!p->link){
        value=p->data;
        q->link=new LinkNode<T>(value);
        q=q->link;
        p=p->link;
    }
    q->link=NULL;
}
template <class T>
void List<T>::makeEmpty() {
    LinkNode<T> p=NULL;
    while(first->link!=NULL){
        p=first->link;
        first->link=p.link;             //any question?
        delete p;
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}