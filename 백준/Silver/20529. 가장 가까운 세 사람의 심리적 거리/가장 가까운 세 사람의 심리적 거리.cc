#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int t, n;
string students[100001];
string mbti[16] = {"ISTJ", "ISFJ", "INFJ", "INTJ", "ISTP", "ISFP", "INFP", "INTP",
                   "ESTP", "ESFP", "ENFP", "ENTP", "ESTJ", "ESFJ", "ENFJ", "ENTJ" };
int isPresent[16];
int length[16][16];


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for(int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (mbti[i][0] != mbti[j][0]) {
                length[i][j] += 1;
            }
            if (mbti[i][1] != mbti[j][1]) {
                length[i][j] += 1;
            }
            if (mbti[i][2] != mbti[j][2]) {
                length[i][j] += 1;
            }
            if (mbti[i][3] != mbti[j][3]) {
                length[i][j] += 1;
            }
        }
    }

    while (t--) {
        cin >> n;
        int result =  100;
        memset(isPresent, 0, sizeof(isPresent));
        for(int i = 1; i <= n; i++) {
                cin >> students[i];
            }

        for(int i = 1; i <= n; i++) {
            for (int j = 0; j < 16; j++) {
                if(students[i] == mbti[j]) {
                    isPresent[j] += 1;
                }
            }
        }

        for(int i = 0; i < 16; i++){
            if(isPresent[i]) {
                isPresent[i]--;
                for(int j = 0; j < 16; j++) {
                    if(isPresent[j]) {
                        isPresent[j]--;
                    for(int k = 0; k < 16; k++) {
                        if(isPresent[k]) {
                            result = min(result, length[i][j] + length[i][k] +length[j][k]);
                        }
                    }
                      isPresent[j]++;
                    }
                }
                isPresent[i]++;
            }
        }
        cout << result << '\n';
    }
}