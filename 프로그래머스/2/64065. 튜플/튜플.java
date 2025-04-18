import java.util.*;

class Solution {
    
    static class Pair {
        int first;
        int second;
        
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
    
    public int[] solution(String s) {
        
        String str = s.replaceAll("\\{", "").replaceAll("\\}", "");

        
        Integer[] nums = Arrays.stream(str.split(","))
                       .map(Integer::parseInt)
                       .toArray(Integer[]::new);
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int cnt = map.getOrDefault(nums[i], 0);
            map.put(nums[i], cnt + 1);
        }
        
        ArrayList<Pair> pair = new ArrayList<>();
        
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            pair.add(new Pair(entry.getKey(), entry.getValue()));
        }
        
        pair.sort((p1, p2) -> Integer.compare(p2.second, p1.second));

        
        int[] answer = new int[pair.size()];
        
        for (int i = 0; i < pair.size(); i++) {
            answer[i] = pair.get(i).first;
        }
        
        return answer;
    }
}