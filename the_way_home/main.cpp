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

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

ll recursiveSolution(vector<ll> arr, ll leap, ll n){
    if(n == 0)
        return 0;
    ll ans = INF;
    for(int i = 1; i <= leap; i++){
        if(n - i >= 0 && arr[n - i] == 1){
            ans = min(ans,1 + recursiveSolution(arr, leap, n - i));
        }
    }
    return ans;
}

ll dpSolution(vector<ll> arr, ll leap, ll n){
    vector<ll> dp(n + 1);
    dp[0] = 0;
    for(int j = 1; j <= n; j++){
        dp[j] = INF;
        if(arr[j] == 0)
            continue;
         for(int i = 1; i <= leap; i++){
            if(j - i  >= 0 && arr[j - i] == 1){
                dp[j] = min(dp[j],1 + dp[j - i]);
            }
        }
    }
    return dp[n];
}

int main() {
    ll n, leap;
    cin >> n >> leap;
    string s;
    cin >> s;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++){
        arr[i] = s[i] - '0';
    }
    ll aux = 0;
    for(int i = 0; i < n; i++){
        aux++;
        if(aux > leap){
            cout << -1 << endl;
            return 0;
        }
        if(arr[i] == 1)
            aux = 0;
    }
    cout << dpSolution(arr, leap, n - 1 ) << endl;
	return 0;
}
