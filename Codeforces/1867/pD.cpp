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
#include <unordered_map>
using namespace std;
typedef long long ll;
//#define int ll
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
    vector<int> b(n), tag(n);
    for(auto &x:b) cin >> x, x -= 1;
    int ok = 1;
    if(k == 1) {
        bool ok = 1;
        for(int i = 0; i < n; ++i) ok &= (b[i] == i);
        if(ok) cout << "Yes\n";
        else cout << "No\n";
        return;
    }
    vector<int> tmp, a(n, 0);
    for(int i = 0; i < n; ++i){
        if(tag[i]) continue;
        if(ok == 0) break;
        tmp.pb(i);
        a[i] = 1;
        tag[i] = 1;
        int cur = b[i];
        while(true){
            if(a[cur]){
                int sz = tmp.size() - a[cur] + 1;
                if(sz != k) ok = 0;
                break;
            }
            if(tag[cur]) break;
            tag[cur] = 1;
            tmp.pb(cur);
            a[cur] = tmp.size();
            cur = b[cur];
        }
        for(auto x:tmp) a[x] = 0;
        tmp.clear();
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
