    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    typedef pair<int, int> P;
    const int inf = 0x3f3f3f3f << 1;

    int cnt;

    bool ch(int x)
    {
        int flag = 1, res = 1;
        while (x)
        {
            if (flag == x % 10 % 2)
                flag ^= 1, x /= 10;
            else
            {
                res = 0;
                break;
            }
        }
        return res;
    }

    signed main()
    {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cnt += ch(i);

        cout << cnt;

        return 0;
    }