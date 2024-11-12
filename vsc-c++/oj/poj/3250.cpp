#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
#define ll long long
#define int long long
const int inf = 9e18;
typedef pair<int, int> P;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

signed main()
{
    ll all = 0, n;
    n = read();
    ll a;
    stack<P> b;

    for (ll i = 1; i <= n + 1; i++)
    {
        if (i <= n)
            a = read();
        else
            a = inf;

        while (!b.empty() && (b.top().first <= a))
        {
            all += i - b.top().second - 1;
            b.pop();
        }
        b.push({a, i});
    }

    printf("%lld\n", all);
    return 0;
}