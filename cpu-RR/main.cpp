#include<stdio.h>
#include<iostream>
using namespace std;
#include<queue>
#include<fstream>
#include<sstream>
#include<string.h>
const int Time=1;		//定义轮转的每个进程的执行时间
const int N=10;          //定义中间结构体的大小
struct Mat{
	int No;//进程
	int arr_time;//到来时间
	int exu_time;//运行时间
	int priority;//优先级
};
void ReadFile(Mat tt[],int &count);
void RR(Mat tt[],int count);
void Priorty(Mat tt[],int count);
void SJF(Mat tt[],int count);
int main(){
    Mat tt[N];                           //N宏定义
    int count=0;                        //记录进程个数
	ReadFile(tt,count);
    SJF(tt,count);
    Priorty(tt,count);
    RR(tt,count);//轮转调度

}
void SJF(Mat tt[],int count){
    queue<Mat >Cc;
    int k=0;
    int temp[count]={0};//标志是否进队列的
    for(int i=1;i<count;++i){
        if(tt[k].arr_time>tt[i].arr_time)
            k=i;
    }
    Cc.push(tt[k]);
    temp[k]=-1;
    int time=tt[k].arr_time+tt[k].exu_time;
    int p;
    for (int j= 0; j < count; ++j) {
        while(temp[j]<0)
           j++;
        int p=j;
        for (int m = 0; m < count; ++m) {
            if (tt[m].arr_time<=time&&tt[m].exu_time<tt[p].exu_time&&temp[m]>=0)
                p=m;
        }//end m

        Cc.push(tt[p]);
        temp[p]=-1;
        time+=tt[p].exu_time;
    }//end j
    cout<<"SJF短作业优先调度"<<endl;
    while(Cc.size()){
        Mat temp=Cc.front();
        Cc.pop();
        cout<<"p"<<temp.No<<" ";
    }
    cout<<endl;

}
void ReadFile(Mat tt[],int &count){
    ifstream in("/home/jinm32/ClionProjects/cpu-RR/hh");
    if(!in){
        cout<<"Can not open this file!"<<endl;
    }
    string s;getline(in,s);
    for(s;getline(in,s);){
        istringstream sin(s);
        int a[4];int i=0;
        for(int ia;sin>>ia;)
            a[i++]=ia;
        tt[count].No=a[0];
        tt[count].arr_time=a[1];
        tt[count].exu_time=a[2];
        tt[count].priority=a[3];
        ++count;
    }
}
//优先级
void Priorty(Mat tt[],int count){
    queue<Mat > Ac;
    int temp[count]={0};
    for(int i=0;i<count;++i){
        int k=i;
        while(temp[k]<0)
            k=(i+1)%count;
        for(int j=0;j<count;++j){
            if(tt[k].priority>tt[j].priority&&temp[j]==0)
                k=j;
        }
        Ac.push(tt[k]);
        temp[k]=-1;
    }
    cout<<"优先级调度："<<endl;
    while(Ac.size()){
        Mat temp=Ac.front();
        Ac.pop();
        cout<<"p"<<temp.No<<" ";
    }
    cout<<endl;
}
//RR 轮转
void RR(Mat tt[],int count){
    queue<Mat > Bc;						//存放几条进程的所有数据
    int temp[count]={0};
    for(int i=0;i<count;++i){
        int k=i;                        //k 代表最先到的
        while(temp[k]<0)
            k=(i+1)%count;
        for(int j=0;j<count;++j){
            if ((tt[k].arr_time > tt[j].arr_time) && (temp[j] >= 0))
                k = j;
        }
        Bc.push(tt[k]);
        temp[k]=-1;
    }

    cout<<"cpu调度--轮转,轮转单位时间1"<<endl;
    while(Bc.size()!=NULL){
        Mat temp;
        temp=Bc.front();
        temp.exu_time-=Time;
        cout<<"p"<<temp.No<<" ";
        Bc.pop();
        if(temp.exu_time!=0)
            Bc.push(temp);
    }
    cout<<endl;
}