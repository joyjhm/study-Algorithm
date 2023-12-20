#include<iostream>

using namespace std;

struct Node {

    char name;
    char left;
    char right;
};

int n;
char parent, left_child, right_child;
Node node[26];

void preOrder(Node n) {
    cout << n.name;

    if(n.left != '\0'){
        int idx = n.left - 65;
        preOrder(node[idx]);
    }

    if(n.right != '\0') {
        int idx = n.right - 65;
        preOrder(node[idx]);
    }
}
void inOrder(Node n) {
    if(n.left != '\0'){
        int idx = n.left - 65;
        inOrder(node[idx]);
    }
        cout << n.name;

    if(n.right != '\0') {
        int idx = n.right - 65;
        inOrder(node[idx]);
    }
}
void postOrder(Node n) {
    if(n.left != '\0'){
        int idx = n.left - 65;
        postOrder(node[idx]);
    }

    if(n.right != '\0') {
        int idx = n.right - 65;
        postOrder(node[idx]);
    }

    cout << n.name;



}

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> parent >> left_child >> right_child;
        node[parent - 65].name = parent;
        if(left_child != '.'){
            node[parent - 65].left = left_child;
        }
        if(right_child != '.'){
            node[parent - 65].right = right_child;
        }
    }

    preOrder(node[0]);
    cout << '\n';
    inOrder(node[0]);
    cout << '\n';
    postOrder(node[0]);
    cout << '\n';
}