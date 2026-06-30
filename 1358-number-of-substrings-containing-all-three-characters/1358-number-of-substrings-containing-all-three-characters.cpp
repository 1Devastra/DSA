class Solution {
public:
    int numberOfSubstrings(string s) {
        // int p[3]={-1,-1,-1};
        // int total=0;
        // int minvalue=0;
        // for(int i=0; i<s.length(); i++){
        //     p[s[i]-'a']=i;
        //     minvalue=min({p[0],p[1],p[2]});
        //     total+=minvalue+1;
        // }
        // return total;
        int left=0;
        int right=0;
        vector<int>freq(3,0);
        int total=0;
        while(right<s.length()){
            char curr=s[right];
            int f=curr-'a';
            freq[f]++;
            while(freq[0]>0&&freq[1]>0&&freq[2]>0){
                total +=s.length()-right;
                char leftchar=s[left];
                int l=leftchar-'a';
                freq[l]--;
                left++;
            }
            right++;
        }
        return total;
    }
};