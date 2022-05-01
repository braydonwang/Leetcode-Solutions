class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        boolean done = false;
        String pre = "";
        int index = 0;
        while (!done){
            if (strs[0].length() <= index){
                done = true;
                break;
            }
            char ch = strs[0].charAt(index);
            for (int i = 1; i < n; i++){
                String str = strs[i];
                if (str.length() <= index){
                    done = true;
                    break;
                }
                if (str.charAt(index) != ch){
                    done = true;
                    break;
                }
            }
            if (!done){
                index++;
                pre = pre + ch;
            }
        }
        return pre;
    }
}