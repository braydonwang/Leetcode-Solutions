class Solution {
public:
    int computeArea(int a, int b, int c, int d, int e, int f, int g, int h) {
        int left = max(a,e);
        int right = min(c,g);
        int top = min(d,h);
        int bot = max(b,f);
        
        int overlap = 0;
        if (right > left && top > bot) {
            overlap = (top - bot) * (right - left);
        }
        return (c - a) * (d - b) + (g - e) * (h - f) - overlap;
    }
};