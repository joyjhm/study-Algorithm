/*
다른 풀이
같은 벡터를 2개 만들고 하나의 벡터에서 중복을 없애고 오름차순 정렬한다.
vector에서 중복을 없애는 방법: cv.erase(unique(cv.begin(), cv.end()), cv.end());

중복을 제외하고 정렬한 벡터에서 lower_bound(원하는 값 k 이상이 처음 나오는 위치를 찾는 과정)를 써서 좌표의 값을 구한다.
lower_bound(v.begin(), v.end(), num) - v.begin();
*/

#include<iostream>
#include<map>
using namespace std;

int x[1000000];

map<int, int> m;

int n;
int main() {

    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
        m[x[i]] = 1;
    }
    int sum = 0;
    for(auto iter = m.begin(); iter != m.end(); ++iter) {
        int key = iter -> first;
        m[key] = sum;
        sum++; 
    }
    for(int i = 0; i < n; i++) {
        cout << m[x[i]] << " ";
    }
}
