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
#define mod 998244353

int fac[maxn];

void solve(){
    string s; cin >> s;
    int ans1 = 0, ans2 = 1, cnt = 1;
    s += "a";
    int n = s.size();
    for(int i = 1; i < n; ++i){
        if(s[i] == s[i - 1]) cnt++;
        else{
            ans1 += cnt - 1;
            ans2 = ans2 * cnt % mod;
            cnt = 1;
        }
    }
    cout << ans1 << ' ' << ans2 * fac[ans1] % mod << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    fac[0] = 1;
    for(int i = 1; i <= 2e5 + 2; ++i){
        fac[i] = i * fac[i - 1] % mod;
    }
    while(t--) solve();
}
