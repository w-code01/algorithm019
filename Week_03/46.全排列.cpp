class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        backtrack(nums, cur, res);
        return res;
    }

private:
    void backtrack(vector<int>& nums, vector<int> &cur, vector<vector<int>>& res) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(cur.begin(), cur.end(), nums[i]) != cur.end()) {
                continue;
            }
            cur.push_back(nums[i]);
            backtrack(nums, cur, res);
            cur.pop_back();
        }

    }
