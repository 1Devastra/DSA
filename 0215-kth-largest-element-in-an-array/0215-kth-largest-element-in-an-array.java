class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer>minHeap=new PriorityQueue<>((a,b)->a-b);
        for(int i=0; i<nums.length; i++){
            minHeap.add(nums[i]);
            if(minHeap.size()==k+1){
                minHeap.remove();
            }
        }
        return minHeap.peek(); 
    }
     
}