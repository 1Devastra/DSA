class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string s="123456789";
        for(int l=2; l<=9; l++){
            for(int i=0; i+l<=9; i++){
                int num=stoi(s.substr(i,l));
                if(num>=low&&num<=high){
                    ans.push_back(num);
                }
            }
        }
          sort(ans.begin(),ans.end());
        return ans;
    }
};