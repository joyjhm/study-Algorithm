import java.util.*;

class Solution {
    public int solution(int[] topping) {
        int answer = 0;
        
        Map<Integer, Integer> first = new HashMap<>();
        Map<Integer, Integer> second = new HashMap<>();
        int secondType = 0;
        
        first.put(topping[0], 1);
        int firstType = 1;
        
        for (int i = 1; i < topping.length; i++) {
            int cnt = second.getOrDefault(topping[i], 0);
            if (cnt == 0) {
                secondType++;
            }
            second.put(topping[i], cnt + 1);
        }
        
        for (int i = 1; i < topping.length; i++) {
            if(firstType == secondType) {
                answer++;
            }
            
            int addTopping = first.getOrDefault(topping[i], 0);
            
            if(addTopping == 0) {
                firstType++;
            }
            first.put(topping[i], addTopping + 1);
            
            int subTopping = second.get(topping[i]);
            if(subTopping - 1 == 0) {
                secondType--;
            }
            second.put(topping[i], subTopping - 1);
            
            
            
        }
        
        return answer;
    }
}