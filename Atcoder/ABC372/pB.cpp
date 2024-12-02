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
    int m; cin >> m;
    int p[11];
    p[0] = 1;
    for(int i = 1; i <= 10; ++i) p[i] = p[i - 1] * 3;
    vector<int> v;
    for(int i = 10; i >= 0; --i){
        while(m - p[i] >= 0){
            m -= p[i];
            v.pb(i);
        }
    }
    cout << v.size() << '\n';
    for(auto &x:v) cout << x << ' ';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
