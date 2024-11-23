#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _, op, x;
    cin >> _;

    stack<int> s, maxx;

    while (_--)
    {
        cin >> op;
        if (op == 0)
        {
            cin >> x;
            s.push(x);
            if (maxx.empty() || maxx.top() <= x)
                maxx.push(x);
        }
        if (op == 1)
        {
            if (s.empty())
                continue;
                
            x = s.top();
            s.pop();
            if (maxx.top() == x)
                maxx.pop();
        }
        if (op == 2)
        {
            if (maxx.empty())
                cout << 0 << '\n';
            else
                cout << maxx.top() << '\n';
        }
    }

    return 0;
}