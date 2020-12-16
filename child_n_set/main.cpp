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

ll countDigits(ll i){
    ll cnt = 0;
    while(i % 2 == 0){
        cnt++;
        i /= 2;
    }
    return pow(2, cnt);
}

int main() {
    ll sum, limit;
    cin >> sum >> limit;
    vector<pair<ll, ll>> arr;
    for(int i = 1; i <= limit; i++){
        pair<ll, ll> aux;
        aux.first = countDigits(i);
        aux.second = i;
        arr.push_back(aux);
    }
    sort(arr.rbegin(), arr.rend());
    bool isAnswer = false;
    vector<ll> ans;
    ll sumAns = 0;
    for(int i = 0; i < arr.size(); i++){
        if(sumAns + arr[i].first <= sum){
            sumAns += arr[i].first;
            ans.push_back(arr[i].second);
        }
        if(sumAns == sum){
            isAnswer = true;
            break;
        }
    }
    if(!isAnswer){
        cout << -1 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
	return 0;
}
