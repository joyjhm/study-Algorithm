#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int x;
    int y;
    struct Node* left = nullptr;
    struct Node* right = nullptr;
    int idx;
    
    void setVal(int x, int y, int idx) {
        this-> x = x;
        this-> y = y;
        this-> idx = idx;
    }
    
    void printNode() {
        cout << this->x << " " << this->y << '\n';
    }
};
vector<int> v[2];

bool compare(vector<int> v1, vector<int> v2) {

    
    if(v1[1] == v2[1]) {
        return v1[0] < v2[0];
    } 
    else {
        return v1[1] > v2[1];
    }
}

void preOrder(Node* node) {
    if(node != nullptr) {
        v[0].push_back(node->idx);
        preOrder(node->left);
        preOrder(node->right);
    }

}

void postOrder(Node* node) {
    if(node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        v[1].push_back(node->idx);
    }

}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<vector<int>> sortNodeInfo(nodeinfo.size());
    
    copy(nodeinfo.begin(), nodeinfo.end(), sortNodeInfo.begin());
    sort(sortNodeInfo.begin(), sortNodeInfo.end(), compare);
    
    Node node;
    
    for (int i = 0; i < sortNodeInfo.size(); i++) {
        int idx = find(nodeinfo.begin(), nodeinfo.end(), sortNodeInfo[i])
            - nodeinfo.begin() + 1;

        if(i == 0) {
            node.setVal(sortNodeInfo[i][0], sortNodeInfo[i][1], idx);
            continue;
        }
        
        Node* cur = &node;
        int cnt = 1;
        while(true) {
            if(cur->x > sortNodeInfo[i][0]) {
                if(cur->left == nullptr) {
                    Node* addNode = new Node;
                    addNode->setVal(sortNodeInfo[i][0], sortNodeInfo[i][1], idx);
                    cur->left = addNode;
                    break;
                }
                cur = cur -> left;
            } 
            else if (cur->x < sortNodeInfo[i][0]) {
                if(cur->right== nullptr) {
                    Node* addNode = new Node;
                    addNode->setVal(sortNodeInfo[i][0], sortNodeInfo[i][1], idx);
                    cur -> right = addNode;
                    break;
                }
                cur = cur -> right;
            }
            cnt++;
        }
    }
    
    preOrder(&node);
    postOrder(&node);

    answer.push_back(v[0]);
    answer.push_back(v[1]);
     
    return answer;
}