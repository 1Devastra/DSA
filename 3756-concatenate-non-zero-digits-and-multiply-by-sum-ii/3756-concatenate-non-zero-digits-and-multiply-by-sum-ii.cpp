class Solution {

public:
const long long MOD = 1000000007;

    long long power(long long a, long long b){
        long long ans = 1;
        while(b){
            if(b & 1) ans = ans * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ans;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
         int n = s.size();

        vector<long long> prefSum(n + 1, 0);
        vector<long long> val(n + 1, 0);
        vector<int> cnt(n + 1, 0);

        for(int i = 0; i < n; i++){

            int digit = s[i] - '0';

            prefSum[i + 1] = prefSum[i] + digit;

            if(digit != 0){
                val[i + 1] = (val[i] * 10 + digit) % MOD;
                cnt[i + 1] = cnt[i] + 1;
            }
            else{
                val[i + 1] = val[i];
                cnt[i + 1] = cnt[i];
            }
        }


        vector<long long> pow10(n + 2);

        pow10[0] = 1;

        for(int i = 1; i <= n; i++)
            pow10[i] = pow10[i-1] * 10 % MOD;


        vector<int> ans;

        for(auto &q : queries){

            int l = q[0];
            int r = q[1];

            long long sum = prefSum[r+1] - prefSum[l];

            int digits = cnt[r+1] - cnt[l];


            long long x = 
            (val[r+1] - val[l] * pow10[digits] % MOD + MOD) % MOD;


            ans.push_back(x * sum % MOD);
        }

        return ans;
    
    }
};