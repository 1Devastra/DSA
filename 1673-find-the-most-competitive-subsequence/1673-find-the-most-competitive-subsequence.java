class Solution {
    public int[] mostCompetitive(int[] nums, int k) {
        int p=nums.length-k;
        Stack<Integer>s=new Stack<>();
        for(int i=0; i<nums.length; i++){
            int curr=nums[i];
            while(!s.isEmpty()&&p>0 && curr<s.peek()){
                s.pop();
                p-=1;
            }
         s.push(curr);
         
        }
           while(s.size()>k){
                s.pop();
                // p-=1;
            }
         int[] ans=new int[k];
            for(int j=k-1; j>=0; j--){
                ans[j]=s.pop();

            }
            return ans;
       
    }
}