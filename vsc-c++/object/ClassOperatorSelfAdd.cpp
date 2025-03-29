#include <iostream>
using namespace std;

class myInt
{
    friend ostream& operator<<(ostream& cout, const myInt& a);
public:

    myInt(const int& val1, const int& val2) : val1(val1), val2(val2) {}

    // 前置递增 - 传自身 - 无参数签名
    myInt& operator++()
    {
        ++val1, ++val2;
        return *this;
    }

    // 后置递增 - 传旧值 - 有参数签名
    myInt operator++(int)
    {
        myInt tmp = *this;
        ++val1, ++val2;
        return tmp;
    }

    myInt& operator--()
    {
        --val1, --val2;
        return *this;
    }

    myInt operator--(int)
    {
        myInt tmp = *this;
        --val1, --val2;
        return tmp;
    }

private:
    int val1, val2;
};

ostream& operator<<(ostream& cout, const myInt& a)
{
    cout << a.val1 << ' ' << a.val2;
    return cout;
}

void test01()
{
    myInt p(10, 30);
    cout << ++p-- << '\n';
    cout << p << '\n';
}

void test02()
{
    myInt p(10, 30);
    cout << ++--p << '\n';
    cout << p;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    test01();
    test02();

    return 0;
}