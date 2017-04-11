#include <iostream>
#include<vector>
using namespace std;
#include<algorithm>
class Solution {
public:
    vector<vector<int> > threeSum(vector<int >& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        if(nums.size()<3)
            return result;
        for(int i=0;i<nums.size()-2;++i){
            int begin=i+1;
            int end=nums.size()-1;
            if(i>0&&(nums[i]==nums[i-1]))
                continue;
            while(begin<end){
                if(begin>i+1&&nums[begin]==nums[begin-1]){
                    begin++;
                    continue;
                }
                if(end<nums.size()-1&&nums[end]==nums[end+1]){
                    end--;
                    continue;
                }
                if(nums[i]+nums[end]+nums[begin]>0)
                    end--;
                else if(nums[i]+nums[end]+nums[begin]<0)
                    begin++;
                else{
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[begin]);
                    temp.push_back(nums[end]);
                    result.push_back(temp);
                    begin++;
                }
            }//end for while
        }//end for i
        return result;
    }
};
int main() {
    Solution p;
    vector<int> a;
    a.push_back(-1);
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(-1);
    a.push_back(4);
    vector<vector<int>> result=p.threeSum(a);
    cout<<result.size();
    return 0;
}