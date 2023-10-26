#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;


void split(string str, char delimiter, int num[]) {
    stringstream ss(str);
    string temp;
    int index = 0;
    while(getline(ss, temp, delimiter)) {
        num[index] = stoi(temp);
        index++;
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;


    while(t--){
        int num[100000];
        bool isReverse = false;
        string p, arr;
        int n;
        map<char, int> m;
        cin >> p >> n >> arr;

        // 숫자 분리
        arr.erase(0,1);
        arr.erase(arr.length() - 1, arr.length());
        split(arr, ',', num);
        
        // R과 D의 개수 분리
        for(int i = 0; i < p.length(); i++) {
            m[p[i]]++;
        }
        int start = 0;
        int end = n - 1;
        if(m['D'] > n) {
            cout << "error" << '\n';
        }
        else {
            for(int i = 0; i < p.length(); i++) {
                if(p[i] == 'R') {
                    isReverse = (isReverse) ? false : true;
                }
                else {
                    if(isReverse) {
                        num[end--] = 0;
                        n--;
                    } else {
                        num[start++] = 0; 
                        n--;
                    }
                }
            }

            cout << '[';
            
            if(n == 0) {
                cout << ']' << '\n';
            }
            else {
                if(isReverse) {
                    for(int i = end; i > start; i--) {
                        cout << num[i] << ',';
                    } 
                    cout << num[start] << ']' << '\n';
                }
                else {
                    for(int i = start; i < end; i++) {
                        cout << num[i] << ',';
                    } 
                    cout << num[end] << ']' << '\n';
                }
            }
        }
    }
}