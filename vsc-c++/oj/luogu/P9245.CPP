#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;

struct node
{
    // nodeId , w
    vector<P> gra;
    ll height;
};

int n, k;
vector<node> v;
vector<P> eular;
vector<int> firstVis;

void dfs(int u, int f, int nowdep)
{
    eular.push_back({u, nowdep});
    for (auto &[i, j] : v[u].gra)
    {
        if (i == f)
            continue;
        dfs(i, u, nowdep + 1);
        eular.push_back({u, nowdep});
    }
}

vector<vector<int>> st;
void buildST()
{
    int es = eular.size();
    int loges = log(es) + 1;
    st.resize(es, vector<int>(loges));
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    v.resize(n);
    firstVis.resize(n);
    for (int i = 1; i < n; i++)
    {
        int _u, _v, t;
        cin >> _u >> _v >> t;
        v[_u].gra.push_back({_v, t});
        v[_v].gra.push_back({_u, t});
    }

    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto &[i, j] : v[cur].gra)
        {
            if (v[i].height || i == 1)
                continue;
            v[i].height = v[cur].height + j;
            q.push(i);
        }
    }

    dfs(1, 0, 0);

    return 0;
}