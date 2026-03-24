import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        boolean hasZero = false;
        int ones = 0;

        List<Integer> plus = new ArrayList<>();
        List<Integer> minus = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());

            if (num > 1) {
                plus.add(num);
            }
            else if(num == 1) {
                ones++;
            }
            else if (num == 0) {
                hasZero = true;
            }
            else {
                minus.add(num);
            }
        }
        plus.sort(Collections.reverseOrder());
        minus.sort(Integer::compareTo);

        int sum = 0;

        for (int i = 0; i + 1 < plus.size(); i += 2) {
            sum += plus.get(i) * plus.get(i + 1);
        }
        if(plus.size() % 2 != 0) {
            sum += plus.get(plus.size() - 1);
        }
        sum += ones;

        for (int i = 0; i + 1 < minus.size(); i += 2) {
            sum += minus.get(i) * minus.get(i + 1);
        }

        if(minus.size() % 2 != 0 && !hasZero) {
            sum += minus.get(minus.size() - 1);
        }

        System.out.println(sum);
    }
}
