class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int  n=nums[0];
        int k=nums[nums.size()-1];
        return gcd(n,k);
    }
};