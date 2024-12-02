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
    if(n == 1) {
        cout << 0 << '\n';
        return;
    }
    n--;
    for(int len = 1, cur = 9; len <= 35; ++len){
        if(len % 2 == 1 && len != 1) cur *= 10;
        if(n - cur > 0){
            n -= cur;
            continue;
        }
        n--;
        vector<int> v(len);
        v[0] = v[len - 1] = 1;
        int mid = len / 2, l, r;
        if(len % 2 == 1){
            l = mid - 1, r = mid + 1;
            v[mid] += n % 10;
            n /= 10;
        }else{
            l = mid - 1, r = mid;
        }
        while(l != -1){
            v[l] += n % 10, v[r] += n % 10;
            --l, ++r, n /= 10;
        }
        for(auto x:v) cout << x;
        break;
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
