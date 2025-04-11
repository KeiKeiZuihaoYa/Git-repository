#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define ll long long
const int inf = 0x3f3f3f3f << 1;
const int N = 2e5 + 10;

int fx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
int fy[8] = {0, 0, -1, 1, -1, 1, 1, -1};

int n, m, k;
vector<vector<int>> e;
vector<bool> ans(N);

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    vector<vector<int>> tv1(n, vector<int>(m));
    e.swap(tv1);

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        queue<int> q;
        q.push(a);
        while (b--)
        {
            int f = q.front();
            q.pop();

            
        }
    }

    return 0;
}