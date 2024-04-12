import java.util.*;

class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int answer = -1;
        Integer[] arr1 = Arrays.stream(queue1).boxed().toArray(Integer[]::new);
        Queue<Integer> q1 = new LinkedList<>(Arrays.asList(arr1));
        
        Integer[] arr2 = Arrays.stream(queue2).boxed().toArray(Integer[]::new);
        Queue<Integer> q2 = new LinkedList<>(Arrays.asList(arr2));
        int size = queue1.length;
        int totalSize = size * 2;
        long sum1 = 0;
        long sum2 = 0;
        
        for (int i = 0; i < size; i++) {
            sum1 += queue1[i];
            sum2 += queue2[i];
        } 
        
        
        int num1, num2;
        num1 = 0;
        num2 = 0;
        while(num1 < totalSize && num2 < totalSize) {
            if(sum1 < sum2) {
                int num = q2.poll();
                q1.offer(num);
                
                sum1 += num;
                sum2 -= num;
                num2++;          
            }
            else if(sum1 > sum2) {
                int num = q1.poll();
                q2.offer(num);
                
                sum2 += num;
                sum1 -= num;
                num1++;
            }
            else {
                answer = num1 + num2;
                return answer;
            }
        }
        
        return answer;
    }
}