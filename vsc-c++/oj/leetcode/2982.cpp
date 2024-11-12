#include <bits/stdc++.h>
using namespace std;

int maximumLength(string s)
{
    int n = s.length(), res = -1, cnt = 0, mid;

    unordered_map<char, vector<int>> mp;
    for (int i = 0, j = 0; i < n;)
    {
        char ch = s[i];

        while(j < n && s[j] == ch)
            j++;

        mp[ch].push_back(j - i);
        i = j;
    }

    for (auto &[_, vec] : mp)
    {
        int l = 1, r = n;
        while (l <= r)
        {
            mid = (l + r) >> 1, cnt = 0;
            for (int i = 0; i < vec.size(); i++)
                if (vec[i] >= mid)
                {
                    cnt += vec[i] - mid + 1;
                    if (cnt >= 3)
                        break;
                }

            if (cnt >= 3)
                l = mid + 1, res = max(res, mid);
            else
                r = mid - 1;
        }
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s = "ereerrrererrrererre";

    cout << maximumLength(s);

    return 0;
}