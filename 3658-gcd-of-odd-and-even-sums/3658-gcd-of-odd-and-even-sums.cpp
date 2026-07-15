class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int even=0; 
        int odd=0;
        int count=0; 
        // for(int i=1; count<n; i+=2){
        //     odd+=i;
        //     count++;
        // }
        // count=0;
        // for(int i=2; count<n; i+=2){
        //     even+=i; 
        //     count++;
        // }
        // int ans=gcd(even,odd);
        // return ans;
        odd=n*n;
        even=n*(n+1);
        int ans=gcd(even,odd);
        return ans;
    }
};