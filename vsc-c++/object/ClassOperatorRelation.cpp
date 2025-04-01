#include <iostream>
#include <string>
using namespace std;

class myClass
{
public:

	myClass(int v1, int v2) : val1(v1), val2(v2) {}

	bool operator==(const myClass& a) const
	{
		return val1 == a.val1 && val2 == a.val2;
	}

	bool operator!=(const myClass& a) const
	{
		return val1 != a.val1 || val2 != a.val2;
	}

private:
	int val1;
	int val2;
};

void test01()
{
	myClass p1(10, 20);
	myClass p2(20, 20);
	if (p1 != p2)
		cout << 1;
	else
		cout << 0;
}

signed main()
{
	test01();

	return 0;
}