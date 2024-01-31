//ᗜˬᗜ
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
    string ans = "";
    for(int j = 0; j < n; ++j){

        for(int i = 0; i < k; ++i){
            ans += (char)('a' + i);
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
