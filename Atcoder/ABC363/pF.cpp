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

bool check(int x){
    while(x != 0){
        if(x % 10 == 0) return 0;
        x /= 10;
    }
    return 1;
}

bool check_palin(int x){
    string s = to_string(x), t = to_string(x);
    reverse(s.begin(), s.end());
    return (s == t);
}

int rev(int x){
    int ret = 0;
    while(x != 0){
        ret *= 10;
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

void solve(){
    int n; cin >> n;
    vector<int> fac;
    set<int> dp;
    map<int, int> pre;
    for(int i = 1; i * i <= n; ++i){
        int x = i, y = n / i;
        if(x * y != n) continue;
        if(check(x)){
            fac.pb(x);
            if(check_palin(x)) dp.insert(x), pre[x] = x;
        }
        if(y != x && check(y)){
            fac.pb(y);
            if(check_palin(y)) dp.insert(y), pre[y] = y;
        }
    }
    for(auto x:fac){
        if(x == 1) continue;
        if(dp.find(n) != dp.end()) break;
        int k = x * rev(x);
        for(int y:dp){
            int ny = y * k;
            if(n % ny != 0 || dp.find(ny) != dp.end()) continue;
            dp.insert(ny);
            pre[ny] = y;
            if(n == ny) break;
        }
    }
    if(dp.find(n) == dp.end()){
        cout << "-1\n";
        return;
    }
    int cur = n;
    vector<int> tmp;
    while(cur != pre[cur]){
        int x = cur, y = pre[cur];
        tmp.pb(x / y);
        cur = pre[cur];
    }
    deque<int> ans;
    ans.pb(cur);
    for(int X:tmp){
        for(int x:fac){
            int y = rev(x);
            if(x * y == X){
                ans.pb(x);
                ans.push_front(y);
                break;
            }
        }
    }
    int t = ans.size();
    for(int i = 0; i < t; ++i){
        cout << ans[i] << "*\n"[i == t - 1 ? 1 : 0];
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
