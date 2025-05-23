import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        
        for (int i = 0; i < works.length; i++) {
            pq.offer(works[i]);
        }
        
        while(!pq.isEmpty() && n-- != 0) {
            int val = pq.peek();
            pq.poll();
            if(val - 1 > 0) {
                pq.offer(val - 1);    
            }
            
        }
        
        while(!pq.isEmpty()) {
            int val = pq.peek();
            pq.poll();
            answer += val * val;
        }
        
        
        return answer;
    }
}