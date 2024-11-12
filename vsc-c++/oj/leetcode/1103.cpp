#include <bits/stdc++.h>
using namespace std;

vector<int> distributeCandies(int candies, int num_people)
{
    vector<int> res(num_people);
    for (int i = 0, cnt = 0, sum = 0; sum <= candies; i++, sum += cnt)
    {
        i = i == num_people ? 0 : i;
        res[i] += min((++cnt), candies - sum);
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int candies = 7, num_people = 4;
    vector<int> res = distributeCandies(candies, num_people);
    return 0;
}