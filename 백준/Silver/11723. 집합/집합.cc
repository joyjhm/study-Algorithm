#include<iostream>
#include<string>
using namespace std;

int m;
int s[21];

void add(int x) {
    s[x] = 1;
}
void check(int x) {
    cout << s[x] << '\n';
}
void remove(int x) {
    s[x] = 0;
}
void toggle(int x){
    if(s[x]) {
        s[x] = 0;
    }
    else{
        s[x] = 1;
    }
}

void all() {
    for(int i = 1; i <= 20; i++) {
        s[i] = 1;
    }
}

void empty() {
    for(int i = 1; i <= 20; i++) {
        s[i] = 0;
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    for (int i = 0; i < m; i++) {
        string str;
        int x;
        cin >> str;
        if(str == "add") {
            cin >> x;
            add(x);
        }
        else if(str == "remove") {
            cin >> x;
            remove(x);
        }
        else if(str == "check") {
            cin >> x;
            check(x);
        }
        else if(str == "toggle") {
            cin >> x;
            toggle(x);
        }
        else if(str == "all") {
            all();
        }
        else {
            empty();
        }
    }

}