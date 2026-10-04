#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng:

*/

void merge(int a[], int l, int m, int r){
    vector<int> x(a+l, a+m+1);
    vector<int> y(a+m+1, a+r+1);

    int i=0, j=0;
    while(i<x.size() && j<y.size()){
        if(x[i] < y[j])
            a[l++] = x[i++];
        else
            a[l++] = y[j++];
    }

    while(i<x.size())
        a[l++] = x[i++];
    while(j<y.size())
        a[l++] = y[j++];
}

void mergesort(int a[], int l, int r){
    if(l<r){ // co it nhat 2 phan tu
        int m = (l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputt.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int a[n];
        for(int &x : a)
            cin >> x;

        mergesort(a,0,n-1);

        for(int x : a)
            cout << x << ' ';
        cout << endl;
    }

    return 0;
}