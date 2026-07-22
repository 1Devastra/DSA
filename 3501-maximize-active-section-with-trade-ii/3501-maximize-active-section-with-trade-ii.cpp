class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = count(s.begin(), s.end(), '1');
        vector<int> zero_start, zero_end;
        for (int i = 0; i < n;) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') ++j;
                zero_start.push_back(i);
                zero_end.push_back(j - 1);
                i = j;
            } else {
                ++i;
            }
        }

        int m = zero_start.size();
        if (m < 2) {
            return vector<int>(queries.size(), total_ones);
        }

       
        vector<int> V(m - 1);
        for (int j = 0; j + 1 < m; ++j) {
            V[j] = (zero_end[j] - zero_start[j] + 1) + 
                   (zero_end[j + 1] - zero_start[j + 1] + 1);
        }

        
        int num_valleys = V.size();
        vector<vector<int>> st;
        if (num_valleys > 0) {
            st.push_back(V);
            for (int half = 1; half * 2 <= num_valleys; half *= 2) {
                const auto& prev = st.back();
                vector<int> next(prev.size() - half);
                for (size_t i = 0; i + half < prev.size(); ++i) {
                    next[i] = max(prev[i], prev[i + half]);
                }
                st.push_back(move(next));
            }
        }

        auto rmq = [&](int lo, int hi) {
            if (lo > hi || lo < 0 || hi >= num_valleys) return 0;
            int len = hi - lo + 1;
            int k = std::bit_width(unsigned(len)) - 1;
            return max(st[k][lo], st[k][hi - (1 << k) + 1]);
        };

        auto clip = [&](int j, int l, int r) {
            return V[j] 
                 - max(0, l - zero_start[j]) 
                 - max(0, zero_end[j + 1] - r);
        };

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];

           
            int ja = lower_bound(zero_end.begin(), zero_end.end(), l) - zero_end.begin();
            
            int jb = upper_bound(zero_start.begin(), zero_start.end(), r) - zero_start.begin() - 1;
            if (ja >= jb) {
                ans.push_back(total_ones);
                continue;
            }

            int max_gain = 0;

            if (ja <= m - 2) {
                max_gain = max(max_gain, clip(ja, l, r));
            }
            if (jb - 1 >= 0 && jb - 1 <= m - 2) {
                max_gain = max(max_gain, clip(jb - 1, l, r));
            }

            int lo_v = ja + 1;
            int hi_v = jb - 2;
            if (lo_v <= hi_v) {
                max_gain = max(max_gain, rmq(lo_v, hi_v));
            }

            ans.push_back(total_ones + max_gain);
        }

        return ans;
    }
};