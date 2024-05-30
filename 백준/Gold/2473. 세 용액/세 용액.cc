#include <iostream>
#include <algorithm> 
#include <vector>
#include <cstdlib>
#define INF 3000000001
using namespace std;

vector<int> result(3);


int main() {

    int n;
    cin >> n;
    vector<long long> liquid(n);

    for (int i = 0; i < n; i++) {
        cin >> liquid[i]; 
    }

    sort(liquid.begin(), liquid.end());

    int start = 0;
    int end = n - 1;

    long long diff = INF;

    for (int i = 0; i < n; i++) {

        start = 0;
        end = n - 1;

        while(start < end) {

            if(start == i) {
                start++;
                continue;
            } else if (end == i) {
                end--;
                continue;
            }

            long long tmp = liquid[start] + liquid[i] + liquid[end];
            if (abs(tmp) < diff) {
                result[0] = liquid[start];
                result[1] = liquid[i];
                result[2] = liquid[end];
                diff = abs(tmp);
            }
            

            if(tmp < 0) {
                start++;
            } else {
                end--;
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result[0] << " " << result[1] << " " << result[2];
}
