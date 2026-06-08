bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);

    bool dp[m + 1][n + 1];
    memset(dp, false, sizeof(dp));

    dp[m][n] = true;

    for (int i = m; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            bool firstMatch = (i < m &&
                              (s[i] == p[j] || p[j] == '.'));

            if (j + 1 < n && p[j + 1] == '*') {
                dp[i][j] = dp[i][j + 2] ||
                           (firstMatch && dp[i + 1][j]);
            } else {
                dp[i][j] = firstMatch &&
                           dp[i + 1][j + 1];
            }
        }
    }

    return dp[0][0];
}
