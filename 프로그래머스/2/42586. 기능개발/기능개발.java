import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        List<Integer> result = new ArrayList<>();
        int size = progresses.length;
        boolean[] done = new boolean[size];
        Arrays.fill(done, false);
        int cnt = 0;
        int idx = 0;
        while(cnt != size) {
            for (int i = 0; i < size; i++) {
                progresses[i] += speeds[i];
                if(!done[i] && progresses[i] >= 100) {
                    pq.offer(i);
                    done[i] = true;
                    System.out.println(i);
                }
            }
            
            int distribute_num = 0;
            
            while(!pq.isEmpty() && pq.peek() <= idx) {
                int cur = pq.peek();
                if (cur <= idx) {
                    pq.poll();
                    idx = cur + 1;
                    distribute_num++;
                    cnt++;
                }
            }
            if (distribute_num != 0) {
                result.add(distribute_num);            
            }
            
        }
        
        answer = new int[result.size()];
        int answerIdx = 0;
        for (Integer num : result) {
            answer[answerIdx++] = num;
        }
        return answer;
    }
}