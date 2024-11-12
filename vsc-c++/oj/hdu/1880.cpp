#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> P;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    // unordered_map<string, string> m12, m21;
    vector<P> v; // zhouyu

    while (getline(cin, s) && s != "@END@")
    {
        string s1, s2;
        int i = 0;
        while (1)
            if (s[i] != ']')
                i++;
            else
                break;

        s1 = s.substr(0, i + 1), s2 = s.substr(i + 2);
        // m12[s1] = s2;
        // m21[s2] = s1;
        v.push_back({s1, s2});
    }

    int _;
    getline(cin, s), _ = stoi(s);
    vector<string> ans(_, "");

    unordered_map<string, set<int>> vq;
    for (int i = 0; i < _; i++)
    {
        getline(cin, s);
        vq[s].insert(i);
    }

    for (auto &[s1, s2] : v)
    {
        if (vq.find(s1) != vq.end())
        {
            for (auto &i : vq[s1])
                ans[i] = s2;
            vq.erase(s1);
        }
        if (vq.find(s2) != vq.end())
        {
            string tmp = s1.substr(1);
            tmp.pop_back();
            for (auto &i : vq[s2])
                ans[i] = tmp;
            vq.erase(s2);
        }
    }

    for (auto &i : ans)
    {
        if (i == "")
            cout << "what?\n";
        else
            cout << i << '\n';
    }

    return 0;
}