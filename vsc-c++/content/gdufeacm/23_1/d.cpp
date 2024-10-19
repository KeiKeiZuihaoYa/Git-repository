#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 1e7 + 10, M = 1e4;

int d = 0;
int p[M] = {0};
int f[M] = {1, 1};

void init()
{

    for (int i = 2; i <= M; i++)
    {
        if (f[i] == 0)
        { // 如果没被标记过，那么i是质数
            p[d++] = i;
        }
        for (int j = 0; j < d; j++)
        {
            if (p[j] * i <= M)
            { // 标记以i为最大因数的数为不是素数（除了1和本身）
                f[p[j] * i] = 1;
            }
            else
            {
                break;
            }
            if (i % p[j] == 0)
            { // 如果p[j]是i的因数，那么后面的数都不是以i为最大因数的
                break;
            }
        }
    }
    for (int i = 0; i < d; i++)
    { // 打印1到n的质数
        cout << p[i] << ' ';
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        
    }
    return 0;
}