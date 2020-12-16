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


int main() {

    ll n, k;
    cin >> n >> k;
    vector<ll> arr(0);
    arr.pb(1);
    arr.pb(1);
    ll a = k +1;
    while(1){
        a++;
        ll aux = a -k;
        ll tmp = arr[aux - 1] * 2;
        if(aux > k){
            tmp -= arr[aux -1 - k];
        }
        if(tmp <= n)
            arr.pb(tmp);
        else break;
    }
    vector<ll> ans;
    for(int i = arr.size() - 1; i >= 0; i-- ){
        if(!ans.size() &&n == arr[i]){
            ans.pb(0); ans.pb(arr[i]);
            break;
        } if(arr[i] <= n) {
            ans.pb(arr[i]);
            n -= arr[i];
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size();i++){
        cout << ans[i] << " ";
    }
	return 0;
}
