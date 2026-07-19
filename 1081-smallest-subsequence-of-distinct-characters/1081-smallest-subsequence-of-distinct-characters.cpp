class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>ind(26);
        vector<bool>see(26);
        string ans;
        for(int i=0; i<s.length(); i++){
            ind[s[i]-'a']=i;
        }
        for(int i=0; i<s.length(); i++){
            char c=s[i];
            if(see[c-'a'])continue;
            while(ans.length()&&ans.back()>c&&ind[ans.back()-'a']>i){
                see[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans.push_back(c);
            see[c-'a']=1;
        }
        return ans;
    }
};