#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f << 1;

int n;
string d;

void work(string &s)
{
    int jin = 0;
    for (auto &i : s)
    {
        if (i == '.')
            continue;
        int now = i - '0';
        now <<= 1;
        now += jin;
        jin = 0;
        if (now >= 10)
            jin = now / 10, now %= 10;
        i = now + '0';
    }
    if (jin)
        s += jin + '0';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> d;
    reverse(d.begin(), d.end());

    while (n--)
        work(d);

    string ans;
    for (int i = d.length() - 1; i >= 0; i--)
    {
        if (d[i] == '.' && i)
        {
            if (d[i - 1] >= '5')
            {
                for (int j = i + 1; j < d.length(); j++)
                {
                    if (d[j] == '9')
                        d[j] = '0';
                    else
                    {
                        d[j]++;
                        break;
                    }
                }
            }
            break;
        }
    }
    reverse(d.begin(), d.end());
    for (auto &i : d)
        if (i != '.')
            cout << i;
        else
            break;

    return 0;
}