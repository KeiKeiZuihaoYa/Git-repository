#include <iostream>
using namespace std;

class myInt
{
    friend ostream& operator<<(ostream& cout, const myInt& a);
public:
    myInt(int val) : val(val) {}

    myInt operator+(const myInt& a)
    {
        return myInt(val + a.val);
    }

    myInt operator+(const int& a)
    {
        return myInt(val + a);
    }

    myInt operator-(const myInt& a)
    {
        return myInt(val - a.val);
    }

    myInt operator+=(const myInt& a)
    {
        val += a.val;
        return *this;
    }

private:
    int val;
};

ostream& operator<<(ostream& cout, const myInt& a)
{
    cout << a.val;
    return cout;
}

void test01()
{
    myInt t(10);
    myInt t1(20);

    myInt t3 = t + t1;
    myInt t4 = t - t1;
    t4 += (t4 += t1);
    cout << t4;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    test01();

    return 0;
}