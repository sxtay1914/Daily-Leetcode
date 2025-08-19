class Solution {
//TC:O(N)
//SC:O(1)
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, count = 0;
        for (int i=0; i<n; i++){
            if (nums[i]!=0){
                count = 0;
            }else{
                count++;
                ans += count;
            }
        }
        return ans;
    }
};