#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

int read()
{
    int f = 1, x = 0;
    char ss = getchar();
    while (ss < '0' || ss > '9')
    {
        if (ss == '-')
            f = -1;
        ss = getchar();
    }
    while (ss >= '0' && ss <= '9')
    {
        x = x * 10 + ss - '0';
        ss = getchar();
    }
    return f * x;
}

void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

int n, k;
int tot, cnt;
struct node
{
    int v, nxt;
} E[200010];
int head[100010];
int dep[100010], size[100010], fa[100010], top[100010];
int son[100010], num[100010];
int sum[500010], set[500010], orsum[500010];
char ss[20];

void add(int u, int v)
{
    E[++tot].nxt = head[u];
    E[tot].v = v;
    head[u] = tot;
}

void dfs1(int u, int pa)
{
    size[u] = 1;
    for (int i = head[u]; i; i = E[i].nxt)
    {
        int v = E[i].v;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        size[u] += size[v];
        if (size[v] > size[son[u]])
            son[u] = v;
    }
}

void dfs2(int u, int tp)
{
    top[u] = tp;
    num[u] = ++cnt;
    if (son[u])
        dfs2(son[u], tp);
    for (int i = head[u]; i; i = E[i].nxt)
    {
        int v = E[i].v;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}

void push(int mid, int s, int t, int p)
{
    set[p << 1] = set[p << 1 | 1] = set[p];
    if (set[p] == 0)
        sum[p << 1] = sum[p << 1 | 1] = 0;
    else
        sum[p << 1] = mid - s + 1, sum[p << 1 | 1] = t - mid;
    set[p] = -1;
}

int getsum(int ll, int rr, int s, int t, int p, int w)
{
    if (ll <= s && t <= rr)
    {
        int ans = sum[p];
        set[p] = w;
        sum[p] = (t - s + 1) * w;
        return ans;
    } // 先记录答案，在更新，放标记，返回
    int mid = s + t >> 1;
    if (set[p] >= 0)
        push(mid, s, t, p);
    int ans = 0;
    if (ll <= mid)
        ans += getsum(ll, rr, s, mid, p << 1, w);
    if (rr > mid)
        ans += getsum(ll, rr, mid + 1, t, p << 1 | 1, w);
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
    return ans;
}

int qsum(int u, int v)
{
    int ans = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        ans += getsum(num[top[u]], num[u], 1, n, 1, 1);
        u = fa[top[u]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    ans += getsum(num[u], num[v], 1, n, 1, 1);
    return ans;
}

int main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int u = read() + 1;
        fa[i + 1] = u;
        add(u, i + 1);
    }

    dep[1] = 1;
    dfs1(1, -1);
    dfs2(1, 1);

    memset(set, -1, sizeof(set));
    int q = read();
    while (q--)
    {
        scanf("%s", &ss);
        int u = read() + 1, ans;

        if (ss[0] == 'i')
        {
            ans = qsum(u, 1);
            ans = dep[u] - ans;
        }

        else if (ss[0] == 'u')
            ans = getsum(num[u], num[u] + size[u] - 1, 1, n, 1, 0);

        print(ans);
        printf("\n");
    }
    return 0;
}