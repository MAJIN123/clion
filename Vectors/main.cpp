#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
//---------------------------------------------
typedef vector<vector<int> > Mat;
Mat input();
void mySort(Mat& a);
void output(const Mat& a);
int main() {
    Mat a;
    a=input();
    mySort(a);
    output(a);
    return 0;
}
void output(const Mat& a){
    for(int i=0;i<a.size();++i) {
        for (int j = 0; j < a[i].size(); ++j)
            cout << a[i][j] << " ";
        cout<<endl;
    }
}
void mySort(Mat& a){
    for(int i=1;i<a.size();++i)
        for(int j=0;j<a.size()-i;++j){
            if(a[j].size()<a[j+1].size())
                a[j].swap(a[j+1]);
        }
}
Mat input(){
    ifstream in("/home/jinm32/ClionProjects/Vectors/aaa");      //可以改进
    if(!in){
        cout<<"Can not open this file!"<<endl;
    }
    Mat a;
    for(string s;getline(in,s);){
        istringstream sin(s);
        vector<int> b;
        for(int ia;sin>>ia;){
            b.push_back(ia);
        }
        a.push_back(b);
    }
    return a;
}