#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int L = 5e6 + 10;

bool isprime[L];
int prime[L];
int cnt;

void euler()
{
    memset(isprime, true, sizeof isprime);
    isprime[1] = isprime[0] = 0;
    for (int i = 2; i < L; i++)
    {
        if (isprime[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] < L; j++)
        {
            isprime[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int n, m, res;
vector<int> v;

void dfs(int cur, int sum, int be)
{
    if (cur >= m)
    {
        res += isprime[sum];
        return;
    }
    for (int i = be; i < n; i++)
    {
        dfs(cur + 1, sum + v[i], i + 1);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    euler();
    cin >> n >> m;
    v.resize(n);
    for (auto &i : v)
        cin >> i;

    sort(v.begin(), v.end());
    dfs(0, 0, 0);

    cout << res;

    return 0;
}