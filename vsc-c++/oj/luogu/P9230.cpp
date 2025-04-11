#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define ll long long
#define int long long

void solve1()
{
    auto comp = [&](string s) -> int
    {
        int ans = 0;
        for (auto &i : s)
            ans += i - '0';
        return ans;
    };

    int res = 0;
    for (int i = 10; i <= 100000000; ++i)
    {
        string now = to_string(i);
        if (now.size() & 1)
            continue;

        string left = now.substr(0, now.size() / 2);
        string right = now.substr(now.size() / 2);
        if (comp(left) == comp(right))
            ++res;
    }
    cout << res;
}

int res2;
void solve2(int cur, int tot)
{
    if (tot >= 10)
        return;
    if (cur > 30)
    {
        res2 += tot == 7;
        return;
    }
    if (tot == 7)
        ++res2;

    solve2(cur + 1, 0);
    solve2(cur + 1, tot + 1);
}

signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // solve1();

    // solve2(1, 0);
    // cout << res2;

    char pid;
    cin >> pid;
    if (pid == 'A')
        puts("4430091");
    else
        puts("8335366");

    return 0;
}