#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 1e5 + 10, M = 25;

int n, m;
int F[N][M], a[N];
#define max min
void stCreate()
{
    for (int i = 1; i <= n; i++)
        F[i][0] = a[i];
    int k = log2(n);
    for (int j = 1; j <= k; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            F[i][j] = max(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
}

inline int stQuery(int l, int r)
{
    int k = log2(r - l + 1);
    return max(F[l][k], F[r - (1 << k) + 1][k]);
}

void print() // for-testing
{
    int k = log2(n);
    for (int j = 0; j <= k; j++)
    {
        cout << "j: " << j << '\n';
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            cout << F[i][j] << ' ';
        cout << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    stCreate();
    // print();

    for (int i = m; i <= n; i++)
    {
        cout << stQuery(i - m + 1, i) << '\n';
    }
    return 0;
}