class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        // vector<int>ans;
        // for(int i=0; i<nums.size(); i++){
        //     bool lonely=true;
        //     for(int j=0; j<nums.size(); j++ ){
        //          if(i!=j &&
        //          nums[j]==nums[i]||
        //          nums[j]==nums[i]-1||
        //          nums[j]==nums[i]+1){
        //         lonely=false;
        //         break;
        //     }
        //     }
        //     if(lonely){
        //         ans.push_back(nums[i]);
        //     }
        // }
        // return ans;  
        unordered_map<int, int>m;
        vector<int>ans;
        for(int x:nums){
            m[x]++;
        }
        for(int x:nums){
            if(m[x]==1&&
            m.find(x-1)==m.end()&&
            m.find(x+1)==m.end()){
                ans.push_back(x);
            }
        }
        return ans;
    }
};