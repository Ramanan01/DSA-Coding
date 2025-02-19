class Solution {
public:
    int numTilings(int n) {
        vector<vector<long long int>> dp(n + 1, vector<long long int>(3, 0));

        if (n == 0) {
            return 0;
        }

        dp[1][0] = 1;
        if (n == 1) {
            return dp[1][0];
        }

        dp[2][0] = 2;
        dp[2][1] = 1;
        dp[2][2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 2][0] % 1000000007 + dp[i - 1][0] % 1000000007) % 1000000007;
            dp[i][1] = (dp[i - 1][2] + dp[i - 2][0]) % 1000000007;
            dp[i][2] = (dp[i - 1][1] + dp[i - 2][0]) % 1000000007;
        }

        return dp[n][0] % 1000000007;
    }
};
