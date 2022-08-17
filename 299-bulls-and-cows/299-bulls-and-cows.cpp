class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> sec(10);
        vector<int> g(10);
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
            } else {
                sec[secret[i]-'0']++;
                g[guess[i]-'0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            cow += min(sec[i],g[i]);
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};