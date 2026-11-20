class Solution {
public:
    int tribonacci(int n) {
        int dp[38];

        dp[0]= 0;
        dp[1] = 1;
        dp[2] = 1;

        if(n < 2) return n;
        if(n == 2) return 1;
        int result = 0;
        for(int i = 3; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
            result = dp[i];
        }
        return result;

    }
};
