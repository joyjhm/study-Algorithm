import java.util.*;

class Solution {
    
    
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        
        Stack<Pair> s = new Stack<>();
        
        
        for (int i = 0; i < numbers.length; i++) {
            if(s.isEmpty()) {
                s.push(new Pair(numbers[i], i));
            }
            else if(s.peek().num >= numbers[i]) {
                s.push(new Pair(numbers[i], i));
            }
            else {
                while(!s.isEmpty() && s.peek().num < numbers[i]) {
                    Pair p = s.peek();
                    s.pop();
                    answer[p.idx] = numbers[i];
                    
                }
                s.push(new Pair(numbers[i], i));
            }
            
        }
        
        while(!s.isEmpty()) {
            Pair p = s.peek();
            s.pop();
            answer[p.idx] = -1;
        }
        
        return answer;
    }
    
    static class Pair {
        int num;
        int idx;
        
        Pair(int num, int idx) {
            this.num = num;
            this.idx = idx;
        }
    }
}