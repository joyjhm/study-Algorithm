import java.util.*;

class Solution {
    
    private String convertToBaseN(int n, int k) {
        int num = n;
        StringBuilder str = new StringBuilder("");
        while(num != 0) {
            int rest = num % k;
            num = num / k;
            str.append(Integer.toString(rest)); 
            
        }
        
        
        return str.reverse().toString();
    }
    
    boolean isPrime(Long num) {
        
        if(num <= 1) {
            return false;
        }
        
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if(num % i == 0) {
                return false;
            }
        }
        

        return true;
    }
    
    public int solution(int n, int k) {
        int answer = 0;
        String str = convertToBaseN(n, k);
        
        String[] arr = str.split("0");
        Long[] numbers = Arrays.stream(arr)
            .filter(s -> !s.equals(""))  
            .map(Long::parseLong)            
            .toArray(Long[]::new);          

        for (int i = 0; i < numbers.length; i++) {
            if(isPrime(numbers[i])) {
                answer++;
            }
        }
        
        return answer;
    }
}