#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

bool search(node *root, int val){
    if(root == NULL) return false;
    if(root->data == val) return true;
    else if(root->data > val) return search(root->left, val);
    else return search(root->right, val);
}

node* insert(node *root, int val){
    // chèn vào làm node con của 1 node lá
    if(root == NULL) return new node(val);

    // luôn chèn 1 node mới làm lá, dễ hiểu là tìm vị trí NULL phù hợp
    if(root->data > val) root->left = insert(root->left, val);
    else if(val > root->data) root->right = insert(root->right, val);

    // muốn giữ đúng cấu trúc cây ở mỗi lần đệ quy phải trả về root để gán làm node con 
    return root;
}

node *minNode(node *root){
    node *tmp = root;
    while(tmp != NULL && tmp->left != NULL){
        tmp = tmp->left;
    }

    return tmp;
}

node* deleteNode(node *root, int val){
    // đi tới root == NULL nếu ko tìm được node cần xóa
    if(root == NULL) return root;
    if(root->data > val) root->left = deleteNode(root->left, val);
    if(root->data < val) root->right = deleteNode(root->right, val);

    else{
        // th1 + th2
        // nếu là node lá, nhảy vào if(root->left == NULL) và tmp = NULL 
        // return về NULL coi như free node đang xét
        if(root->left == NULL){
            node *tmp = root->right;
            delete root;
            return tmp;
        }

        else if(root->right == NULL){
            node *tmp = root->left;
            delete root;
            return tmp;
        }

        // th3
        else{
            node *tmp = minNode(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }
    }

    return root;
}

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
              
    while(t--){
       solve(); 
    }
    return 0;
}