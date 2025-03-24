#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string a;

    getline(cin, a);
    int res = a.length();
    for(auto &i : a)
        if(i == ' ')
            res--;

    cout << res;

    return 0;
}