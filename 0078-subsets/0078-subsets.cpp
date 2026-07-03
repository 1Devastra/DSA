class Solution {
public:
vector<vector<int>> a;
 void f(int i, vector<int>& nums, vector<int>& path) {
        if (i == nums.size()) {
            a.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        f(i +1, nums, path);
        path.pop_back();
        f(i + 1, nums, path);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       a.clear();
        vector<int> path;
        f(0, nums, path); 
        return a;
   }
};