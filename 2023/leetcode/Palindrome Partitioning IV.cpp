class Solution {
public:  //Algorithm - find all sub-palindroms using dp - O(N^2)
         //Well, because [1,k] as to be a palindrom we will just iterate over k, and check if [k,n]
         //could be splited into 2 palindroms - by checking all partitions.  
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int i = 0; i < n; i++)dp[i][i] = 1;
        for(int i = 1; i < n; i++)dp[i-1][i] = s[i] == s[i-1];

        for(int j = 2; j < n; j++){
            for(int i = 0; i + j < n; i++){
                dp[i][i+j] = s[i] == s[i+j] && dp[i+1][i+j-1];
            }
        }

        for(int k = 0; k < n-2; k++){
            if(dp[0][k]){
                for(int j = k + 1; j < n-1; j++){
                    if (dp[k+1][j] && dp[j+1][n-1])return true;
                }
            }
        }

        return false;
    }
};
