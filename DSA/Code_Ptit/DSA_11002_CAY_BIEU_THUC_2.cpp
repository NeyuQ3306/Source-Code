#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>

const long long mod = 1e9 + 7;

/* Ý tưởng: Bài này là duyệt theo mức, ta xây dựng cây bằng bfs và tính toán bằng dfs
- Với bài này chỉ cần duyệt trick trực tiếp input bằng queue là được:
void TestCase() {
    int n; cin >> n; cin.ignore();
    string s; getline(cin, s);
    queue<int> q;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == ' ') continue;
        if (isdigit(s[i])) {
            string tmp = "";
            while (isdigit(s[i])) {
                tmp = s[i--] + tmp;
            }
            i++;
            q.push(stoi(tmp));
        } else {
            int y = q.front(); q.pop();
            int x = q.front(); q.pop();
            q.push(Calculate(x, y, s[i]));
        }
    }
    cout << q.front();
}

- Cách tạo cây và duyệt tính toán bằng dfs (duyệt inorder: left->root->right)
node* build_tree_level(vector<string>& a) {
    if(a.empty()) return NULL;

    node* root = new node(a[0]);
    queue<node*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i < a.size()) {
        node* cur = q.front(); q.pop();

        // left
        cur->left = new node(a[i++]);
        q.push(cur->left);

        // right
        if(i < a.size()) {
            cur->right = new node(a[i++]);
            q.push(cur->right);
        }
    }

    return root;
}

ll eval(node* root) {
    if(!operation(root->data)) {
        return stoll(root->data);
    }

    ll left = eval(root->left);
    ll right = eval(root->right);

    return tinh(left, right, root->data);
}
*/

struct node{
    string data;
    node *left, *right;

    // constructor
    node(string v){
        data = v;
        left = right = NULL;
    }
};


bool isSign(string op){
    if(op == "+" || op == "-" || op == "*" || op == "/") return true;
    return false;
}

ll tinh(ll a, ll b, string op){
    if(op == "+") return a + b;
    if(op == "-") return a - b;
    if(op == "*") return a * b;
    if(op == "/") return a / b;

    return 0;
}


node* make_tree(vector<string> &a){
    node* root = new node(a[0]);
    queue<node*> q;
    q.push(root);

    int idx = 1;
    while(!q.empty() && idx < a.size()){
        node *cur = q.front();
        q.pop();

        cur->left = new node(a[idx++]);
        q.push(cur->left);
        

        if(idx < a.size()){
            cur->right = new node(a[idx++]);
            q.push(cur->right);
        }
    }

    return root;
}

ll tinhh(node *root){
    if(!isSign(root->data)) return stoll(root->data);

    ll a = tinhh(root->left);
    ll b = tinhh(root->right);

    return tinh(a,b,root->data);    
}


void solve() {
    int n;
    cin >> n;
    cin.ignore();

    string s;
    getline(cin, s);
    stringstream ss(s);
    string tok;
    vector<string> a;

    while(ss >> tok){
        a.push_back(tok);
    }

    node* root = make_tree(a);
    ll ans = tinhh(root);
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