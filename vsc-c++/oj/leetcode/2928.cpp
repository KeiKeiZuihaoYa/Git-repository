#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = ;

int distributeCandies(int n, int limit)
{
    if (n >= limit * 3)
        return n == limit * 3;

    int res = 0;
    for (int i = 0; i <= limit; i++)
        for (int j = 0; j <= limit; j++)
            if (n - i - j >= 0 && n - i - j <= limit)
                res++;

    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    return 0;
}