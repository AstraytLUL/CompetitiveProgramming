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
    int n; cin >> n;
    vector<int> p(n + 2), a(n + 2), b(n + 2);
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 2; i <= n; ++i){
        a[i] = p[i] - p[i - 1];
        b[n - i + 1] = p[n - i + 2] - p[n - i + 1];
    }
    a[2] = 1;
    b[n - 1] = 1;
    for(int i = 2; i <= n - 1; ++i){
        int dl = p[i] - p[i - 1], dr = p[i + 1] - p[i];
        if(dl < dr){
            b[i - 1] = 1;
        }else{
            a[i + 1] = 1;
        }
    }
    for(int i = 1; i <= n; ++i) a[i] += a[i - 1];
    for(int i = n; i >= 1; --i) b[i] += b[i + 1];
    int m; cin >> m;
    while(m--){
        int x, y; cin >> x >> y;
        if(x < y) cout << a[y] - a[x] << '\n';
        else cout << b[y] - b[x] << '\n';
    }
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
