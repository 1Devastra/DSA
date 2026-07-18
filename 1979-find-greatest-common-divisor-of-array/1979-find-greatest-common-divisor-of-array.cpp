class Solution {
public:
    int findGCD(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int  n=nums[0];
        // int k=nums[nums.size()-1];
        // return gcd(n,k);
        int n=*min_element(nums.begin(),nums.end());
        int k=*max_element(nums.begin(),nums.end());
        return gcd(n,k);
    }
};