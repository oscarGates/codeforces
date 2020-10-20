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

bool haveSameChars(string s, string t){
    vector<ll> sFreq(26, 0);
    vector<ll> tFreq(26, 0);
    for(int i = 0; i < s.length(); i++){
        sFreq[s[i] - 'a']++;
    }

    for(int i = 0; i < t.length(); i++){
        tFreq[t[i] - 'a']++;

    }
    for(int i = 0; i < t.length(); i++){
        if(tFreq[t[i] - 'a'] > sFreq[t[i] - 'a'])
            return false;
    }

    return true;
}

bool isSubsequence(string s, string t){
     if(s.length() == 0 ) return true;
      if( t.length() == 0) return false;
      int dp = 0;
      int index = s.length() - 1;
      for(int i = t.length() - 1; i>=0; i--){
            if(index >= 0 && t[i] == s[index]){
              dp++;
              index--;
            }
      }
      return dp == s.length();
}

int main() {
    string s, t;
    cin >> s >> t;
    size_t found = s.find(t);

    if (isSubsequence( t, s)){

        cout << "automaton" << endl;

    } else if( haveSameChars(s, t)){

        if(s.length() == t.length()){

            cout << "array" << endl;

        } else {

            cout << "both" << endl;
        }

    } else {

        cout << "need tree" << endl;
    }

	return 0;
}
