#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: Bài toán cho biểu thức duyệt cây theo preorder và inorder cần tìm biểu thức duyệt theo
postorder
=> Bài toán tổng quát cho (inorder + postorder) || (inorder + preorder) xây dựng lại cây nhị phân duy nhất
- inorder quyết định cấu trúc cây, pre và post chỉ giúp xác định root của các subtree

📌 Quy trình
- Lấy phần tử đầu của preorder → root
- Tìm root trong inorder
- Chia inorder:
    Bên trái → cây con trái
    Bên phải → cây con phải
- Dựa vào số lượng node bên trái → chia preorder tương ứng
- Đệ quy

- vector pre,in lưu thứ tự duyệt các đỉnh của cây theo preorder và inorder (nên lưu bằng int)
- Các tham số preL, preR, inL, inR để xác định các subtree thay vì tạo mảng mới để lưu (chia nhỏ và đệ quy vào các subtree)
- map để đánh dấu vị trí root trong inorder để chia subtree, truy xuất nhanh 

Node* build(vector<char>& pre, int preL, int preR,
            vector<char>& in, int inL, int inR,
            unordered_map<char,int>& pos) {

    if(preL > preR || inL > inR) return NULL;

    // chọn ra root của mỗi subtree, lần đầu gọi hàm build thì sẽ là root của cả cây
    char rootVal = pre[preL];
    // mỗi lần lặp là 1 lần đi vào các subtree bên trái và bên phải, preorder[preL] là root của subtree đang xét
    Node* root = new Node(rootVal);

    // map để truy xuất vị trí nhanh, nếu duyệt để tìm mất O(n*số lần lặp đệ quy) => quá lớn
    int k = pos[rootVal]; // vị trí trong inorder, nhớ là inorder để chia subtree trái,phải và đệ quy tiếp
    int leftSize = k - inL;

    root->left = build(pre, preL+1, preL+leftSize,
                       in, inL, k-1, pos);

    root->right = build(pre, preL+leftSize+1, preR,
                        in, k+1, inR, pos);

    return root;
}

*/

struct node{
    int data;
    node *left, *right;

    node(int a){
        data = a;
        left = right = NULL;
    }
};

int n;
vector<int> pre, in;
int preL,preR,inL,inR;
map<int,int> mp;

node* build_tree(int preL, int preR, int inL, int inR){
    // tránh đệ quy quá sâu và đã duyệt hết các đỉnh
    if(preL > preR || inL > inR) return NULL;

    node *root = new node(pre[preL]);
    int k = mp[pre[preL]];
    int leftsize = k - inL;

    // xây dựng tiếp subtree trái, phải trên các mảng con của pre,in
    root->left = build_tree(preL+1, preL+leftsize, inL, k-1);
    root->right = build_tree(preL+leftsize+1, preR, k+1, inR);

    return root;
}

void postorder(node *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void solve() {
    cin >> n;
    preL = inL = 0;
    preR = inR = n-1;

    pre.clear();
    in.clear();
    mp.clear();

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        in.push_back(x);
        mp[x] = i;
    }
    
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        pre.push_back(x);
    }

    // for(int x : pre) cout << x << " ";
    // cout << endl;
    // for(int x : in) cout << x << " ";

    node* root = build_tree(preL,preR,inL,inR);
    postorder(root);
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