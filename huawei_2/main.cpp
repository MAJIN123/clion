#include <iostream>
#include <vector>
using namespace std;
bool Have(int a,int b,int c,int num){
    if(a==num)
        return 1;
    if(b==num)
        return 1;
    if(c==num)
        return 1;
    return 0;
}
void Sort_Array(int* a,int length)
{
    int temp;
    for (int i=0;i<length;i++)
        for (int j=i+1;j<length;j++)
        {
            if (a[j] < a[i])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
}
int Up(int *a,int length,int num) {
    //0<num<10
    Sort_Array(a, length);
    if (num <= length)
        return a[num];
    else {
        int count = length;
        while (count <= num) {
            for (int i = 0; i < length; ++i)
                for (int j = 0; j < length; ++j) {
                    if (j == i);
                    else {
                        if (a[i] == 2 && a[j] == 5 || a[i] == 5 && a[j] == 2 || a[i] == 6 && a[j] == 9 ||
                            a[i] == 9 && a[j] == 6);
                        else {
                            //temp.push_back(a[i] * 10 + a[j]);
                            ++count;
                            if (count == num)return a[i] * 10 + a[j];
                        }
                    }
                }//end for j
        }//end for while
    }
}
int main() {
    int a,b,c;
    int p=0,q=0;

    cin>>a;
    if(cin.get()==',')
        cin>>b;
    if(cin.get()==',')
        cin>>c;
    int t;
    if(a>b) {t=a;a=b;b=t;}
    if(b>c) {t=b;b=c;c=t;}
    if(a>b) {t=a;a=b,b=t;}

    if(a<1||b<1||c<1)
        return -1;
    if(a>9||b>9||c>9)
        return -1;
    if(a==b||b==c||a==c)
        return -1;

    if(Have(a,b,c,2)&&Have(a,b,c,5))
        ;
    else{
        if(Have(a,b,c,2))
            p=5;
        if(Have(a,b,c,5))
            p=2;
    }
    if(Have(a,b,c,6)&&Have(a,b,c,9))
        ;
    else{
        if(Have(a,b,c,6))
            q=9;
        if(Have(a,b,c,9))
            q=6;
    }

    int arry[5]={a,b,c,0,0};
    int value;
    if(!p&&!q){
        value=Up(arry,3,c);
        cout<<value;
        return 0;
    }
    if(p&&q){
        arry[3]=p;arry[4]=q;
        value=Up(arry,5,c);
        cout<<value;
        return 0;
    }
    if(p==0){
        arry[3]=q;
        value=Up(arry,4,c);
        cout<<value;
        return 0;
    }
    else{
        arry[3]=q;
        value=Up(arry,4,c);
        cout<<value;
        return 0;
    }
}