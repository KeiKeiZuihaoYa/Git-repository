#include <bits/stdc++.h>
using namespace std;
string a, b;
int ne[100000000];

string tran(string t)
{
    int tlen = t.length();
    for (int i = 0; i < tlen; i++)
    {
        if (t[i] >= 'A' && t[i] <= 'Z')
            t[i] += 32;
        if (t[i] == ' ')
            t[i] = '_';
    }
    return t;
}

int kmp(int pos)
{
    int i = 0, j = pos, alen = a.length(), blen = b.length();
    while (i < alen && j < blen)
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
            continue;
        }
        if (i == -1)
        {
            i = 0;
            j++;
            continue;
        }
        i = ne[i];
    }
    if (i >= alen)
        return j - alen;
    else
        return -1;
}

void getne()
{
    ne[0] = -1;
    int j = 0, k = -1, alen = a.length();
    while (j < alen)
    {
        if (k == -1 || a[j] == a[k])
        {
            j++, k++;
            if (a[j] == a[k])
                ne[j] = ne[k];
            else
                ne[j] = k;
        }
        else
            k = ne[k];
    }
}

int main()
{
    a = '_';
    b = '_';
    string temp;
    getline(cin, temp);
    a += temp;
    getline(cin, temp);
    b += temp;
    a += '_';
    b += '_';
    a = tran(a);
    b = tran(b);
    //	cout<<a<<" "<<b;
    getne();
    int fl = kmp(0);
    if (fl == -1)
        cout << "-1";
    else
    {
        int alen = a.length();
        int cnt = 1, t = kmp(fl + alen - 1);
        while (t != -1)
        {
            cnt++;
            t = kmp(t + alen - 1);
        }
        cout << cnt << " " << fl;
    }
    return 0;
}