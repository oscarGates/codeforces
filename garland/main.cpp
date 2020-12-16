#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.size();
    int m = t.size();
    vector<int> sFreq(26, 0);
    vector<int> tFreq(26, 0);
    for(int i = 0; i < n; i++){
        sFreq[s[i]-'a']++;
    }
    for(int i = 0; i < m; i++){
        tFreq[t[i] - 'a']++;
    }
    int ans = 0;
    for(int i = 0; i < 26; i++){
        if(sFreq[i] != 0 && tFreq[i] != 0){
            ans += min(sFreq[i], tFreq[i]);
        }
        if(tFreq[i] > 0 && sFreq[i] == 0) {
                cout << -1 << endl;
                return 0;

        }
    }

        cout << ans << endl;
    return 0;
}
