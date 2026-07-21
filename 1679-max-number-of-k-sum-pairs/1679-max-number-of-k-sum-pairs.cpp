class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0;
        int start=0; 
        int end=nums.size()-1;
        while(start<end){
            int sum=nums[start]+nums[end];
            if(sum==k){
                count++;
                start++;
                end--;
            }else if(sum<k){
                start++;
            }else{
                end--;
            }
        }
       return count; 
    }
};