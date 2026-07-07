class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            unordered_set<int>distinct_odd;
            unordered_set<int>distinct_even;
            for(int j=i; j<nums.size(); j++){
                if(nums[j]%2==0){
                distinct_even.insert(nums[j]);
            }else{
                distinct_odd.insert(nums[j]);
            }
            if(distinct_odd.size()==distinct_even.size()){
            ans=max(ans,j-i+1);
            }
            }
        }
        
        return ans;
        
    }
};