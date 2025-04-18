import java.util.*;

class Solution {
    public int[] solution(int n, long left, long right) {
        int size = (int)(right - left + 1);
        int[] result = new int[size];
        
        for (long i = left, idx = 0; i <= right; i++, idx++) {
            int row = (int)(i / n);
            int col = (int)(i % n);
            result[(int)idx] = Math.max(row, col) + 1;
        }
        
        return result;
    }
}