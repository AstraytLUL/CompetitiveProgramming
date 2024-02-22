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
    int h, w, n; cin >> h >> w >> n;
    vector<int> a(n + 1), cnt(40, 0);
    for(int i = 1; i <= n; ++i) cin >> a[i], cnt[a[i]]++;
    priority_queue<pii> pq;
    if(h > w) swap(h, w);
    for(int i = 32; i >= 0; --i){
        int len = w, cap = 0;
        if(h < (1ll<<i)) continue;
        h -= (1ll<<i);
        for(int j = i; j >= 0; j--){
            if((1ll<<j) <= len) {
                int a = len / (1ll<<j), b = (1ll<<i) / (1ll<<j);
                cap += a * b;
                len %= (1ll<<j);
            }
            int sub = min(cap, cnt[j]);
            cap -= sub;
            cnt[j] -= sub;
            cap *= 4;
        }
    }
    int sum = 0;
    for(int i = 0; i <= 25; ++i){
        sum += cnt[i];
    }
    cout << (sum ? "No\n": "Yes\n");
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
