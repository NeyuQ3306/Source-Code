#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: Xây cây và duyệt theo các cách nếu trùng nhau thì 2 cây bằng nhau
- Có thể có test làm cách trên vẫn sai thì viết hàm duyệt từng node tại từng vị trí của 2 cây
bool identical(node* a, node* b){
    if(a == NULL && b == NULL) return true;
    if(a == NULL || b == NULL) return false;

    return (a->data == b->data)
        && identical(a->left, b->left)
        && identical(a->right, b->right);
}
- Có thể tối ưu build cây bằng map sao cho thao tác insertNode từ O(n^2) xuống O(n) vì thao tác tìm
node chả chỉ mất O(1), phù hợp với bài toán cây nhị mõi với mỗi node là 1 giá trị riêng biệt
node* build_tree(int n){
    unordered_map<int, node*> mp;
    node* root = NULL;

    for(int i=0; i<n; i++){
        int u, v;
        char c;
        cin >> u >> v >> c;

        if(mp.find(u) == mp.end()){
            mp[u] = new node(u);
            if(root == NULL) root = mp[u];
        }

        if(mp.find(v) == mp.end()){
            mp[v] = new node(v);
        }

        if(c == 'L') mp[u]->left = mp[v];
        else mp[u]->right = mp[v];
    }

    return root;
}
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

vector<int> in1,in2;

void inOrder1(node *root){
    if(root != NULL){
        inOrder1(root->left);
        in1.push_back(root->data);
        inOrder1(root->right);
    }
}

void inOrder2(node *root){
    if(root != NULL){
        inOrder2(root->left);
        in2.push_back(root->data);
        inOrder2(root->right);
    }
}

void solve() {
    int n;
    cin >> n;

    // tree1
    node* root1 = NULL;
    for(int i=0; i<n; i++){
        int u,v;
        char c;
        ok = false;
        cin >> u >> v >> c;

        if(root1 == NULL){
            root1 = new node(u);
            makeNode(root1,u,v,c);
        }
        else insertNode(root1,u,v,c);
    }


    int m;
    cin >> m;

    // tree2
    node *root2 = NULL;
    for(int i=0; i<m; i++){
        int u,v;
        char c;
        ok = false;

        cin >> u >> v >> c;
        if(root2 == NULL){
            root2 = new node(u);
            makeNode(root2,u,v,c);
        }
        else insertNode(root2,u,v,c);
    }

    in1.clear();
    in2.clear();
    inOrder1(root1);
    inOrder2(root2);

    // for(int i=0; i<in1.size(); i++) cout << in1[i] << " ";
    // cout << endl;
    // for(int i=0; i<in2.size(); i++) cout << in2[i] << " ";

    cout << (in1 == in2 ? 1 : 0) << endl;
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