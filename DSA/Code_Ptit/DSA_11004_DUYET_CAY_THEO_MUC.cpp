#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: Với input này ta xây cây bằng 2 hàm 1 hàm tìm node cha và 1 hàm insert node con
- Duyệt theo mức chính là duyệt bằng thuật toán bfs mất O(n)
*/

struct node{
    int data;
    node *left, *right;

    node(int a){
        data = a;
        left = right = NULL;
    }
};

bool ok = false;
// khi đã tìm được node cha, xác định là node con trái hay phải để tạo mới
void make_node(node* root, int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);

    ok = true;
}

// tìm node cha để chèn thêm cạnh cho cây, thêm biến bool để ngắt đệ quy khi tìm được node cha
void insert_node(node* root, int u, int v, char c){
    if(root == NULL) return;
    if(ok) return;

    if(root->data == u){
        make_node(root,u,v,c);
    }

    else{
        insert_node(root->right, u, v, c);
        insert_node(root->left, u, v, c);
    }
}

void levelOrder(node *root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* tmp = q.front();
        q.pop();

        cout << tmp->data << " ";
        if(tmp->left != NULL){
            q.push(tmp->left);
        }

        if(tmp->right != NULL){
            q.push(tmp->right);
        }
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
        
        // node root của cả cây phải tạo thủ công
        if(root == NULL){
            root = new node(u);
            make_node(root,u,v,c);
        }

        else{
            ok = false;
            insert_node(root,u,v,c);
        }
    }

    levelOrder(root);
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