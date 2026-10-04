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

/* Ý tưởng: Có 2 cách xây dựng cây AVL
- Cách 1: Cho 1 mảng bắt xây AVL bằng cách insert sẽ cho ra nhiều cây AVl
=> Cùng 1 tập đỉnh sẽ tồn tại nhiều cây AVL thỏa mãn phụ thuộc vào thứ tự insert vào
// lấy chiều cao an toàn
int getHeight(node* root){
    return root ? root->height : 0;
}

// quay phải
node* rightRotate(node *z){
    node *x = z->left;
    node *y = x->right;

    x->right = z;
    z->left = y;

    // update height
    z->height = 1 + max(getHeight(z->left), getHeight(z->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

// quay trái
node* leftRotate(node *z){
    node *x = z->right;
    node *y = x->left;

    x->left = z;
    z->right = y;

    // update height
    z->height = 1 + max(getHeight(z->left), getHeight(z->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

// insert AVL
node* insert1(node *root, int val){
    // 1. insert như BST
    if(!root) return new node(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);
    else return root;

    // 2. update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. tính balance
    int bf = getHeight(root->left) - getHeight(root->right);

    // 4. 4 trường hợp

    // LL
    if(bf > 1 && val < root->left->data)
        return rightRotate(root);

    // RR
    if(bf < -1 && val > root->right->data)
        return leftRotate(root);

    // LR
    if(bf > 1 && val > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if(bf < -1 && val < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

- Cách 2: Build AVl từ 1 tập đỉnh nhưng luôn cho ra duy nhất 1 cây bằng cách luôn chọn
phần tử giữa làm root, xây dựng inorder của cây BST từ mảng cho trước
=> Cây là cây AVL hoàn hảo, ta luôn cố gắng lấy đỉnh ở giữa làm root sao cho luôn cân bằng
nhất có thể

node* buildAVL(vector<int>& v, int l, int r){
    if(l > r) return NULL;

    int mid = (l + r) / 2;
    node* root = new node(v[mid]);

    root->left = buildAVL(v, l, mid-1);
    root->right = buildAVL(v, mid+1, r);

    return root;
}

=> Cùng 1 tập và 1 thứ tự insert cố định (duyệt xuôi/ngược mảng) thì BST và AVL đều 
cho 1 cây BST và AVl duy nhất
=> AVL sẽ cho nhiều cây nếu cùng 1 tập đỉnh nhưng thứ tự insert khác nhau (xáo trộn mảng)
=> Tùy vào để ycau như nào ta sẽ build cây bằng 1 trong 2 cách trên
*/

struct node{
    int data, height;
    node *left, *right;

    node(int x){
        data = x;
        height = 1;
        left = right = NULL;
    }
};

// build cay BST
node* insert(node *root, int val){
    if(!root) return new node(val);
    if(root->data > val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    return root;
}

// inOrder
void inOrder(node *root, vector<int> &in){
    if(root){
        inOrder(root->left, in);
        in.push_back(root->data);
        inOrder(root->right, in);
    }
}

// build cay AVL
node* build_AVL(vector<int> &in, int l, int r){
    if(l > r) return NULL;

    int m = (l+r)/2;
    node *root = new node(in[m]);

    root->left = build_AVL(in, l, m-1);
    root->right = build_AVL(in, m+1, r);

    return root;
}

void solve() {
    int n;
    cin >> n;

    int a[n];
    for(int &x : a) cin >> x;

    node *root = new node(a[0]);
    for(int i=1; i<n; i++){
        root = insert(root, a[i]);
    }

    vector<int> in;
    inOrder(root,in);
    node *root_AVL = build_AVL(in,0,in.size()-1);
    cout << root_AVL->data << endl;
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