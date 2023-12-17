#include<iostream>
#include<map>
using namespace std;

int t, k, n;
char c;

int main() {

    cin >> t;
    while(t--){
        map<int, int> m;
        map<int, int>::iterator it;

        cin >> k;

        for(int i = 0; i < k; i++) {
            cin >> c >> n;
            if (c == 'I'){
                m[n] += 1;
            }
            else {
                if(!m.empty()) {
                    if(n == 1) {
                        it = --m.end();
                    }
                    else if(n == -1) {
                        it = m.begin();
                    }
                    it->second--;
                    if(it-> second == 0){
                        m.erase(it->first);
                    }
                }
            }
        }

            if(!m.empty()) {
                it = --m.end();
                int max = it->first;
                it = m.begin();
                int min = it->first;
                cout << max << " " << min << '\n';
            }
            else {
                cout << "EMPTY" << '\n';
            }


    }
}