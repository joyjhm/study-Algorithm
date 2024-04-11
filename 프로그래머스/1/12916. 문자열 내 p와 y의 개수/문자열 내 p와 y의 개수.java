class Solution {
    boolean solution(String s) {
        boolean answer = true;
        int cnt_p = 0;
        int cnt_y = 0;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == 'p' || c == 'P') {
                cnt_p += 1;
            } 
            else if (c == 'y' || c == 'Y') {
                cnt_y++;
            }
        }
        
        if (cnt_p == cnt_y) {
            answer = true;
        } else {
            answer = false;
        }

        return answer;
    }
}