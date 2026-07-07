class Solution {
public:
    long long sumAndMultiply(int n) {
        // std::vector<int> ans;
        // for(int i=0; i<n; i++){
        //     if(i!=0){
        //         ans.push_back(i);
        //     }
        // }
        // int  x=0;
        // long long sum=0;
        // while(!ans.empty()){
        //     x=ans.back();
        //     sum+=x;
        //     ans.pop_back();
        // }
        // return (long long)x*sum; 
        int x=0;
         long long sum=0;
         string s=to_string(n);
         for(char c:s){
            if(c!='0'){
                int digit=c-'0';
                x=x*10+digit;
                sum=sum+digit;
            }
         }
         return x*sum;

    }
};