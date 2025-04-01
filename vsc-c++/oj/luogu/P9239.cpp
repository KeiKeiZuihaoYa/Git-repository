#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solveA()
{
    string tmp = "5 6 8 6 9 1 1 2 4 9 1 9 8 2 3 6 4 7 7 5 9 5 0 3 8 7 5 8 1 5 8 6 1 8 3 0 3 7 9 2 7 0 5 8 8 5 7 0 9 9 1 9 4 4 6 8 6 3 3 8 5 1 6 3 4 6 7 0 7 8 2 7 6 8 9 5 6 5 6 1 4 0 1 0 0 9 4 8 0 9 1 2 8 5 0 2 5 3 3";
    vector<int> v;
    istringstream is(tmp);
    int t, n;
    while (is >> t)
        v.push_back(t);

    n = v.size();
    string now = "";
    unordered_set<string> ump;
    for (int i1 = 0; i1 < n; i1++)
    {
        if (v[i1] != 2)
            continue;
        for (int i2 = i1 + 1; i2 < n; i2++)
        {
            if (v[i2] != 0)
                continue;
            for (int i3 = i2 + 1; i3 < n; i3++)
            {
                if (v[i3] != 2)
                    continue;
                for (int i4 = i3 + 1; i4 < n; i4++)
                {
                    if (v[i4] != 3)
                        continue;
                    for (int i5 = i4 + 1; i5 < n; i5++)
                    {
                        if (v[i5] >= 2)
                            continue;
                        now += v[i5] + '0';
                        for (int i6 = i5 + 1; i6 < n; i6++)
                        {
                            if (v[i6] == 0)
                                continue;
                            now += v[i6] + '0';
                            for (int i7 = i6 + 1; i7 < n; i7++)
                            {
                                if (v[i7] > 3)
                                    continue;
                                now += v[i7] + '0';
                                for (int i8 = i7 + 1; i8 < n; i8++)
                                {
                                    now += v[i8] + '0';
                                    ump.insert(now);
                                    now.pop_back();
                                }
                                now.pop_back();
                            }
                            now.pop_back();
                        }
                        now.pop_back();
                    }
                }
            }
        }
    }

    for (auto &i : ump)
        cout << i << '\n';

    long long ans = 0;
    for (auto it = ump.begin(); it != ump.end(); ++it)
    {
        string now = *it;
        int mm = stoi(now.substr(0, 2));
        int dd = stoi(now.substr(2, 2));

        if (mm > 12 || dd > 31 || dd == 0 || mm == 0)
            continue;

        if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        {
            if (dd > 31)
                continue;
        }
        else if (mm == 2)
        {
            if (dd > 28)
                continue;
        }
        else if (dd > 30)
            continue;
        ans++;
    }
    cout << ans;
}

int L = 23333333;

double f(int x)
{
    return 1.0 * x * x * log2(x * 1.0 / L);
}

void solveB()
{
    double right = 11625907.5798 * -1 * L;
    for (int i = 0; i <= (L >> 1); i++)
    {
        double now = f(i) + f(L - i);
        if (now == right)
        {
            cout << i;
            break;
        }
    }
}

int main()
{
    //  solveA();
    // solveB();
    string ans[] = {
        "210",                  // 双引号中替换为 A 题的答案
        "The answer of task B", // 双引号中替换为 B 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}