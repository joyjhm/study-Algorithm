import java.util.*;

class Solution {
    
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int s : scoville) {
            pq.offer(s);
        }
        
        while(pq.peek() < K) {
            if(pq.size() == 1) {
                answer = -1;
                break;
            }
            int first = pq.peek();
            pq.poll();
            int second = pq.peek();
            pq.poll();
            int val = first + second * 2;
            pq.offer(val);
            answer++;
        }
        
        return answer;
    }
}