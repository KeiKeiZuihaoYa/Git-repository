#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;
int n, m, d, flag = 1, cnt;
map<int, int> mp;
char op;
queue<int> q;
vector<int> ans;

void init()
{
    mp.clear();
    ans.clear();
    while (!q.empty())
        q.pop();
    cnt = 0;
    flag = 1;
}

void del()
{
    cnt++;
    int now = -1;
    if (!mp.empty())
    {
        if (flag == 1)
        {
            map<int, int>::iterator it = mp.begin();
            now = (*it).first;
            if (--(*it).second == 0)
                mp.erase(now);
        }
        else
        {
            map<int, int>::reverse_iterator it = mp.rbegin();
            now = (*it).first;
            if (--(*it).second == 0)
                mp.erase(now);
        }
    }
    if (cnt == q.front())
    {
        q.pop();
        ans.push_back(now);
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
    {
        init();

        for (int i = 1, x; i <= m; i++)
        {
            cin >> x;
            q.push(x);
        }

        while (cin >> op && op != 'e')
        {
            if (op == 'a')
            {
                cin >> d;
                mp[d]++;
            }

            if (op == 'r')
                del();

            if (op == 'p')
                cin >> flag;
        }

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << '\n';
        cout << '\n';
    }

    return 0;
}