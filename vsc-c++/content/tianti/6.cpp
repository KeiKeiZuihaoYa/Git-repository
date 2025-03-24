#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<P> v(n);
    for (auto &i : v)
        cin >> i.first;
    for (int i = 0; i < n; i++)
        v[i].second = i + 1;
    sort(v.begin(), v.end());
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        cout << v[i].second << ' ';
        v[i].first *= (n - i - 1);
        sum += v[i].first;
    }

    cout << '\n'
         << fixed << setprecision(2) << sum / v.size();

    return 0;
}