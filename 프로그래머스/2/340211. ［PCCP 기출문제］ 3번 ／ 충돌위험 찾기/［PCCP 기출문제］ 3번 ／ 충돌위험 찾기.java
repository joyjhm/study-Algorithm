import java.util.*;

class Solution {

    private static final int[] dy = {0,1,0,-1};
    private static final int[] dx = {1,0,-1,0};

    public static int move(
        int startY, int startX,
        int endY, int endX,
        int[][][] visited,
        int time,
        boolean includeStart
    ) {
        int yy = startY;
        int xx = startX;

        if (includeStart) {
            visited[yy][xx][time]++;
        }

        while (yy != endY) {
            time++;
            yy += yy < endY ? 1 : -1;
            visited[yy][xx][time]++;
        }

        while (xx != endX) {
            time++;
            xx += xx < endX ? 1 : -1;
            visited[yy][xx][time]++;
        }

        return time;
    }

    public int solution(int[][] points, int[][] routes) {
        int answer = 0;
        int[][][] visited = new int[101][101][19801];
        int max_time = 0;
        for (int i = 0; i < routes.length; i++) {
            int time = 0;
            for (int j = 0; j < routes[i].length - 1; j++) {
                int start = routes[i][j] - 1;
                int end = routes[i][j + 1] - 1;
                int startY = points[start][0];
                int startX = points[start][1];
                int endY = points[end][0];
                int endX = points[end][1];

                time = move(startY, startX, endY, endX, visited, time, j == 0);
                max_time = Math.max(max_time, time);
            } 
        }

        for (int i = 1; i <= 100; i++) {
            for (int j = 1; j <= 100; j++) {
                for (int k = 0; k <= max_time; k++) {
                    if(visited[i][j][k] > 1) {
                        answer++;
                    }                           
                }
            }
        }
        
        return answer;
    }
}