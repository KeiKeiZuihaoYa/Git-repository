#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int n, m;
vector<int> ne;
string s, p;

void get_Next(string s) // 这个函数对字符串s进行预处理得到next数组
{
    int j = 0;
    ne[0] = 0; // 初始化
    for (int i = 1; i < s.size(); i++)
    { // i指针指向的是后缀末尾，j指针指向的是前缀末尾
        while (j > 0 && s[i] != s[j])
            j = ne[j - 1]; // 前后缀不相同，去找j前一位的最长相等前后缀
        if (s[i] == s[j])
            j++;   // 前后缀相同，j指针后移
        ne[i] = j; // 更新next数组
    }
}

void print(int l)
{
    for (int i = 0; i < l; i++)
        cout << ne[i] << ' ';
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l;
    cin >> l >> s;
    ne.resize(l + 10);
    get_Next(s);
    // print(l);
    cout << l - ne[l - 1];
    return 0;
}