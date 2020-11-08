/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int j = 0;
        for(int i = 0; i<(nums.size()-1); i++) {
            if(nums[i] != nums[i+1]) {
                nums[++j] = nums[i+1];
            }

            return j+1;
        }
    }
};

int main() {
     Solution solution;

     vector<int> nums={1,1,2};
     solution.removeDuplicates(nums);
}
// @lc code=end

