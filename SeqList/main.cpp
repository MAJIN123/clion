#include <iostream>
#include "LinearList.h"
using namespace std;
const int defaultSize=100;
template <class T>
class SeqList{
protected:
    T *data;
    int maxSize;
    int last;
public:
    SeqList(int sz=defaultSize);         //构造函数
    SeqList(SeqList<T>& L);             //赋值构造函数
    ~SeqList(){delete []data;}          //析构函数
    int Length()const{return last+1;}        //目前长度
    int Size()const{return maxSize;}         //最大长度
    bool getData(int i,T& x)const{if(i>=0&&i<=last+1){x=data[i];return true;}return false;}//取第i个值给x
    int Search(T& x);                   //找x ，返回X的位置(第多少个)
    bool Insert(int i,T& x);            //插入函数，o<<i<<last+1;,插在i个之后
    bool Remove(int i,T& x);            //删除第i个元素，用x带出
    bool IsEmpty(){return (last==-1)? true:false;}  //判空
    bool IsFull(){return (last==maxSize-1)?true:false;}//判满
    void input();
    void output();

};
template <class T>
void SeqList<T>::output() {
    cout<<"元素最后位置是："<<last<<endl;
    for(int i=0;i<last;i++){
        cout<<"#"<<i+1<<":"<<data[i]<<endl;
    }
};
template <class T>
void SeqList<T>::input() {
    cout<<"开始建立，请输入元素个数:"<<endl;
    while(1){
        cin>>last;
        if(last>0&&last<maxSize)break;
        if(last<0||last>maxSize)
            cout<<"个数不能超过"<<maxSize<<":"<<endl;
    }
    cout<<"请输入元素："<<endl;
    for(int i=0;i<last;i++){
        cout<<i+1<<":";
        cin>>data[i];
        cout<<endl;
    }
}
template <class T>
bool SeqList<T>::Remove(int i, T &x) {
    if(i<1||i>last+1)return false;
    x=data[i-1];
    for(int j=i-1;j<last;j++)
        data[j]=data[j+1];
    last--;
    return true;
}
template <class T>
bool SeqList<T>::Insert(int i, T &x) {
    if(i<0||i>last+1)return false;
    for(int j=last;j>=i;j--){
        data[j+1]=data[j];
    }
    data[i]=x;
    last++;
    return true;
}

template <class T>
int SeqList<T>::Search(T &x) {
    for(int i=0;i<=last;i++){
        if(x==data[i]){
            return i+1;
        }
    }
    return 0;
}

template <class T>
SeqList<T>::SeqList(SeqList<T> &L) {
    maxSize=L.Size();
    last=L.Length()-1;
    T vaule;
    data=new T[maxSize];
    if(!data){
        cout<<"存储发生错误！"<<endl;
    }//end if
    for(int i=0;i<=last;i++) {
        L.getData(i, vaule);
        data[i] = vaule;
    }//end for
}
template <class T>
SeqList<T>::SeqList(int sz){
    if(sz>0){
        maxSize=sz;
        last=-1;
        data=new T[maxSize];
        if(!data){
            cout<<"存储发生错误！"<<endl;
        }
    }
}
int main() {
    SeqList<int> L;
    L.input();
    L.output();
}