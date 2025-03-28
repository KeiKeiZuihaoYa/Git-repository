#include <iostream>
using namespace std;

class myInt
{
    friend ostream& operator<<(ostream& cout, const myInt& a);
public:

    myInt(const int& t1, const int& t2)
    {
        if (val1 != nullptr)
            delete val1, val1 = nullptr;

        val1 = new int(t1), val2 = t2;
    }

    myInt& operator=(const myInt& a)
    {
        int t1 = *a.val1, t2 = a.val2;

        if (val1 != nullptr)
            delete val1, val1 = nullptr;
        val1 = new int(t1), val2 = t2;

        return *this;
    }

    ~myInt()
    {
        if (val1 != nullptr)
            delete val1, val1 = nullptr;
    }

private:
    int *val1, val2;
};

ostream& operator<<(ostream& cout, const myInt& a)
{
    cout << a.val1;
    return cout;
}

void test01()
{
    myInt p1(10, 20);
    myInt p2(1, 20);
    myInt p3(100, 200);

    cout << p1 << ' ' << p2 << ' ' << p3;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    test01();

    return 0;
}