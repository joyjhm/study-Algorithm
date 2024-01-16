#include<iostream>

using namespace std;

bool star[10000][10000];
int n;

int main() {

    cin >> n;
    int len = 2 * n - 1;
    int target = len / 2 + 1;
    star[1][target] = true;

    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= len; j++) {
            if(i % 3 == 1){
                if(star[i][j]) {
                    star[i + 1][j - 1] = true;
                    star[i + 1][j + 1] = true;
                }
            }
            else if (i % 3 == 2) {
                if(star[i][j]) {
                    star[i + 1][j - 1] = true;
                    star[i + 1][j] = true;
                    star[i + 1][j + 1] = true;
                }
            } 
            else {
                if(star[i][j]) {
                    cnt++;

                    if(cnt % 5 == 0) {
                        star[i + 1][j + 1] = true;
                    }
                    else if(cnt % 5 == 1) {
                        if(star[i + 1][j - 1]) {
                            star[i + 1][j - 1] = false;
                        }
                        else {
                            star[i + 1][j - 1] = true;
                        }
                    }

                }


            }
        }
    }                  

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= len; j++) {
            if(star[i][j]) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << '\n';
    }
    

}