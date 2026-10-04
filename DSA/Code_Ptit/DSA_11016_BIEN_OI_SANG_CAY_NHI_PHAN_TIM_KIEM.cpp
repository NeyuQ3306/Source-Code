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

/* Ý tưởng: Từ cây NP ta tìm biểu diễn inorder -> sort -> xây cây BST dựa trên inorder
- Vì inorder có tính chất tăng dần, ko thể sử dụng pre/postorder
*/

struct node{
    int data;
    node *left, *right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};

void makeNode(node *root, int u, int v, int c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void insert(node *root, int u, int v, char c){
    if(!root) return;
    if(root->data == u) makeNode(root,u,v,c);
    
    insert(root->left,u,v,c);
    insert(root->right,u,v,c);
}

void inOrder(node *root, vector<int> &in){
    if(root){
        inOrder(root->left,in);
        in.push_back(root->data);
        inOrder(root->right,in);
    }
}

int idx = 0;
void build_bst(node *root, vector<int> &in){
    if(!root) return;
    build_bst(root->left,in);
    root->data = in[idx++];
    build_bst(root->right,in);
}

void inOrder1(node *root){
    if(root){
        inOrder1(root->left);
        cout << root->data << " ";
        inOrder1(root->right);
    }
}


void solve() {
    int n;
    cin >> n;

    node *root = NULL;
    for(int i=0; i<n; i++){
        int u,v;
        char c;
        cin >> u >> v >> c;

        if(!root){
            root = new node(u);
            makeNode(root,u,v,c);
        }
        else insert(root,u,v,c);
    }

    vector<int> in;
    inOrder(root,in);
    sort(in.begin(),in.end());

    idx = 0;
    build_bst(root,in);
    inOrder1(root);
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