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

/* Ý tưởng: In ra thứ tự postOrder
*/

struct node{
    int data;
    node *left, *right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};

node *insert(node *root, int val){
    if(!root) return new node(val);
    if(root->data > val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    return root;
}

void inOrder(node *root, vector<int> &in){
    if(root){
        inOrder(root->left, in);
        in.push_back(root->data);
        inOrder(root->right, in);
    }
}

node *build_avl(vector<int> &in, int l, int r){
    if(l > r) return NULL;

    int m = (l+r)/2;
    node *root = new node(in[m]);
    root->left = build_avl(in,l,m-1);
    root->right = build_avl(in,m+1,r);

    return root;
}

void preOrder(node *root){
    if(root){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
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

    node *root_bst = new node(a[0]);
    for(int i=1; i<n; i++) root_bst = insert(root_bst, a[i]);

    vector<int> in;
    inOrder(root_bst, in);
    node *root_avl = build_avl(in,0,in.size()-1);
    postOrder(root_avl);
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