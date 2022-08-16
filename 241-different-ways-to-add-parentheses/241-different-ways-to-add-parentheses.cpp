class Solution {
public:
    vector<int> diff(string expression, int r, int c, vector<vector<vector<int>>>& dp) {
        if (dp[r][c].size() != 0) {
            return dp[r][c];
        }
        vector<int> ans;
        for (int i = r; i < c; i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> l = diff(expression,r,i-1,dp);
                vector<int> r = diff(expression,i+1,c,dp);
                for (int left: l) {
                    for (int right: r) {
                        if (expression[i] == '+') {
                            ans.push_back(left + right);
                        } else if (expression[i] == '-') {
                            ans.push_back(left - right);
                        } else {
                            ans.push_back(left * right);
                        }
                    }
                }
            }
        }
        if (ans.size() == 0) {
            ans.push_back(stoi(expression.substr(r,c-r+1)));
        }
        return dp[r][c] = ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<vector<vector<int>>> dp(expression.length(),vector<vector<int>>(expression.length()));
        return diff(expression,0,expression.length()-1,dp);
    }
};