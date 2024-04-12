import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);    
            if(c == '(') {
                stack.push(c);
            } else {
                if(stack.empty()) {
                    answer = false;
                    break;
                } else {
                    stack.pop();
                }
            }
        }
        
        if(!stack.empty()) {
            answer = false;
        }

        
        
        return answer;
    }
}