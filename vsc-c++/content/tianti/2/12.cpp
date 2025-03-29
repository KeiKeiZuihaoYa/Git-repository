#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;

    priority_queue<int, vector<int>, greater<int>> qright; // minn
    priority_queue<int, vector<int>, less<int>> qleft;     // maxx

    for (int i = 0; i < n; i++) // 0 -> 1   2 - > 2   4 - > 3
    {
        qright.push(v[i]);
        if (i % 2 == 0)
        {
            int limit = (i >> 1) + 1;
            // cout << limit << ' ';
            while (qright.size() > limit)
                qleft.push(qright.top()), qright.pop();
            while (qleft.size() && qright.size() && qleft.top() > qright.top())
            {
                int l = qleft.top(), r = qright.top();
                qleft.pop(), qright.pop();
                qleft.push(r), qright.push(l);
            }
            cout << qright.top() << '\n';
        }
    }

    return 0;
}