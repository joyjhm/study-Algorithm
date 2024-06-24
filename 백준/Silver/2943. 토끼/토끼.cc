#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    
    int k = sqrt(n);
    vector<int> cup(ceil((float)n / k));
    vector<int> match(n);

    for (int i = 0; i < m; i++) {
        int s, a;
        cin >> s >> a;
        a = a - 1;
        int end = a + s - 1;
        int result = 0;

        if(end != n - 1) {
            while(end % k != k - 1 && s > 0) {
                result += ++match[end--];
                s--;
            }
        }
        while(a % k != 0 && s > 0) {
            result += ++match[a++];
            s--;
        }

        if(s != 0) {
            for (int i = a / k; i <= end / k; i++) {
                result += ++cup[i];
            }
        }

        cout << result << '\n';
    }

}

