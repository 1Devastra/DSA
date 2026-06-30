class Solution {
public:
    int numberOfSubstrings(string s) {
        int p[3]={-1,-1,-1};
        int total=0;
        int minvalue=0;
        for(int i=0; i<s.length(); i++){
            p[s[i]-'a']=i;
            minvalue=min({p[0],p[1],p[2]});
            total+=minvalue+1;
        }
        return total;
    }
};