class Solution {
public:
    bool isValid(string s) {
        char a[10005];
        int index = 0;
        for (int i = 0; i < s.size(); i++){
            char ch = s[i];
            if (ch == '[' || ch == '(' || ch == '{'){
                a[index] = ch;
                index++;
            } else if (ch == ')'){
                if (index > 0 && a[index-1] == '('){
                    index--;                    
                } else {
                    return false;
                }
            } else if (ch == ']'){
                if (index > 0 && a[index-1] == '['){
                    index--;                    
                } else {
                    return false;
                }
            } else {
                if (index > 0 && a[index-1] == '{'){
                    index--;                    
                } else {
                    return false;
                }
            }
        }
        if (index == 0){
            return true;
        }
        return false;
    }
};