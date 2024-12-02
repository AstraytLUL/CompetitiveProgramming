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

int A[105], B[105], P[105], Q[105];

void solve(){
    int n, x; cin >> n >> x;
    int l = 0, r = 1e9 + 1;
    for(int i = 1; i <= n; ++i){
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
        if(A[i] * Q[i] < B[i] * P[i]) swap(A[i], B[i]), swap(P[i], Q[i]);
    }
    while(l < r - 1){
        int mid = (l + r) / 2; 
        int cost = 0;
        for(int i = 1; i <= n; ++i){
            int s = 0, t = 0;
            s = mid / A[i];
            if(s * A[i] < mid) s++;
            int c = s * P[i];
            for(int k = s - 1; k >= max(0ll, s - 1000); --k){
                int rem = mid - k * A[i];
                t = rem / B[i];
                if(t * B[i] < rem) t++;
                c = min(k * P[i] + t * Q[i], c);
            }
            cost += c;
        }
        if(cost > x) r = mid;
        else l = mid;
    }
    cout << l << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
