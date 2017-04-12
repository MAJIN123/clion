
#include "Solution_1.h"
#include "Solution_15.h"

int main() {
    Solution_1 p;
    vector<int> nums,result;
    nums.push_back(6);
    nums.push_back(2);
    nums.push_back(4);

    result=p.twoSum(nums,6);
    cout<<result[0]<<" "<<result[1];
    return 0;
}