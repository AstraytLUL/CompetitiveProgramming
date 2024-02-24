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
    int n, k; cin >> n >> k;
    vector<int> a(n), x(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<int> cnt(n + 1, 0);
    for(int i = 0; i < n; ++i){
        cin >> x[i];
        int p = abs(x[i]);
        cnt[p] += a[i];
    }
    for(int i = n, carry = 0; i >= 0; --i){
        cnt[i] += carry;
        if(i != 0 && cnt[i] > k) carry = cnt[i] - k, cnt[i] = k;
        else carry = 0;
    }
    bool ok = 1;
    for(int i = n; i >= 1; --i){
        if(cnt[i] > k) ok = 0;
    }
    if(cnt[0] != 0) ok = 0;
    cout << (ok ? "Yes\n" : "No\n");
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
