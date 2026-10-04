#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: Một cây nhị phân được gọi là cây đủ nếu tất cả các node trung gian của nó 
đều có hai node con.

*/

struct node{
    int data;
    node *left, *right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};

bool ok;
void makeNode(node *root, int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);

    ok = true;
}

void insertNode(node *root, int u, int v, char c){
    if(root == NULL) return;
    if(ok) return;

    if(root->data == u) makeNode(root,u,v,c);
    else{
        insertNode(root->left,u,v,c);
        insertNode(root->right,u,v,c);
    }
}

bool check = true;
void check_full_tree(node *root){
    if(root == NULL) return;
    if(root->left == NULL && root->right != NULL
    || root->right == NULL && root->left != NULL) check = false;
    
    if(root->left == NULL && root->right == NULL) return;
    else{
        check_full_tree(root->left);
        check_full_tree(root->right);
    }
}


void solve() {  
    int n;
    cin >> n;

    node *root = NULL;
    for(int i=0; i<n; i++){
        int u,v;
        char c;
        ok = false;

        cin >> u >> v >> c;
        if(root == NULL){
            root = new node(u);
            makeNode(root,u,v,c);
        }
        else insertNode(root,u,v,c);
    }
    
    check = true;
    check_full_tree(root);
    cout << (check ? 1 : 0) << endl;
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