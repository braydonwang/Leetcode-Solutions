class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for (int i = 0; i < expression.size()-1; i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> l = diffWaysToCompute(expression.substr(0,i));
                vector<int> r = diffWaysToCompute(expression.substr(i+1));
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
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};