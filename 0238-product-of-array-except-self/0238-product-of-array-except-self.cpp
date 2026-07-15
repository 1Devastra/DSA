class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(),1);
        vector<int>prefix(nums.size(),1);
        vector<int>suffix(nums.size(),1);

        // 1st approach its give the TLE

        // for(int i=0; i<nums.size(); i++){
        //     int product=1;
        //     for(int j=0; j<nums.size(); j++)
        //     if(i!=j){
        //         product=product*nums[j];
        //     }
        //     ans.push_back(product);
        // }
        // return ans;



        // 2nd approach


        // prefix[0]=1;
        // suffix[nums.size()-1]=1;
        // for(int i=1; i<nums.size(); i++){
        //     prefix[i]=prefix[i-1]*nums[i-1];
        // }
      
        // for(int j=nums.size()-2; j>=0; j--){
        //     suffix[j]=suffix[j+1]*nums[j+1];
        // }
        // for(int i=0; i<nums.size(); i++){
        //     ans[i]=prefix[i]*suffix[i];

        // }
        // return ans;

        // 3rd approach
        for(int i=1; i<nums.size(); i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int sufix=1;
        for(int j=nums.size()-2; j>=0; j--){
            sufix=sufix*nums[j+1];
            ans[j]=ans[j]*sufix;
        }
       
        return ans;
      
    }
};