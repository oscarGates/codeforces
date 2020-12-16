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


void printSolution(vector<ll> arr, vector<bool> isOk, ll zeroes){
    ll sum = 0;
    for(int i = 0; i < arr.size(); i++ ){
        if(isOk[i])
            sum ++;
    }
    if(zeroes == sum){
        cout << 0 << endl;
        return;
    }

    for(int i = 0; i < arr.size(); i++){
        if(isOk[i])
            cout << arr[i];
    }
    cout << endl;
}

bool evaluate(ll pos, vector<bool> isOk){
    if(pos >= 0){
        isOk[pos] = false;
        return true;

    }
    return false;
}

ll searchMinModulo(vector<ll> arr, vector<bool> isOk, ll mod){
    for(int i = arr.size() - 1; i >= 0; i--){
        if(isOk[i] && arr[i] % 3 == mod){
            return i;
        }

    }
    return -1;
}

void applyCriteria(vector<ll> arr, vector <bool> isOk, ll zeroes, ll a, ll b){
       ll pos = searchMinModulo(arr, isOk, a);
       if(evaluate(pos, isOk)){
            isOk[pos] = false;
            printSolution(arr, isOk, zeroes);
            return;
       }
       pos = searchMinModulo(arr, isOk, b);
       if(!evaluate(pos, isOk)){
            cout << -1 << endl;
            return;
       }
       isOk[pos] = false;

       pos = searchMinModulo(arr, isOk, b);
        if(!evaluate(pos, isOk)){
            cout  << -1 << endl;
            return;
       }
       isOk[pos] = false;

       printSolution(arr, isOk, zeroes);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll zeroes = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] == 0)
            zeroes++;
    }
    if(zeroes == 0){
        cout << -1 << endl;
        return 0;
    }
    if(zeroes == n){
        cout << 0 << endl;
        return 0;
    }
    sort(arr.rbegin(), arr.rend());
    vector<bool> isCorrect(n, true);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    if(sum % 3 == 0){
         printSolution(arr, isCorrect, zeroes);
        return 0;
    }

    if(sum % 3 == 1){
       applyCriteria(arr, isCorrect, zeroes, 1, 2);
    } else {
        applyCriteria(arr, isCorrect, zeroes, 2, 1);
    }
	return 0;
}
