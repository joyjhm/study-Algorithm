import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        Arrays.sort(citations);
        int size = citations.length;
        int n = citations[size - 1];

        int idx = 0;
        // [1,1,1,1,1]
        for (int i = 1; i <= n; i++) {
            while(citations[idx] < i) {
                idx++;
            }
            
            
            if (i <= size - idx) {
                answer = i;
            }
        }
        
        return answer;
    }
}