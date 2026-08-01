class Solution {
public:
    using int64 = long long;

    int64 combCap(int n, int r, int64 cap) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        __int128 res = 1;

        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i);
            res /= i;
            if (res >= cap) return cap;
        }
        return (int64)res;
    }

    int64 countWays(vector<int> &cnt, int64 cap) {
        int rem = 0;
        for (int x : cnt) rem += x;

        int64 ans = 1;
        for (int c : cnt) {
            if (c == 0) continue;
            ans = min(cap, ans * combCap(rem, c, cap));
            if (ans >= cap) return cap;
            rem -= c;
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26, 0);
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1) mid = char('a' + i);
        }

        int64 K = k;
        if (countWays(half, K) < K) return "";

        string left = "";

        int halfLen = s.size() / 2;
        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                int64 ways = countWays(half, K);

                if (ways >= K) {
                    left.push_back(char('a' + c));
                    break;
                } else {
                    K -= ways;
                    half[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + string(1, mid) + right;
        return left + right;
    }
};