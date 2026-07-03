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
        
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        f(i + 1, nums, path);
    }
   vector<vector<int>> subsetsWithDup(vector<int>& nums)  {
       a.clear();
        vector<int> path;
        sort(nums.begin(), nums.end());
        f(0, nums, path); 
        return a;
   }
};