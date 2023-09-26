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

void solve(){
    int n, ans = 0; cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; ++i) cin >> v[i];
    for(int j = 0; j < 32; ++j){
        vector<int> p(1, 0);
        int cnto = 0, cnte = 0, sumo = 0, sume = 0;
        for(int i = 1; i <= n; ++i){
            if((1<<j) & v[i]) {
                int c = p.size() % 2;
                int l = p.back() + 1, r = i;
                if(c){
                    cnto += (r - l + 1), cnto %= mod;
                    sumo += (r - l + 1) * (l + r) / 2 % mod, sumo %= mod;
                    int x = ((i + 1) * cnto - sumo) % mod;
                    ans = ans + x * (1<<j) % mod, ans %= mod;
                }else{ 
                    cnte += (r - l + 1), sume %= mod;
                    sume += (r - l + 1) * (l + r) / 2 % mod, sume %= mod;
                    int x = ((i + 1) * cnte - sume) % mod;
                    ans = ans + x * (1<<j) % mod, ans %= mod;
                }
                p.pb(i);
            }else{
                int c = p.size() % 2;
                if(c == 0){
                    int x = ((i + 1) * cnto - sumo) % mod;
                    ans = ans + x * (1<<j) % mod, ans %= mod;
                }else{
                    int x = ((i + 1) * cnte - sume) % mod;
                    ans = ans + x * (1<<j) % mod, ans %= mod;
                }
            }
        }
    }
    ans %= mod; ans += mod;
    cout << ans % mod << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
