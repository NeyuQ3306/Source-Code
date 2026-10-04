#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define sz size
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng:

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
    if(root->data < val) root->right = insert(root->right, val);

    return root;
}

void check_leaf(node *root){
    if(!root) return;
    if(!root->left && !root->right) cout << root->data << " ";
    check_leaf(root->left);
    check_leaf(root->right);
}

void preOrder(node *root){
    if(root){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int ans = 0;
void findHeight(node *root, int cnt){
    if(!root) return;
    if(!root->left && !root->right) ans = max(ans, cnt);

    findHeight(root->left, cnt + 1);
    findHeight(root->right, cnt + 1);
}

void NRL(node *root){
    if(root){
        cout << root->data << " ";
        NRL(root->right);
        NRL(root->left);
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

    ans = 0;
    findHeight(root, 1);
    cout << ans << endl;

    // NRL(root);
    // cout << endl;
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