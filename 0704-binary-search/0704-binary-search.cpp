class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1,index=-1;
        while(l<=h){
            // int mid=(l+h)/2;
            int mid=l+(h-l)/2;
            if(target<nums[mid]){
                h=mid-1;
            }
            else if(target>nums[mid]){
                l=mid+1;
            }
            else{
            index=mid;
            break;
            }
        }
        return index;
    }
};