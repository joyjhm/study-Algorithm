import java.util.*;

class Solution {
    
    private boolean isCheck(String str) {
        Stack<Character> s = new Stack<>();
        
        for (int i = 0; i < str.length(); i++) {
            if(str.charAt(i) == '['  || str.charAt(i) == '(' || str.charAt(i) == '{') {
                s.push(str.charAt(i));
            }
            else {
                if(s.isEmpty()) {
                    return false;
                }
                else if(s.peek() == '[' && str.charAt(i) == ']') {
                    s.pop();
                }
                else if(s.peek() == '(' && str.charAt(i) == ')') {
                    s.pop();
                }
                else if(s.peek() == '{' && str.charAt(i) == '}') {
                    s.pop();
                }
                else {
                    return false;
                }
            }
        }
        
        if(!s.isEmpty()) {
            return false;
        }
        
        
        return true;
    }
    
    public int solution(String s) {
        int answer = 0;
        String str = s;

        for (int i = 0; i < s.length(); i++) {
            if (isCheck(str)) {
                answer++;
            }
            str = str.substring(1) + str.charAt(0);
        }

        return answer;
    }
}
