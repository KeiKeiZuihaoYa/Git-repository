#include <bits/stdc++.h>
using namespace std;

// node -> address value NextNodeAddress
struct node
{
    int value;
    string Address, NextNodeAddress;
};

unordered_map<string, node> mp;

void printList(vector<node> &res1)
{
    for (int i = 0; i < res1.size(); i++)
    {
        cout << res1[i].Address << ' ' << res1[i].value << ' ' << (i == res1.size() - 1 ? "-1" : res1[i + 1].Address) << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string be;
    int n;
    cin >> be >> n;

    for (int i = 1; i <= n; ++i)
    {
        node now;
        cin >> now.Address >> now.value >> now.NextNodeAddress;
        mp[now.Address] = now;
    }

    vector<node> res1, res2;
    unordered_set<int> us; // 验证是否有出现相同的数值

    while (be != "-1")
    {
        node nowNode = mp[be];

        (us.count(abs(nowNode.value)) ? res2.push_back(nowNode) : res1.push_back(nowNode));
        be = nowNode.NextNodeAddress;
        us.insert(abs(nowNode.value));
    }

    printList(res1);
    printList(res2);

    return 0;
}