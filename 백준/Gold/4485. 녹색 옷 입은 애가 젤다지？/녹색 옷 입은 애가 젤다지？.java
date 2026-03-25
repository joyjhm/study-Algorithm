import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    public static int INF = 987654321;
    public static int[] dy = {0, 1, 0, -1};
    public static int[] dx = {1, 0, -1, 0};

    public static int dijkstra(ArrayList<ArrayList<Integer>> arr, int n) {

        PriorityQueue<Point> pq = new PriorityQueue<>(
                (p1, p2) -> {
                    if(p1.cost == p2.cost) {
                        if(p1.y == p2.y) {
                            return p1.x - p2.x;
                        }
                        return p1.y - p2.y;
                    }
                    return p1.cost - p2.cost;
                }
        );


        int[][] distance = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distance[i][j] = INF;
            }
        }
        pq.add(new Point(arr.get(0).get(0), 0, 0));
        distance[0][0] = arr.get(0).get(0);

        while(!pq.isEmpty()) {
            int cost = pq.peek().cost;
            int y = pq.peek().y;
            int x = pq.peek().x;
            pq.poll();

            if (cost > distance[y][x]) {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int ty = y + dy[i];
                int tx = x + dx[i];

                if(ty >= n || ty < 0 || tx >= n || tx < 0)
                    continue;

                if(distance[ty][tx] > cost + arr.get(ty).get(tx)) {
                    distance[ty][tx] = cost + arr.get(ty).get(tx);
                    pq.add(new Point(cost + arr.get(ty).get(tx), ty, tx));
                }
            }
        }

        return distance[n - 1][n - 1];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int idx = 1;
        while(true) {
            int n = Integer.parseInt(br.readLine());
            if(n == 0) {
                break;
            }

            ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                ArrayList<Integer> list = new ArrayList<>();
                for (int j = 0; j < n; j++) {
                    list.add(Integer.parseInt(st.nextToken()));
                }
                arr.add(list);
            }

            int value = dijkstra(arr, n);
            System.out.println("Problem " + idx + ": " + value);
            idx++;
        }
    }

    static class Point {
        int cost;
        int y;
        int x;

        Point(int cost, int y, int x) {
            this.cost = cost;
            this.y = y;
            this.x = x;
        }
    }
}
