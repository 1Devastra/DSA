class Solution {
public:
    static const int MOD = 1000000007;

     long long gcdSum(vector<int>& nums) {
       int n = nums.size();

        vector<int> prefixGcd(n);

        int mx = 0;

        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        int i = 0;
        int j = n - 1;

        while(i < j) {
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return ans;
    }
};