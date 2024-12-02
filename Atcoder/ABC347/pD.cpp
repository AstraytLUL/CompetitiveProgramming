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
    int a, b, C; cin >> a >> b >> C;
    int X, Y;
    X = Y = 0;
    for(int i = 0; i < 60; ++i){
        if(C & (1ll << i)){
            if(a > b){
                a--;
                X ^= (1ll<<i);
            }else{
                b--;
                Y ^= (1ll<<i);
            }
        }
    }
    for(int i = 0; i < 60; ++i){
        if((C & (1ll << i)) == 0){
            if(a != 0 && b != 0){
                a--, b--;
                X ^= (1LL<<i);
                Y ^= (1LL<<i);
            }
        }
    }
    if(a == 0 && b == 0){
        cout << X << ' ' << Y << '\n';
    }else cout << -1 << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
