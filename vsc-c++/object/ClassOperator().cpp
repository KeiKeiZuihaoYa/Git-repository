#include <iostream>
#include <string>
#include <vector>
using namespace std;

class mySub
{
public:
	
	int operator()(const int& a, const int& b)
	{
		return a - b;
	}

	void operator()(const vector<int>& v)
	{
		val1 = v[0], val2 = v[1];
	}

	vector<int> operator()()
	{
		return vector<int>({ val1, val2 });
	}

private:
	int val1, val2;
};

void test01()
{
	vector<int> v({ 1,2,3,4,5 });
	mySub p1;
	p1(v);
	vector<int> tmp = p1();
	cout << p1(tmp[0], tmp[1]);
}

signed main()
{
	test01();
	return 0;
}