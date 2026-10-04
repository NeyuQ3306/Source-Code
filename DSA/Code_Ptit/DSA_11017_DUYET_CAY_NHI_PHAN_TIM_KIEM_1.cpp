#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define sz size
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: Cho biểu diễn preOrder xác định được root, các phần tử sau chỉ cần chèn vào 
cây
*/

struct node{
    int data;
    node *left, *right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};

node* insert(node *root, int val){
    if(!root) return new node(val);

    if(root->data > val) root->left = insert(root->left, val);
    else if(root->data < val) root->right = insert(root->right, val);

    return root;
}

void postOrder(node *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int &x : a) cin >> x;

    node *root = new node(a[0]);
    for(int i=1; i<n; i++){
        root = insert(root, a[i]);
    }

    postOrder(root);
    cout << endl;
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