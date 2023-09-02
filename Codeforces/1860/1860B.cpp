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
    int m, k, a1, ak; cin >> m >> k >> a1 >> ak;
    m -= k * ak;
    if(m < 0){
        m += k * ak;
        m %= k;
    }
    if(m <= a1) {
        cout << 0 << '\n';
        return;
    }
    m -= k * (a1 / k);
    int t = a1 / k;
    a1 %= k;
    if(a1 >= m % k){
        cout << m / k << '\n';
    }else{
        if(t == 0){
            m -= a1;
            cout << m / k + m % k << '\n';
        }else{
            cout << m / k + 1 << '\n';
        }
    }
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
