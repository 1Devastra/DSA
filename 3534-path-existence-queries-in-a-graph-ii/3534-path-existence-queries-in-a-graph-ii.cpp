class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
    // vector<vector<int>>result(n);
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(abs(nums[i]-nums[j])<=maxDiff){
    //              result[i].push_back(j);
    //              result[j].push_back(i);
    //         }
    //     }
    // }
    // vector<vector<int>>dist(n,vector<int>(n,-1));
    // for(int k=0; k<n; k++){
    //     queue<int>que;
    //     que.push(k);
    //     dist[k][k]=0;
    //     while(!que.empty()){
    //         int node=que.front();
    //         que.pop();
    //         for(auto&i:result[node]){
    //             if(dist[k][i]==-1){
    //                 dist[k][i]=dist[k][node]+1;
    //                 que.push(i);
    //             }
    //         }
    //     }
    // }
    // vector<int>ans;
    // for(auto&q:queries){
    //     ans.push_back(dist[q[0]][q[1]]);
    // }
    // return ans;
 ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<pair<int, int>> sorted_nodes(n);
        for (int i = 0; i < n; ++i) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[sorted_nodes[i].second] = i;
        }

        const int max_power = 18; 
        vector<vector<int>> L(max_power, vector<int>(n));
        vector<vector<int>> R(max_power, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            int val = sorted_nodes[i].first;
            
            auto lit = lower_bound(sorted_nodes.begin(), sorted_nodes.end(), make_pair(val - maxDiff, 0));
            L[0][i] = distance(sorted_nodes.begin(), lit);
            
            auto rit = upper_bound(sorted_nodes.begin(), sorted_nodes.end(), make_pair(val + maxDiff, n));
            R[0][i] = distance(sorted_nodes.begin(), rit) - 1;
        }
        for (int j = 1; j < max_power; ++j) {
            for (int i = 0; i < n; ++i) {
                L[j][i] = L[j - 1][L[j - 1][i]];
                R[j][i] = R[j - 1][R[j - 1][i]];
            }
        }
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (v < L[max_power - 1][u] || v > R[max_power - 1][u]) {
                ans.push_back(-1);
                continue;
            }

            int cur_l = u;
            int cur_r = u;
            int steps = 0;
            for (int j = max_power - 1; j >= 0; --j) {
                int next_l = L[j][cur_l];
                int next_r = R[j][cur_r];

                if (v < next_l || v > next_r) {
                    cur_l = next_l;
                    cur_r = next_r;
                    steps += (1 << j);
                }
            }
            if (v >= L[0][cur_l] && v <= R[0][cur_r]) {
                ans.push_back(steps + 1);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};