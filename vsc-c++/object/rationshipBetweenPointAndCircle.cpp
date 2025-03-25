#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<double, double> P;
const int inf = 0x3f3f3f3f << 1;

class point
{
public:
    P getPoint()
    {
        return mPoint;
    }
    void setPoint(P point)
    {
        mPoint = point;
    }
private:
    P mPoint;
};

class circle
{
public:
    void setR(double r)
    {
        m_r = r;
    }
    void setCenter(point center)
    {
        m_center = center;
    }
    
    double getR()
    {
        return m_r;
    }
    point getCenter()
    {
        return m_center;
    }
private:
    double m_r;
    point m_center;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    return 0;
}