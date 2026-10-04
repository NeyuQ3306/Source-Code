#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: Tổng node lá phải thỏa 2 điều kiện
1. Nó là con phải của một node khác
2. Nó không có left và right
=> Duyệt dfs nhưng thêm tham số bool isRight để biết nó là con trái hay con phải 

- Bài này xây cây và duyệt bị mle ko biết tại sao =)) trick là đọc input ko cần xây cây
- Ta cần node lá phải nghĩa là nó là con phải của 1 node và ko có node con
+ char c đọc vào là R
+ thuộc vector rightChild và ko thuộc vector parent
*/

struct node{
    int data;
    node *left, *right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};

// node* build_tree(){
//     int n;
//     cin >> n;

//     unordered_map<int,node*> mp;
//     node* root = NULL;

//     for(int i=0; i<n; i++){
//         int u,v;
//         char c;
//         cin >> u >> v >> c;

//         if(mp.find(u) == mp.end()){
//             mp[u] = new node(u);
//             if(root == NULL) root = mp[u];
//         }

//         if(mp.find(v) == mp.end()){
//             mp[v] = new node(v);
//         }

//         if(c == 'L') mp[u]->left = mp[v];
//         else mp[u]->right = mp[v];
//     }

//     return root;
// }

// ll sum_right_leaf(node *root, bool isRight){
//     if(root == NULL) return 0;
//     // nếu là lá và là con phải trả về data
//     if(root->left == NULL && root->right == NULL && isRight) return root->data;
//     // nếu là node trung gian đệ quy tiếp
//     return sum_right_leaf(root->left,false) + sum_right_leaf(root->right, true);
// }

void solve() {
    int n;
    cin >> n;

    unordered_set<int> par, rightChild;
    for(int i=0; i<n; i++){
        int u,v;
        char c;
        cin >> u >> v >> c;

        par.insert(u);
        if(c == 'R') rightChild.insert(v);
    }

    ll ans = 0;
    for(auto x : rightChild){
        if(par.find(x) == par.end()) ans += x;
    }

    cout << ans << endl;
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