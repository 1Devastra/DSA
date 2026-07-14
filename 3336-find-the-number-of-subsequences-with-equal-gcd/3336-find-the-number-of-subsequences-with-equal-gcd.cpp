class Solution {
public:
static const int MOD=1000000007;
    int subsequencePairCount(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1));
        dp[0][0]=1;
        for(int i=0; i<n; i++){
            vector<vector<int>>ndp(m+1,vector<int>(m+1));
            for(int s1=0; s1<=m; s1++){
                for(int s2=0; s2<=m; s2++){
                    int val=dp[s1][s2];
                    if(val==0)continue;
                    int d1=gcd(s1,nums[i]);
                    int d2=gcd(s2,nums[i]);
                    ndp[s1][s2]=(ndp[s1][s2]+val)%MOD;
                    ndp[d1][s2]=(ndp[d1][s2]+val)% MOD;
                    ndp[s1][d2]=(ndp[s1][d2]+val)%MOD;
                }
            }
            dp.swap(ndp);
        }
        int ans=0;
        for(int i=1; i<=m; i++){
            ans=(ans+dp[i][i])%MOD;
        }
        return ans;
        
    }
};