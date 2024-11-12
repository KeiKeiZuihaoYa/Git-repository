#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

class bitsearch
{
    int target = 7;

public:
    int binary_search(vector<int> v, int l, int r)
    {
        if (l >= r)
            return l;

        int mid = (l + r) >> 1;

        if (v[mid] == target)
            return mid;

        if (v[mid] > target)
            return binary_search(v, l, mid);
        else
            return binary_search(v, mid + 1, r);
    }
    void work()
    {
        vector<int> v({6, 2, 3, 5, 9, 8, 7, 1, 4});
        sort(v.begin(), v.end());

        cout << binary_search(v, 0, v.size() - 1) << '\n';
    }
};

class maxsub
{
public:
    P lr;
    int max_subarray(vector<int> v, int l, int r)
    {
        if (l == r)
            return v[l];

        int mid = (l + r) >> 1, maxleft = 0, maxright = 0, lsub = max_subarray(v, l, mid), rsub = max_subarray(v, mid + 1, r);
        int side = max(lsub, rsub);
        P slr;
        if (side == lsub)
            slr = {l, mid};
        else
            slr = {mid + 1, r};

        int lindex, rindex;
        for (int i = mid, tmp = 0; i >= l; i--)
        {
            tmp += v[i];
            lindex = tmp > maxleft ? i : lindex;
            maxleft = max(maxleft, tmp);
        }
        for (int i = mid + 1, tmp = 0; i <= r; i++)
        {
            tmp += v[i];
            rindex = tmp > maxright ? i : rindex;
            maxright = max(maxright, tmp);
        }

        if (maxleft + maxright > side)
            lr = {lindex, rindex};
        else
            lr = slr;
        return max(side, maxleft + maxright);
    }
    void work()
    {
        vector<int> v({-2, 1, -3, 4, -1, 2, 1, -5, 4});
        cout << max_subarray(v, 0, v.size() - 1) << '\n';
        cout << lr.first << ' ' << lr.second << '\n';
    }
};

class MERGESORT
{
public:
    void merge(vector<int> &v, int l, int mid, int r)
    {
        vector<int> tmp(r - l + 1);

        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r)
            tmp[k++] = v[i] < v[j] ? v[i++] : v[j++];
        while (i <= mid)
            tmp[k++] = v[i++];
        while (j <= r)
            tmp[k++] = v[j++];

        copy(tmp.begin(), tmp.end(), v.begin() + l);
    }
    void mergesort(vector<int> &v, int l, int r)
    {
        if (l >= r)
            return;

        int mid = (l + r) >> 1;
        mergesort(v, l, mid);
        mergesort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
    void work()
    {
        vector<int> v({8, 3, 2, 9, 7, 1, 5, 4});
        mergesort(v, 0, v.size() - 1);

        for (auto i : v)
            cout << i << ' ';
        cout << '\n';
    }
};

class quicksort
{
public:
    int partition(vector<int> &v, int l, int r)
    {
        int pivot = v[l];
        while (l < r)
        {
            while (l < r && v[r] >= pivot)
                r--;
            v[l] = v[r];

            while (l < r && v[l] <= pivot)
                l++;
            v[r] = v[l];
        }
        v[l] = pivot;
        return l;
    }
    void quick(vector<int> &v, int l, int r)
    {
        if (l >= r)
            return;

        int mid = partition(v, l, r);
        quick(v, l, mid - 1);
        quick(v, mid + 1, r);
    }
    void work()
    {
        vector<int> v({8, 3, 2, 9, 7, 1, 5, 4});
        quick(v, 0, v.size() - 1);

        for (auto i : v)
            cout << i << ' ';
        cout << '\n';
    }
};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // 排序 + 查找 => O(nlogn) + O(logn)
    bitsearch bs;
    // bs.work();

    // O(logn)
    maxsub ms;
    // ms.work();

    // O(logn)
    MERGESORT MS;
    // MS.work();

    // O(logn)
    quicksort qs;
    qs.work();

    return 0;
}