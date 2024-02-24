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
    int n, m; cin >> n >> m;
    vector<int> val(n + 1, 0), pre(n + 1, 0);
    for(int i = 1; i <= n; ++i) cin >> val[i], pre[i] = (val[i] == 1);
    for(int i = 1; i <= n; ++i) pre[i] += pre[i - 1], val[i] = val[i] + val[i - 1];
    for(; m; --m){
        int l, r; cin >> l >> r;
        int sum = val[r] - val[l - 1], ones = pre[r] - pre[l - 1];
        sum -= (r - l + 1);
        if(sum >= ones && l != r) cout << "Yes\n";
        else cout << "No\n";
    }
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
