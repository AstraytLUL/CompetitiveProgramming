//君の手を握ってしまったら
//孤独を知らないこの街には
//もう二度と帰ってくることはできないのでしょう
//君が手を差し伸べた 光で影が生まれる
//歌って聞かせて この話の続き
//連れて行って見たことない星まで
//さユリ - 花の塔
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>
#include <climits>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
typedef long long ll;
#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 200005
#define mod 1000000007

void solve(){
    int n, m, l;
    cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;

    cin >> m;
    vector<int> b(m);
    for(auto &x:b) cin >> x;

    cin >> l;
    vector<int> c(l);
    for(auto &x:c) cin >> x;

    set<int> st;

    for(int s = 0; s < n * m * l; ++s){
        int i = s / (l * m) % n, j = (s / l) % m, k = s % l;
        st.insert(a[i] + b[j] + c[k]);
    }
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        cout << (st.find(x) == st.end() ? "No" : "Yes") << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
