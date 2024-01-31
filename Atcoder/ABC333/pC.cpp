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
    vector<int> v;
    for(int i = 1; i <= 15; ++i){
        for(int j = i; j <= 15; ++j){
            for(int k = j; k <= 15; ++k){
                int a = 0, b = 0, c = 0;
                for(int t = 0; t < i; ++t){
                    a = 10ll * a + 1;
                }
                for(int t = 0; t < j; ++t){
                    b = 10ll * b + 1;
                }
                for(int t = 0; t < k; ++t){
                    c = 10ll * c + 1;
                }
                v.pb(a + b + c);
            }
        }
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    cout << v[n - 1];
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
