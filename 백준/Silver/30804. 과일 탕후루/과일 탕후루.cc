#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> fruit(n);
    vector<int> num(10);

    for (int i = 0; i < n; i++) {
        cin >> fruit[i];
    }

    int start = 0;
    int end = 0;

    int result = 0;
    int cnt = 0;
    int fruit_cnt = 0;

    while(end <= n - 1) {

        if(fruit_cnt < 2) {
            if(num[fruit[end]] == 0) {
                fruit_cnt++;
            }
        }
        else if(num[fruit[end]] == 0) {
            while(true) {
                num[fruit[start]]--;
                cnt--;
                if(num[fruit[start]] == 0){
                    start++;
                    break;
                }
                start++;
            }
        }

        num[fruit[end]]++;
        end++;
        cnt++;
        if(cnt > result) {
            result = cnt;
        }
    }

    cout << result;
}

