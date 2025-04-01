#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<bool> v(10);

vector<int> nowres(4);

void dfs(int index, int be)
{
    if (index == 4)
    {
        cout << nowres[1] << ' ' << nowres[2] << " " << nowres[3] << '\n';

        return;
    }
    if (index == 1)
        for (int i = be; i < 1000; i++)
        {
            string nowNumberString = to_string(i);
            if (nowNumberString[0] == nowNumberString[1] || nowNumberString[0] == nowNumberString[2] || nowNumberString[1] == nowNumberString[2])
                continue;
            bool flag = false;
            for (auto &j : nowNumberString)
                if (v[j - '0'])
                {
                    flag = true;
                    break;
                }
            if (flag)
                continue;

            nowres[index] = i;
            for (auto &j : nowNumberString)
                v[j - '0'] = true;

            dfs(index + 1, i << 1);

            nowres[index] = 0;
            for (auto &j : nowNumberString)
                v[j - '0'] = false;
        }
    else
    {
        int i = be;
        string nowNumberString = to_string(i);
        if (nowNumberString[0] == nowNumberString[1] || nowNumberString[0] == nowNumberString[2] || nowNumberString[1] == nowNumberString[2])
            return;
        bool flag = false;
        for (auto &j : nowNumberString)
            if (v[j - '0'])
            {
                flag = true;
                break;
            }
        if (flag)
            return;
        nowres[index] = i;
        for (auto &j : nowNumberString)
            v[j - '0'] = true;

        dfs(index + 1, nowres[1] * 3);

        nowres[index] = 0;
        for (auto &j : nowNumberString)
            v[j - '0'] = false;
    }
}

signed main()
{
    v[0] = true;
    dfs(1, 102);
    return 0;
}