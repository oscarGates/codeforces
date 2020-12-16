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

ll arrToInt(vector<ll> arr){
    ll ans = 0;
    for(int i = 0; i < arr.size(); i++){
        ans *= 10;
        ans += arr[i];
    }
    return ans;
}
ll res = 0;
ll minVal = INF * 100;
void backtracking(vector<ll> arr, ll pos, vector<ll> ans, vector<bool> isAvailable, ll n){
    if(pos == arr.size()){
        ll num = arrToInt(ans);
        if(num >= n){
            if(num - n < minVal){
                res = num;
                minVal = num - n;
            }
        }
        return;
    }
    for(int i = 0; i < arr.size(); i++){
        if(isAvailable[i]){
            isAvailable[i] = false;
            ans[pos] = arr[i];
            backtracking(arr, pos + 1, ans, isAvailable, n);
            isAvailable[i] = true;
        }
    }
}
int main() {
    string s;
    cin >> s;
    ll len = (s.size() % 2 == 0)? s.size(): s.size()+1;
    if(s[0] - '0' > 7)
        len += 2;
    vector<ll> arr(len);
    ll fours = len / 2;
    for(int i = 0; i < len; i++){
        if(fours > 0)
            arr[i] = 4;
        else
            arr[i] = 7;
        fours--;
    }


    vector<ll> ans(len);
    vector<bool> isAvailable(len, true);
    backtracking(arr, 0, ans, isAvailable, stoi(s));
    cout << res << endl;
    return 0;
}

