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
bool recursive(vector<ll> arr, ll n, ll target){
    if(target == 0)
        return true;
    if(target < 0 || n == 0)
        return false;
    return recursive(arr, n -1, target - arr[n-1]) || recursive(arr, n - 1,target);
}

bool recursiveDP(vector<ll> arr, ll n, ll target){


    bool dp[n + 1][target + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= target; j++){
            if(j == 0)
                dp[i][j] = true;
            else
                dp[i][j] = false;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= target; j++){
            dp[i][j] = dp[i-1][j];
            bool val = (j - arr[i - 1] >= 0)? dp[i-1][j - arr[i - 1]]: false;
            dp[i][j] = dp[i][j] || val;
        }
    }
    return dp[n][target];

}

int main() {
    ll n;
    cin >> n;
    ll cnt = 0;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        arr[i] = x / 100;

        cnt += x / 100;
    }

    ll target = cnt / 2;

    if( cnt  % 2 == 0 && recursiveDP(arr, n, target)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

	return 0;
}
