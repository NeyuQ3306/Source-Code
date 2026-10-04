#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: Cây nhị phân hoàn hảo (perfect binary tree): mỗi node trung gian đều có 2 con 
và mọi node lá đều cùng mức
- Đệ quy ở mỗi node kiểm tra xem có đủ 2 node con hay ko
- Tính toán mức = độ sâu của node
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
void makeNode(node *root, int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);

    ok = true;
}

void insertNode(node* root, int u, int v, char c){
    if(root == NULL) return;
    if(ok) return;

    if(root->data == u) makeNode(root,u,v,c);

    insertNode(root->left,u,v,c);
    insertNode(root->right,u,v,c);
}

set<int> se;
bool check;
int lev;

void check_perfect_tree(node *root, int lev){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) se.insert(lev);


    if(root->left == NULL && root->right != NULL
    || root->right == NULL && root->left != NULL) check = false;
    else{
        check_perfect_tree(root->left,lev+1);
        check_perfect_tree(root->right,lev+1);
    }
}

void solve() {
    int n;
    cin >> n;

    node *root = NULL;
    for(int i=0; i<n; i++){
        ok = false;
        int u,v;
        char c;
        cin >> u >> v >> c;

        if(root == NULL){
            root = new node(u);
            makeNode(root,u,v,c);
        }

        else insertNode(root,u,v,c);
    }

    se.clear();
    check = true;
    lev = 0;

    check_perfect_tree(root, lev);
    cout << (se.size() == 1 && check ? "Yes" : "No") << endl;
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