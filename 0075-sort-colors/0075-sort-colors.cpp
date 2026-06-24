class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st=0,end=nums.size()-1,mid=0;
        while(mid<=end){
            if(nums[mid]==0){
                swap(nums[mid],nums[st]);
                st++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[end]);
                end--;
               
            }
            else{
                mid++;
            }
            
        }
        
    }
};