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

void solve(int tc){
    int n; cin >> n;
    vector<int> X(n);
    for(auto &x:X) cin >> x;
    sort(X.begin(), X.end());
    int l = X[0] + X[1], r = X[n - 2] + X[n - 1];
    int ans = r - l;
    if(n == 5){
        l = X[0] + X[2];
        r = X[3] + X[4];
        ans = r - l;
        l = X[0] + X[1];
        r = X[2] + X[4];
        ans = max(ans, r - l);
    }
    //cerr << X[0] << ' ' << X[n - 1] << '\n';
    //cerr << "n = "<< n << ' ' << l << ' ' << r << '\n';
    cout << "Case #" << tc << ": ";
    cout << fixed << ans / 2.0 << '\n';
}

signed main(){
    starburst
    freopen("A_input.txt", "r", stdin);
    freopen("A_output.txt", "w", stdout);
    int t = 1; cin >> t;
    for(int i = 1; i <= t; ++i) solve(i);
}
