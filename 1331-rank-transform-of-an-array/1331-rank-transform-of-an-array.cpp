class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        if(n==0){
            return{};
        }
        vector<pair<int,int>>A(n);
        for(int i=0; i<n; i++){
            A[i]={arr[i],i};
        }
        sort(A.begin(),A.end());
        int r=1;
        vector<int>ans(n);
        ans[A[0].second]=1;
        for(int i=1; i<n; i++){
            if(A[i].first!=A[i-1].first){
                r++;
            }
                ans[A[i].second]=r;  
    }
     return ans;
    }
};