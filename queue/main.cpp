#include <iostream>
using namespace std;
const int defaultSize=20;
template <class T>
class Queue{
protected:
    int rear,front;
    T *element;
    int maxSize;
public:
    Queue(int sz=defaultSize):front(0),rear(0),maxSize(sz)  //构造函数
        {element=new T[maxSize];}
    ~Queue(){delete []element;}         //析构函数
    bool EnQueue(const T& x);           //进队列
    bool DeQueue(T& x);                 //出队列
    bool IsFull()const{return((rear+1)%maxSize==rear)?true:false;}
    bool IsEmpty()const{return(rear==front)?true:false;}
    bool getFront(T& x);                //返回队头的元素  x带出
    friend ostream& operator<<(ostream& os,Queue<T>& L){
        os<<"front:"<<L.front<<"rear:"<<L.rear<<endl;
        for(int i=L.front;i!=L.rear;i=(i+1)%L.maxSize){
            os<<i<<":"<<L.element[i]<<endl;
        }
        return os;
    }
};
template <class T>
bool Queue<T>::getFront(T &x) {
    if(IsEmpty())return false;
    x=element[front];
    return true;
}
template <class T>
bool Queue<T>::DeQueue(T &x) {
    if(IsEmpty())return false;
    x=element[front];
    front=(front+1)%maxSize;
    return true;
}
template <class T>
bool Queue<T>::EnQueue(const T &x) {
    if(IsFull())return false;
    element[rear]=x;
    rear=(rear+1)%maxSize;
    return true;
}
int main() {
    Queue<int> Q;
    Q.EnQueue(20);
    Q.EnQueue(19);
    Q.EnQueue(18);
    cout<<Q;
    int x;
    Q.DeQueue(x);
    cout<<Q;
}