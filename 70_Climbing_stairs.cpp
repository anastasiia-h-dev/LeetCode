class Solution {
public:
    int climbStairs(int n) {
        int dp[45];

        dp[0] = 1;
        dp[1] = 2;

        if(n <= 2)
        {
            return n;
        }
        int result = 0;
        for(int i = 2; i < n; i ++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
            result = dp[i];
        }
        return result;
    }
};