#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int MAXN = 1e8 + 5;

bool isprime[MAXN]; // isprime[i]表示i是不是素数
int prime[MAXN];    // 现在已经筛出的素数列表
int n;              // 上限，即筛出<=n的素数
int cnt;            // 已经筛出的素数个数

void euler()
{
    memset(isprime, true, sizeof(isprime)); // 先全部标记为素数
    isprime[1] = false;                     // 1不是素数
    for (int i = 2; i <= n; ++i)            // i从2循环到n（外层循环）
    {
        if (isprime[i])
            prime[++cnt] = i;
        // 如果i没有被前面的数筛掉，则i是素数
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j)
        // 筛掉i的素数倍，即i的prime[j]倍
        // j循环枚举现在已经筛出的素数（内层循环）
        {
            isprime[i * prime[j]] = false;
            // 倍数标记为合数，也就是i用prime[j]把i * prime[j]筛掉了
            if (i % prime[j] == 0)
                break;
            // 最神奇的一句话，如果i整除prime[j]，退出循环
            // 这样可以保证线性的时间复杂度
        }
    }
}

int k, res;
vector<int> v, vis;

void dfs(int nowindex, int be, long long sum)
{
    if (nowindex >= k)
    {
        if (isprime[sum])
            res++;
        return;
    }
    for (int i = be; i < n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = 1;

        dfs(nowindex + 1, i + 1, sum + v[i]);
        vis[i] = 0;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    v.resize(n);
    vis.resize(n);
    euler();
    for (auto &i : v)
        cin >> i;
    dfs(0, 0, 0);
    cout << res;
    return 0;
}