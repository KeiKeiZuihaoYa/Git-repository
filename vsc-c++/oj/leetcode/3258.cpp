#include <bits/stdc++.h>
using namespace std;

int countKConstraintSubstrings(string s, int k)
{
    int ss = s.length();
    int i = ss - 1, cnt0 = 0, cnt1 = 0, l = i, res = 0;

    vector<int> left(ss);
    while (i >= 0)
    {
        while ((cnt0 <= k || cnt1 <= k) && l >= 0)
        {
            s[l] == '0' ? cnt0++ : cnt1++;

            if (cnt0 <= k || cnt1 <= k)
                l--;
            else
            {
                s[l] == '0' ? cnt0-- : cnt1--;
                break;
            }
        }
        left[i] = l + 1;
        (s[i--] == '0' ? cnt0-- : cnt1--);
    }

    for (int i = 0; i < ss; i++)
        res += i - left[i] + 1;

    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    int k;
    s = "10101", k = 1;
    cout << countKConstraintSubstrings(s, k);

    return 0;
}