class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
          int ones = 0;
        for (char c : s)
            if (c == '1') ones++;

        string t = "1" + s + "1";
        int m = t.size();

        vector<pair<char,int>> runs;

        for (int i = 0; i < m;) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int ans = ones;

        for (int i = 1; i + 1 < runs.size(); i++) {
            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {

                int gain = runs[i - 1].second + runs[i + 1].second;
                ans = max(ans, ones + gain);
            }
        }

        return ans;
        
    }
};