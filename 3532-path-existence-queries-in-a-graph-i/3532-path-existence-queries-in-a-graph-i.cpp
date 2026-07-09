class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>pair(n);
        for(int i=1; i<n; i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                pair[i]=pair[i-1];
            }else{
                pair[i]=pair[i-1]+1;
            }
        }
        vector<bool>result;
        for(auto&q:queries){
            if(pair[q[0]]==pair[q[1]]){
                result.push_back(true);
            }else{
                result.push_back(false);
            }
        }
       return result; 
        
    }
};