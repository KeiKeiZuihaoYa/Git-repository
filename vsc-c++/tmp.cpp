#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
const int N = 2e5;

unordered_map<int, int> mp;
int fa[N], cnt;
struct node
{
    int a, b, c;
};

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
        fa[fx] = fy;
}
int mpfind(int x)
{
    return mp.count(x) ? mp[x] : mp[x] = ++cnt;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        // 初始化
        cnt = 0;
        for (int i = 1; i <= 2 * n; i++)
            fa[i] = i;
        mp.clear();

        vector<node> v;
        for (int i = 0; i < n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;

            a = mpfind(a), b = mpfind(b);
            if (c == 0)
                v.push_back({a, b, c});
            else
                merge(a, b);
        }

        bool flag = true;
        for (auto it : v)
        {
            int a = it.a, b = it.b;
            if (find(a) == find(b))
            {
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}