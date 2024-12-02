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
    int n, m, tot = 0; cin >> n >> m;
    vector<int> cnt(m, 0), a(n);
    for(auto &x:a) cin >> x, x %= m, tot += x;
    cnt[a[0] % m] = 1;
    int sum = a[0], ans = 0;
    for(int i = 1; i < n; ++i){
        sum += a[i];
        sum %= m;
        ans += cnt[sum];
        int t = (m -(tot - sum) % m) % m;
        ans += cnt[t];
        cnt[sum]++;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
