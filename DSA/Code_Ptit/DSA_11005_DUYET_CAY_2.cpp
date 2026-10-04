#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: LevelOrder cho root của subtree, inOrder cho cấu trúc subtree, đệ quy tất cả subtree
- Node đầu tiên của level-order → root
- Tìm root trong inorder
-Chia inorder:
    trái
    phải
- Lọc lại level-order:
    phần tử thuộc subtree trái
    phần tử thuộc subtree phải
- Đệ quy


=> Luôn đảm bảo thứ tự của Inorder: left -> root -> right là đúng
- Inorder chia cấu trúc cây trái phải, levelOrder xác định node trước sau
- Bước 3 chia inorder cho ta tập node subtree trái, phải
- Bước 4 khi lọc theo biểu diễn levelOrder ta được thứ tự mức các node 
*/

struct node{
    int data;
    node *left, *right;

    node(int x){
        data = x;
        left = right = NULL;
    }
};

node* build_tree(vector<int> lev, vector<int> in){
    // đã duyệt hết cây thì inorder rỗng
    if(in.empty()) return NULL;

    // Gọi đệ quy ta luôn có root của subtree là phần tử đầu của mảng level
    node *root = new node(lev[0]);

    // Xác định vị trí root trong in, có thể tối ưu hơn là dùng map mất O(logn) thay vì find O(n)
    int k = find(in.begin(), in.end(), lev[0]) - in.begin();

    // Chia tập node subtree trái, phải trong in phải dùng unordered_set để giữ đúng data
    vector<int> leftSubtr(in.begin(), in.begin()+k);
    vector<int> rightSubtr(in.begin()+k+1, in.end());
    
    unordered_set<int> leftSet(leftSubtr.begin(), leftSubtr.end());

    // Chia lại biểu diễn levelOrder theo subtree trái, phải
    vector<int> leftLevel, rightLevel;
    for(int i=1; i<lev.size(); i++){
        if(leftSet.count(lev[i])) leftLevel.push_back(lev[i]);
        else rightLevel.push_back(lev[i]);
    }

    // Đệ quy tiếp trên các subtree đã chia 
    root->left = build_tree(leftLevel, leftSubtr);
    root->right = build_tree(rightLevel, rightSubtr);


    // Sau khi xây dựng xong trả về node root của cây
    return root;
}

void postOrder(node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> in(n), lev(n);
    for(int i=0; i<n; i++) cin >> in[i];
    for(int i=0; i<n; i++) cin >> lev[i];

    node *root = build_tree(lev, in);
    postOrder(root);
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