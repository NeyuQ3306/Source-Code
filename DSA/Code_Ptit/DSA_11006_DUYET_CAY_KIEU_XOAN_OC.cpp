#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: Ta sử dụng 2 ngăn xếp, ngăn xếp 1 để in từ trái sang phải, ngăn xếp 2 để in từ phải
sang trái
- Lặp tới khi 2 ngăn xếp rỗng
- Ban đầu thêm root vào st1, lặp st1 pop các phần tử ra lần lượt
    Mỗi phần tử ta push node con của nó vào st2
- Duyệt st2, pop các phần tử ra lần lượt
    Mỗi phần tử ta push node con của nó vào st1

=> Duyệt từ phải sang trái thì đẩy vào stack theo thứ tự trái phải
=> Duyệt từ trái sang phải thì đẩy vào stack theo thứ tự phải trái
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
    
    insertNode(root->left,u,v,c);
    insertNode(root->right,u,v,c);
}

void spiralOrder(node *root){
    stack<node*> st1,st2;
    st1.push(root);

    while(!st1.empty() || !st2.empty()){
        while(!st1.empty()){
            node *tmp = st1.top();
            st1.pop();
            cout << tmp->data << " ";

            if(tmp->right != NULL) st2.push(tmp->right);
            if(tmp->left != NULL) st2.push(tmp->left);
        }

        while(!st2.empty()){
            node *tmp = st2.top();
            st2.pop();
            cout << tmp->data << " ";

            if(tmp->left != NULL) st1.push(tmp->left);
            if(tmp->right != NULL) st1.push(tmp->right);
        }
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

    spiralOrder(root);
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