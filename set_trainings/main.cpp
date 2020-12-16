#include <bits/stdc++.h>
using namespace std;
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;
//     vector<vector<int> > vec( n , vector<int> (m));
const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
ll n, k;
ll fuction(ll num){
    if(num < k)
        return 0;
    if(num > k)
        return 1;
    ll ans = 0;
    for(int i = 1; i <= k; i++){
        if(num - i > 0){
            ans += fuction(num - i);
        } else {
            ans += 0;
        }
    }
    return ans;
}
ll dp(){
    vector<ll> arr;
    arr.pb(0);
    arr.pb(1);
}

int main() {
    ll n, k, aux = 0;
    cin >> n >> k;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(k == arr[i]){
            aux++;
        }
    }
    if(aux == n){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;

    while(1){
        ll cnt = 0;
        ll last = -1;
        for(int i = n - 1 ; i >= 0; i--){
            if(arr[i] < k && arr[i] != last){
                last = arr[i];
                arr[i]++;
            }
            if(arr[i] == k){
                cnt++;
            }
        }
        ans++;

        if(cnt == n)
            break;
    }
    cout << ans << endl;
	return 0;
}
