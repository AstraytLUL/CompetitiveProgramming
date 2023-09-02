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
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    int l = 0, r = 1e9;
    while(l != r){
        int mid = (l + r) / 2;
        vector<int> tmp1 = v, tmp2;
        for(auto &x:tmp1) x = max(0ll, x - mid);
        tmp2 = tmp1;
        sort(tmp2.begin(), tmp2.end());
        if(tmp1 == tmp2) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
