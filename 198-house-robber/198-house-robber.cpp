RECURSION + MEMOIZATION => TC = O(2^N), SC = O(N) + O(N) {Recursion Stack + dp array}
---------------------------------------------------------------------------------
  class Solution {
public:
    int solve(int idx, vector<int> nums, vector<int>& dp){
        if(idx == 0) return nums[idx];
        if(idx < 0) return 0;
        
        if(dp[idx] != -1) return dp[idx];  // shows precomputed.
        
        int pick = nums[idx] + solve(idx-2, nums, dp); // no two adjacent houses can be broken into.
        int notPick = solve(idx-1, nums, dp);
        
        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n, -1);
        solve(n-1, nums, dp);
        
        return dp[n-1];  // dp[4] means max money which can be robbed from [0,...,4] houses.
    }
};
-------------------------------------------------------------------------------------------------
Using Tabulation method => TC = O(N), SC = O(N)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp(n, 0);
        dp[0]=nums[0];
        dp[1]= max(nums[0], nums[1]);
        
        for(int i=2;i<n;i++){
            int pick = nums[i] + dp[i-2];
            int notPick = dp[i-1];
            
            dp[i] = max(pick, notPick);
        }
        
        return dp[n-1];
    }
};

*/
-------------------------------------------------------------------
Space Optimization => TC = O(N), SC = O(1)
  
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int prev = nums[0];
        int prev2 = 0;
        
        for(int i=1;i<n;i++){
            int pick = nums[i] + prev2;
            int notPick = prev;
            
            int curr = max(pick, notPick);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};
