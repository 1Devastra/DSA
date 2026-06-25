class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0,product=1;
        while(n>0){
            
            int val=n%10;
            sum=sum+val;
            product=product*val;
            n=n/10; 
        }
       int result=product-sum;
       return result;
    }

};