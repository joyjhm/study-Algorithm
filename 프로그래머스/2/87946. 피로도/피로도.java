import java.util.*;

class Solution {
    
    private int size;
    private boolean[] visited;
    private int result = 0;
    
    public void dfs(int k, int depth, int[][] dungeons) {
        
        if (result < depth) {
            result = depth;
        }
        
        
        for (int i = 0; i < size; i++) {
            int needCost = dungeons[i][0];
            int cost = dungeons[i][1];
            
            if(!visited[i] && k - needCost >= 0) {
                visited[i] = true;
                dfs(k - cost,depth + 1, dungeons);
                visited[i] = false;
            }
        }
        
    }
    
    public int solution(int k, int[][] dungeons) {
        int answer = -1;
        size = dungeons.length;
        visited = new boolean[size];
        Arrays.fill(visited, false);
        
        dfs(k, 0, dungeons);
        
        answer = result;
        
        return answer;
    }
}