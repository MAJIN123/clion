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
class LinkedStack{
protected:
    LinkNode<T>* top;
public:
    LinkedStack():top(NULL){}         //构造函数
    ~LinkedStack(){makeEmpty();}     //析构函数
    void push(const T& x);          //进栈
    bool pop(T& x);                 //出栈
    void makeEmpty();               //清空
    bool gettop(T& x)const{if(IsEmpty())return false;x=top->data;return true;}
    bool IsEmpty()const{return(top==NULL)?true:false;}
    int getSize();
    friend ostream& operator<<(ostream& os,LinkedStack<T>& L){
        LinkNode<T>* p=L.top;
        int i=0;
        while(p!=NULL){
            cout<<++i<<":"<<p->data<<endl;
            p=p->link;
        }
        return os;
    }
};
template <class T>
int LinkedStack<T>::getSize() {
    LinkNode<T>* p=top;
    int i=0;
    while(p!=NULL){
        i++;
        p=p->link;
    }
    return i;
}
template <class T>
bool LinkedStack<T>::pop(T &x) {
    if(IsEmpty())return false;
    LinkNode<T>* p=top;
    top=top->link;
    delete p;
    return true;
}
template <class T>
void LinkedStack<T>::push(const T &x) {
    top=new LinkNode<T>(x,top);
}
template <class T>
void LinkedStack<T>::makeEmpty() {
    LinkNode<T>* p;
    while(top!=NULL){
        p=top;
        top=top->link;
        delete p;
    }
}
int main() {
    LinkedStack<int> L;
    int x,y;
    L.push(5);
    L.push(8);
    L.push(10);
    y=L.getSize();
    cout<<"size"<<y<<endl;
    cout<<L;
    L.pop(x);
    cout<<x<<endl;
    cout<<L;
}