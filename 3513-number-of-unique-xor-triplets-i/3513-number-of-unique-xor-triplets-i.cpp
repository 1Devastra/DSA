class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;
        int bitLength = 32 -__builtin_clz(n);
        return 1 << bitLength;

    }
};