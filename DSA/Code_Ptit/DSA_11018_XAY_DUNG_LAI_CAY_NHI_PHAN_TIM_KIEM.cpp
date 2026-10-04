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

/* Ý tưởng: Giống bài cho preOrder xây dựng lại cây BST
- Với dạng biểu diễn cho biết root của cây BST thì ta có thể xây dựng lại cây bằng thao
tác chèn từ root
*/

struct node{
    int data;
    node *left, *right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};

node* insert(node* root, int val){
    if(!root) return new node(val);

    if(root->data < val) root->right = insert(root->right, val);
    else if(root->data > val) root->left = insert(root->left, val);

    return root;
}

void preOrder(node *root){
    if(root){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
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

    preOrder(root);
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