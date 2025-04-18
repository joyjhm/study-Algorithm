import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        Map<String, Integer> map = new HashMap<>(); 
        int time = 0;
        for (int i = 0; i < cities.length; i++) {
            String city = cities[i].toLowerCase();
            
            if(map.containsKey(city)) {
                time++;
                map.put(city, time);
            }
            else {
                time += 5;
                
                if(map.size() == cacheSize && cacheSize > 0) {  
                    Integer oldestTime = Integer.MAX_VALUE;
                    String changeKey = null;
                    for (Map.Entry<String, Integer> entry : map.entrySet()) {
                        if (entry.getValue() < oldestTime) {
                            oldestTime = entry.getValue();
                            changeKey = entry.getKey();
                        }
                    }
                    map.remove(changeKey);
                } 
                    
                if(cacheSize > 0) {
                    map.put(city, time);                                
                }    
            }

                    
 
            
        }
        
        return time;
    }
}