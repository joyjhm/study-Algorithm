#include <iostream>
#include <vector>

using namespace std;

int isPresent[1000001];
int main() {

    int n;
    cin >> n;

    vector<int> score(n + 1);


    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        isPresent[num] = i;
    }

    for (int i = 1; i <= 1000000; i++) {

        if(isPresent[i]) {
            for (int j = i * 2; j <= 1000000; j += i) {
                if(isPresent[j]) {
                    score[isPresent[i]]++;
                    score[isPresent[j]]--;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << score[i] << " ";
    }


}