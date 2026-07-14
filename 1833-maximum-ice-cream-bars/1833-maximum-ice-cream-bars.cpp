class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int more= *max_element(costs.begin(),costs.end());
        vector<int>ans(more+1);
        int total=0;
        for(int i=0; i<costs.size(); i++)++ans[costs[i]];
        for(int costs=1; costs<=more; costs++){
            if(ans[costs]>0){
                int small=min(ans[costs],coins/costs);
                total+=small;
                coins-=small*costs;
                if(coins==0)break;
            }
        }
     return total;
 
    }
};