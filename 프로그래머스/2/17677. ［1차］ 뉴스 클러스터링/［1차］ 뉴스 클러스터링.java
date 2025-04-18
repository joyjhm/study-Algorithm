import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        
        Map<String, Integer> map = new HashMap<>();
        int sum = 0;
        int intersect = 0;
        
        for (int i = 0; i < str1.length()- 1; i++) {
            String str = str1.substring(i, i + 2).toLowerCase();

            if(!(str.charAt(0) >= 'a' && str.charAt(0) <= 'z' 
                 && str.charAt(1) >= 'a' && str.charAt(1) <= 'z')) {
                continue;
            }
            
            map.put(str, map.getOrDefault(str, 0) + 1);
            sum++;
        }
        
        for (int i = 0; i < str2.length() - 1; i++) {
            String str = str2.substring(i, i + 2).toLowerCase();
            
            if(!(str.charAt(0) >= 'a' && str.charAt(0) <= 'z' &&
                 str.charAt(1) >= 'a' && str.charAt(1) <= 'z')) {
                continue;
            }
            
            int cnt = map.getOrDefault(str, 0);
            if(cnt == 0) {
                sum++;
            }
            else {
                map.put(str, cnt - 1);
                intersect++;
            }
        }
        
        if (sum == 0) {
            return 1 * 65536;
        }
        else {
            return 65536 * intersect / sum;
        }
    }
}