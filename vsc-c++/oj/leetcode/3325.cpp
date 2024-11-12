#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s, int k)
{
    unordered_map<char, int> m;
    vector<int> freq[26];

    for (int i = 0; i < 26; i++)
        m[i + 'a'] = -1;

    for (int i = 0, cnt = 0; i < s.size(); i++)
    {
        int index = m[s[i]];
        if (index == -1)
        {
            index = m[s[i]] = cnt;
            cnt++;
        }
        freq[index].push_back(i);
    }

    int ans = 0, ss = s.length(), flag = 1;
    for (auto vec : freq)
    {
        if (vec.size() < k)
            continue;

        int start = 0, end = k - 1;
        if (flag)
            ans += vec[0];
        flag = vec[0] & flag;
        while (end < vec.size())
        {
            ans += ss - vec[end];

            start++;
            end++;
        }
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s = "abacb";
    int k = 2;
    cout << numberOfSubstrings(s, k);

    return 0;
}