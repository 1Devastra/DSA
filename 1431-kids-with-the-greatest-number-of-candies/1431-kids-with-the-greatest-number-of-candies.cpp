class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int max=0;
        for(int i=0; i<candies.size(); i++){
            if(max<candies[i]){
                max=candies[i];
            }
        }
        for(int i=0; i<candies.size(); i++){
            int curr=extraCandies+candies[i];
            if(max<=curr){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
             

        }
        return ans;
        
    }
};