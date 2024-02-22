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
    int k, x, a; cin >> k >> x >> a;
    bool ok = 1;
    int loss = 0;
    for(int i = 1, bet = 1; i <= x; ++i){
        if(ok == 0) break;
        if(bet * (k - 1) <= loss){
            int l = 0, r = 1e9;
            while(l < r){
                int mid = (l + r) / 2;
                if(mid * (k - 1) <= loss) l = mid + 1;
                else r = mid;
            }
            bet = r;
        }
        loss += bet;
        if(loss >= a) ok = 0;
    }
    if(ok == 0){
        cout << "No\n";
    }else if((a - loss) * k <= a){
        cout << "No\n";
    }else{
        cout << "Yes\n";
    }
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
