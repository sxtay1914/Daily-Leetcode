class Solution {
//TC:O(N)
//SC:O(1)
public:
    int longestSubarray(vector<int>& nums) {
        //must delete element from it
        //sliding window at anytime must only contain <= 1 zero
        int l = 0, ans = 0, zero_count = 0;
        bool zero_exist = false;
        for (int r = 0; r<nums.size(); r++){
            if (nums[r]==0){
                zero_count++;
                zero_exist = true;
            }
            if (zero_count>1){
                if (nums[l]==0){
                    zero_count--;
                }
                l++;
            }
            ans = max(ans, r-l+1-zero_count);
        }
        if (zero_exist){
            return ans;
        }
        return --ans;
    }
};