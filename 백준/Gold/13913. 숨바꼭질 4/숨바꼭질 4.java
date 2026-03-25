import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int max_range = 100000;
        boolean[] visited = new boolean[max_range + 1];
        int[] parent = new int[max_range + 1];
        Queue<Integer> q = new LinkedList<>();
        q.add(n);
        parent[n] = -1;
        visited[n] = true;

        while (!q.isEmpty()) {
            int cur = q.poll();

            if (cur == k) {
                break;
            }

            if (cur + 1 <= max_range && !visited[cur + 1]) {
                parent[cur + 1] = cur;
                visited[cur + 1] = true;
                q.add(cur + 1);
            }

            if (cur - 1 >= 0 && !visited[cur - 1]) {
                parent[cur - 1] = cur;
                visited[cur - 1] = true;
                q.add(cur - 1);
            }

            if (cur * 2 <= max_range && !visited[cur * 2]) {
                parent[cur * 2] = cur;
                visited[cur * 2] = true;
                q.add(cur * 2);
            }
        }

        int idx = k;
        List<Integer> list = new ArrayList<>();
        list.add(k);
        while (parent[idx] != -1) {
            list.add(parent[idx]);
            idx = parent[idx];
        }

        System.out.println(list.size() - 1);

        for (int i = list.size() - 1; i >= 0; i--) {
            System.out.print(list.get(i) + " ");
        }
    }
}
