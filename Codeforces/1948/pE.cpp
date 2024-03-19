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
    int grp = min(n, k);
    int q = 0;
    vector<int> tmp, c;
    while(tmp.size() < n){
        int t = grp / 2;
        if(grp % 2 == 0) t--;
        for(int i = t; i >= 1; --i){
            tmp.pb(q * grp + i);
            c.pb(q + 1);
        }
        for(int i = grp; i > t; --i){
            tmp.pb(q * grp + i);
            c.pb(q + 1);
        }
        q++;
    }
    tmp.resize(n);
    map<int,int> ls;
    for(int i = 0; i < n; ++i) ls[tmp[i]] = i;
    int t = 1;
    for(auto [val, id]:ls){
        tmp[id] = t;
        t++;
    }
    for(int i = 0; i < n; ++i) cout << tmp[i] << ' ';
    cout << '\n' << q << '\n';
    for(int i = 0; i < n; ++i) cout << c[i] << ' ';
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
