import java.util.*;

class Solution {
    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};
    boolean[][][] visited = new boolean[50][50][4];
    
    public int solution(String dirs) {
        int answer = 0;
        int y = 5;
        int x = 5;
        int idx;
        
        for (int i = 0; i < dirs.length(); i++) {
            if (dirs.charAt(i) == 'R') {
                idx = 0;
            }
            else if (dirs.charAt(i) == 'D') {
                idx = 1;
            }
            else if (dirs.charAt(i) == 'L') {
                idx = 2;
            }
            else {
                idx = 3;
            }
            
            int ty = y + dy[idx];
            int tx = x + dx[idx];
            
            if(ty > 10 || ty < 0 || tx > 10 || tx < 0) {
                continue;
            }
            
            if(!visited[ty][tx][(idx + 2) % 4] && !visited[y][x][idx]) {
                visited[ty][tx][(idx + 2) % 4] = true;
                visited[y][x][idx] = true;
                answer++;
            }
            
            y = ty;
            x = tx;
        }
        
        
        return answer;
    }
}