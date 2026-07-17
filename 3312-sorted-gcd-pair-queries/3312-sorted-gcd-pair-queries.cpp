class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
         int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        // exact[g] = number of pairs having gcd exactly g
        vector<long long> exact(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            long long cnt = 0;

            for (int j = g; j <= mx; j += g)
                cnt += freq[j];

            long long pairs = cnt * (cnt - 1) / 2;

            for (int j = 2 * g; j <= mx; j += g)
                pairs -= exact[j];

            exact[g] = pairs;
        }
        vector<long long> pref(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            pref[g] = pref[g - 1] + exact[g];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }

        return ans;
        
    }
};