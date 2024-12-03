#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

class migong
{
public:
    int n, m; // 行 && 列
    int fx[4] = {1, 0, -1, 0};
    int fy[4] = {0, 1, 0, -1};

    // 判断是否在范围内
    bool in(int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    // 输出
    void print(vector<vector<bool>> &last, vector<vector<int>> &mp)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (last[i][j])
                    cout << "*";
                else
                    cout << mp[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }

    void main()
    {
        cin >> n >> m;

        // 0 = 路 1 = 墙 2 = 起点 3 = 终点
        vector<vector<int>> mp(n, vector<int>(m));     // 输入
        vector<vector<bool>> vis(n, vector<bool>(m));  // 访问
        vector<vector<bool>> last(n, vector<bool>(m)); // 答案
        for (auto &vec : mp)
            for (auto &i : vec)
                cin >> i;

        function<bool(int, int)> dfs = [&](int x, int y)
        {
            if (mp[x][y] == 3)
            {
                print(last, mp);
                return true;
            }

            for (int k = 0; k < 4; k++)
            {
                int nx = x + fx[k];
                int ny = y + fy[k];
                if (in(nx, ny) && !vis[nx][ny] && mp[nx][ny] != 1)
                {
                    vis[nx][ny] = true;
                    last[nx][ny] = true;
                    if (dfs(nx, ny))
                        return true;
                    last[nx][ny] = false; // 回溯
                }
            }
            return false;
        };

        // find beginning
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mp[i][j] == 2)
                {
                    vis[i][j] = true;
                    dfs(i, j);
                    return;
                }
    }
};

class nqueen
{
public:
    // broad size
    int n;

    // output
    void print(vector<vector<bool>> ans)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << (ans[i][j] ? "Q" : ".") << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    void main()
    {
        cin >> n;

        vector<bool> visrow(n, false), viscol(n, false), visl1(n, false), visl2(n, false);
        vector<vector<bool>> ans(n, vector<bool>(n, false));

        // 深度优先搜索函数，尝试在第 col 列放置皇后
        function<void(int)> dfs = [&](int col)
        {
            if (col == n)
            {
                print(ans);
                return;
            }

            // row
            for (int i = 0; i < n; i++)
            {
                if (!visrow[i] && !viscol[i] && !visl1[i + col] && !visl2[n - 1 - i + col])
                {
                    visrow[i] = viscol[i] = visl1[i + col] = visl2[n - 1 - i + col] = true;
                    ans[i][col] = true;

                    dfs(col + 1);

                    visrow[i] = viscol[i] = visl1[i + col] = visl2[n - 1 - i + col] = false;
                    ans[i][col] = false;
                }
            }
        };

        dfs(0);
    }
};

class zeroOnebag
{
    struct item
    {
        int v, w;              // 物品的价值和重量
        double valuePerWeight; // 物品的价值密度
    };

public:
    // 主函数
    void main()
    {
        // n: 物品数量, w: 背包容量, maxValue: 最大价值
        int n, w, maxValue = 0;
        cin >> n >> w;

        // 初始化物品列表
        vector<item> items(n);
        // 输入物品的价值和重量，并计算价值密度
        for (auto &i : items)
        {
            cin >> i.w >> i.v;
            i.valuePerWeight = (double)i.v / i.w;
        }

        // 排序
        sort(items.begin(), items.end(), [&](item a, item b)
             { return a.valuePerWeight > b.valuePerWeight; });

        // 定义获取上界函数
        function<double(int, int, int)> getUpperBound = [&](int index, int currentWeight, int currentValue)
        {
            double bound = currentValue;
            int totalWeight = currentWeight;

            // 遍历剩余物品，尝试添加到背包中
            for (int i = index; i < n && totalWeight < w; i++)
            {
                if (totalWeight + items[i].w <= w)
                    totalWeight += items[i].w, bound += items[i].v;
                else
                    bound += (w - totalWeight) * items[i].valuePerWeight, totalWeight = w;
            }
            return bound;
        };

        // 定义回溯函数
        function<void(int, int, int)> knapsack = [&](int index, int currentWeight, int currentValue)
        {
            // update res
            maxValue = max(maxValue, currentValue);

            // 边界条件
            if (index >= n || currentWeight >= w)
                return;

            // 剪枝
            if (getUpperBound(index, currentWeight, currentValue) <= maxValue)
                return;

            // choose
            if (currentWeight + items[index].w <= w)
                knapsack(index + 1, currentWeight + items[index].w, currentValue + items[index].v);

            // not choose
            knapsack(index + 1, currentWeight, currentValue);
        };

        // 从第一个物品开始回溯
        knapsack(0, 0, 0);
        // 输出最大价值
        cout << maxValue;
    }
};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int op;
    cin >> op;
    switch (op)
    {
    case 1:
        migong().main();
        break;

    case 2:
        nqueen().main();
        break;
    case 3:
        zeroOnebag().main();
        break;
    }

    return 0;
}