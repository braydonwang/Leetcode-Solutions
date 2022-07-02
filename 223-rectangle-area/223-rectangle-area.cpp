class Solution {
public:
    int computeArea(int a, int b, int c, int d, int e, int f, int g, int h) {
        return (c - a) * (d - b) + (g - e) * (h - f) - max((min(d,h) - max(b,f)),0) * max((min(c,g) - max(a,e)),0);
    }
};