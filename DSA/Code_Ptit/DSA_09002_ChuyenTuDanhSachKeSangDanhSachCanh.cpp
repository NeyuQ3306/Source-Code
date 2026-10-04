#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;

/* Ý tưởng:

*/

int n,m;
// vector<vector<int>> adj(1001); // danh sach ke
vector<pair<int,int>> edge; // danh sach canh
// int a[1001][1001]; // ma tran ke

void solve() {
    cin >> n;
    cin.ignore();

    string s, num;
    for(int i=1; i<=n; i++){
        getline(cin,s);
        stringstream ss(s);

        while(ss >> num){
            if(stoi(num) > i) edge.push_back({i,stoi(num)});
        }
    }

    for(int i=0; i<edge.size(); i++){
        cout << edge[i].first << " " << edge[i].second << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
              
    while(t--){
       solve(); 
    }
    return 0;
}