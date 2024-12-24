class Solution {
public:

    int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp) {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (S1[i] == S2[j])
            return dp[i][j] = 0 + editDistanceUtil(S1, S2, i - 1, j - 1, dp);

        // Minimum of three choices:
        // 1. Replace the character at S1[i] with the character at S2[j]
        // 2. Delete the character at S1[i]
        // 3. Insert the character at S2[j] into S1
        else
            return dp[i][j] = 1 + min(editDistanceUtil(S1, S2, i - 1, j - 1, dp),
                                    min(editDistanceUtil(S1, S2, i - 1, j, dp),
                                        editDistanceUtil(S1, S2, i, j - 1, dp)));
    }

    int minDistance(string& S1, string& S2) {
        int n = S1.size();
        int m = S2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return editDistanceUtil(S1, S2, n - 1, m - 1, dp);
    }

};