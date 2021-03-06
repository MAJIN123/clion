#include <iostream>
#include<string.h>
const int defaluteSize=128;
using namespace std;
class AString{
private:
    char *ch;           //串存放数组
    int curLength;       //数组当前长度
    int maxSize;        //数组最大长度
public:
    AString(int sz=defaluteSize);          //串构造函数
    AString(const char* init);              //构造一个最大长度为maxSize，由init初始化的字符串
    AString(const AString& ob);             //赋值构造函数
    ~AString(){delete []ch;}                 //析构函数
    int Length()const{return curLength;};
    AString& operator()(int pos,int len);
    //当0<=pos<=maxSize&&len>0时，取出子串
    int operator==(AString &ob)const{return strcmp(ch,ob.ch)==0;}
    int operator!=(AString &ob)const{return strcmp(ch,ob.ch)!=0;}
    int operator!(){return curLength==0;}
    AString& operator=(AString &ob);//串ob 赋值给*this
    AString& operator+=(AString &ob);//串ob+*this 赋值给*this
    char& operator[](int i);
    //取*this 的第i个元素
    int Find(AString& pat)const;
    //在*this找pat的子串，没有则返回-1
    void getNext(int next[]);
    int KMPFind(AString& pat,int k,int next[])const;
    //kmp算法 求从pat的k位开始找子串，返回满足条件的开始位置
};
int AString::KMPFind(AString &pat, int k, int *next) const {
    int posP=0,posT=k;
    int lengthP=pat.curLength;
    int lengthT=curLength;
    while(posP<lengthP&&posT<lengthT){
        if(posP==-1||pat.ch[posP]==ch[posT]){
            posP++;posT++;
        }
        else posP=next[posP];
    }
    if(posP<lengthP)return -1;
    return posT-lengthP;
}
void AString::getNext(int *next) {
    int k=-1;
    int i=0;
    next[0]=-1;
    while(i<curLength){
        if(k==-1||ch[i]==ch[k]) {
            i++;
            k++;
            next[i]=k;
        }
        else k=next[k];
    }
}
int AString::Find(AString &pat) const {
    int i,j;
    for(i=0;i<Length();++i) {
        for (j = 0; j < pat.Length(); ++i) {
            if (pat.ch[i]==ch[i+j])
                break;
        }//end for j
        if(j==pat.Length())return i;
    }//end for i
    return -1;
}
char& AString::operator[](int i) {
    if(i<0||i>=curLength)cout<<"字符串下标越界！"<<endl;
    return ch[i];
}
AString& AString::operator+=(AString &ob) {
    int n=curLength+ob.curLength;
    maxSize=(maxSize>n)?maxSize:n;
    char *temp=ch;                              //释放！！
    ch=new char[n];
    if(ch==NULL)cout<<"Alloction error!"<<endl;
    strcpy(ch,temp);
    strcat(ch,ob.ch);
    delete temp;
    return *this;
}
AString& AString::operator=(AString &ob) {
    if(ob!=*this){
        delete ch;
        maxSize=ob.maxSize;
        curLength=ob.curLength;
        ch=new char[maxSize];
        if(ch==NULL)cout<<"Alloction error!"<<endl;
        strcpy(ch,ob.ch);
    }
    return *this;
}
AString& AString::operator()(int pos, int len) {
    AString temp;
    if(0<=pos<=maxSize&&len>0&&pos+len-1<maxSize){
        if((pos+len)>maxSize)len=curLength-pos;
        temp.curLength=len;
        for(int i=0,j=pos;i<len;++j,++i){
            temp.ch[i]=ch[j];
            temp.ch[len]='\0';
        }
    }
    else{
        temp.ch[0]='\0';
        temp.curLength=0;
    }
    return temp;
}
AString::AString(const char *init) {
    int len=strlen(init);
    curLength=len;
    maxSize=(len>defaluteSize)?len:defaluteSize;
    ch=new char[maxSize+1];
    if(ch==NULL)cout<<"Alloction error!"<<endl;
    strcpy(ch,init);
}
AString::AString(const AString &ob) {
    maxSize=ob.maxSize;
    curLength=ob.curLength;
    ch=new char[ob.maxSize+1];
    if(ch==NULL)cout<<"Alloction error!"<<endl;
    strcpy(ch,ob.ch);
}
AString::AString(int sz) {
    maxSize=sz;
    ch=new char[maxSize];
    if(ch==NULL)
        cout<<"Allocation error!"<<endl;
    ch[0]='\0';
    curLength=0;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}