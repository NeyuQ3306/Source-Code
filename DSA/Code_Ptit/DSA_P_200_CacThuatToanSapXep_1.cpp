#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const long long mod = 1e9 + 7;
const int MAXN = 101;
ll n, m;
ll a[MAXN][MAXN];

/* Ý tưởng: Bài sắp xếp với dữ liệu "đẹp"-các phần tử có cùng số lượng chữ số
- Ta dùng radixsort bản chất là sắp xếp các theo chữ số từ hàng đơn vị -> chục > trăm -> ...
- Ta sắp xếp các chữ số này bằng countingsort - đếm phân phối
 + có thể cài đặt như sau: ĐPT(O(n))
  void countingSort(int a[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int index = (a[i] / exp) % 10;
        output[--count[index]] = a[i];
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

-> nhưng mà khó hiểu và khó cài đặt
 + Ta có thể cài đặt bằng map<int,vector<int>> với key là chữ số 0->9 và vector để lưu các phần tử
 có chữ số ở hàng đang xét trùng với key, thì khi duyệt lại map sẽ là các phần tử tăng dần theo chữ số
 hàng đang xét và vẫn giữ nguyên tính stable
 + Tối ưu và dễ cài đặt hơn nữa thì là code dưới, vì map dễ cài đặt nhưng truy cấp sẽ tốn thgian O(logn) 
 chậm hơn là ta dùng vector truy cập chỉ mất O(1)

*/

void countingsort(int a[], int n, int exp){
    vector<int> bucket[10]; // lưu các chữ số 0->9

    // phân loại các phần tử theo chữ số vào bucket
    for(int i=0; i<n; i++){
        int digit = (a[i]/exp) % 10;
        bucket[digit].push_back(a[i]);
    }

    // lưu lại cho a[] khi đã sắp xếp xong
    int idx = 0;
    for(int d=0; d<10; d++){
        for(int x : bucket[d])
            a[idx++] = x;
    }
}

void radixsort(int a[], int n){
    int max_val = *max_element(a,a+n);
    for(int exp = 1; max_val/exp > 0; exp *= 10){
        countingsort(a,n,exp);
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

        radixsort(a,n);

        for(int x : a)
            cout << x << ' ';
        cout << endl;
    }

    return 0;
}