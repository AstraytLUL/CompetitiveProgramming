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
    vector<int> v;
    for(int i = 1; i + k - 1 <= n; i += k){
        cout << "? " << i << endl;
        int x; cin >> x;
        v.pb(x);
        if(i + k > n){
            int ul = 0; 
            cout << "? " << i << endl;
            cin >> ul;
            if(i - k >= 1) cout << "? " << i - k << endl, cin >> ul;
        }
    }
    int r = n % k;
    int id = n - r / 2 - k + 1;
    int a, b;
    cout << "? " << id << endl;
    cin >> a;
    cout << "? " << id + r / 2 << endl;
    cin >> b;
    int ans = a ^ b;
    for(auto &x:v) ans ^= x;
    cout << "! " << ans << endl;
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
