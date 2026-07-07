class Solution {
public:
    long long sumAndMultiply(int n) {
        std::vector<int> ans;
        while(n>0){
           int digit=n%10;
           if(digit!=0){
            ans.push_back(digit);
           }
           n=n/10;
        }
        long long  x=0;
        long long sum=0;
        while(!ans.empty()){
            int val =ans.back();
            x=x*10+val;
            sum+=val;
            ans.pop_back();
        }
        return (long long)x*sum; 
        // int x=0;
        //  long long sum=0;
        //  string s=to_string(n);
        //  for(char c:s){
        //     if(c!='0'){
        //         int digit=c-'0';
        //         x=x*10+digit;
        //         sum=sum+digit;
        //     }
        //  }
        //  return x*sum;

    }
};