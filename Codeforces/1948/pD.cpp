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

int pw[5005];

void solve(){
    string s; cin >> s;
    int n = s.size();
    int ans = 0;
    pw[0] = 1;
    for(int i = 1; i < 5005; ++i) pw[i] = pw[i - 1] * 41 % mod;
    for(int t = 2; t <= (int) s.size(); t += 2){
        int L = 0, R = 0;
        int half = t / 2;
        queue<int> ql, qr;
        for(int i = 0; i < half; ++i){
            int l = i, r = i + half;
            if(s[l] == '?' || s[r] == '?'){
                L = L * 41 % mod;
                R = R * 41 % mod;
                ql.push(0);
                qr.push(0);
            }else{
                L = (s[l] + L * 41) % mod;
                R = (s[r] + R * 41) % mod;
                ql.push(s[l] * pw[half] % mod);
                qr.push(s[r] * pw[half] % mod);
            }
            
        }
        if(L == R) ans = t;
        for(int i = half; i + half < (int) s.size(); ++i){
            int l = i, r = i + half;
            if(s[l] == '?' || s[r] == '?'){
                L = L * 41 % mod;
                R = R * 41 % mod;
                ql.push(0);
                qr.push(0);
            }else{
                L = (s[l] + L * 41) % mod;
                R = (s[r] + R * 41) % mod;
                ql.push(s[l] * pw[half] % mod);
                qr.push(s[r] * pw[half] % mod);
            }
            L -= ql.front(); ql.pop();
            L = (L + mod) % mod;
            R -= qr.front(); qr.pop();
            R = (R + mod) % mod;
            if(L == R) ans = t;
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
