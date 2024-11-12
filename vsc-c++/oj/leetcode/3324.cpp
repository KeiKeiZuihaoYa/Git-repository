#include <bits/stdc++.h>
using namespace std;

vector<string> stringSequence(string target)
{
    vector<string> ans;
    string now;
    for (auto i : target)
    {
        now += 'a';
        ans.push_back(now);
        int limit = i - 'a';

        while (limit--)
        {
            now.back()++;
            ans.push_back(now);
        }
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string target = "he";
    vector<string> ans = stringSequence(target);
    for (auto i : ans)
        cout << i << '\n';
    return 0;
}