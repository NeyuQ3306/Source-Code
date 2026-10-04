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
struct node{
    int data;
    node *left, *right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};

bool ok = false;

void makeNode(node* root, int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);

    ok = true;
}

void insertNode(node* root, int u, int v, char c){
    if(root == NULL) return;
    if(ok) return;
    if(root->data == u) makeNode(root,u,v,c);
    else{
        insertNode(root->left,u,v,c);
        insertNode(root->right,u,v,c);
    }
}

set<int> se;
int lev = 0;

// mức của 1 node lá = độ sâu của node lá đó
void check_level_leaf(node* root, int lev){
    if(root == NULL) return;

    // nếu root đang xét là node lá thì insert level 
    if(root->left == NULL && root->right == NULL) se.insert(lev);

    // nếu node đang xét là node trung gian, đệ quy tiếp với lev+1
    check_level_leaf(root->left, lev+1);
    check_level_leaf(root->right, lev+1);
}

void solve() {
    lev = 0;
    se.clear();

    int n;
    cin >> n;

    node* root = NULL;
    for(int i=0; i<n; i++){
        ok = false;
        int u,v;
        char c;
        cin >> u >> v >> c;

        if(root == NULL){
            root = new node(u);
            makeNode(root,u,v,c);
        }
        else{
            insertNode(root, u, v, c);
        }
    }

    check_level_leaf(root, lev);
    cout << (se.size() == 1 ? 1 : 0) << endl;
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