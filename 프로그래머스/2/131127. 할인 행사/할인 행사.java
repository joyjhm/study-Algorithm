import java.util.*;

class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        Map<String, Integer> target = new HashMap<>();

        for (int i = 0; i < want.length; i++) {
            target.put(want[i], number[i]);
        }

        for (int i = 0; i <= discount.length - 10; i++) {
            Map<String, Integer> window = new HashMap<>();
            for (int j = i; j < i + 10; j++) {
                window.put(discount[j], window.getOrDefault(discount[j], 0) + 1);
            }

            if (check(window, target)) {
                answer++;
            }
        }

        return answer;
    }

    private boolean check(Map<String, Integer> window, Map<String, Integer> target) {
        for (String key : target.keySet()) {
            if (window.getOrDefault(key, 0) != target.get(key)) {
                return false;
            }
        }
        return true;
    }

}