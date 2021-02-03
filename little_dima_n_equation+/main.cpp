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
const long long INF = 1000000000;
ll sumOfDigits(ll x){
    ll ans = 0;
    while(x > 0){
        ans += x% 10 ;
        x /= 10;
    }
    return ans;
}
ll powCust(ll x, ll po){
    ll ans = 1;
    while(po--)
        ans *= x;
    return ans;
}

int main() {
    ll a, b, c;
    cin >> a >>b >> c;
    set<ll> ans;
    for(int i = 0; i < 81; i++){
        ll formula = b * powCust(i, a) + c;
        if(i == sumOfDigits(formula) && formula > 0 && formula < INF){
            ans.insert(formula);
        }
    }
    cout << ans.size() << endl;
    for (auto it = ans.begin(); it !=
                             ans.end(); ++it)
        cout << *it << " ";
	return 0;
}