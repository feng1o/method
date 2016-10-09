//http://www.cnblogs.com/TenosDoIt/p/4024413.html
/*
点是否在三角形内
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
在一个二维坐标系中，已知三角形三个点的坐标ABC(逆时针顺序)，对于坐标系中任意一点D，判断改点是否在三角形内（点在三角形边上也认为在三角形内）。
输入
输入一组坐标数据（float类型），分表代表A、B、C、D四个点的坐标
输出
如果D点位于三角形ABC内，则输出“Yes”；
如果D点不位于三角形ABC内，则输出“No”；

样例输入
0.0 0.0 2.0 0.0 2.0 2.0 1.0 0.5
样例输出
YES

Hint
题目解析：
本题需要简单的几何知识，重点考察问题分析能力、算法实现能力和逻辑思维能力。
温馨提示

*/
#if 01
#include<string>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<algorithm>
#include<ctime>
#include<unordered_map>
#include<map>
#include<typeinfo>
#include<cmath>
#include<ctime>
#include<climits>
using namespace std;

//类定义：二维向量
class Vector2d
{
public:
	double x_;
	double y_;

public:
	Vector2d(double x, double y) :x_(x), y_(y){}
	Vector2d() :x_(0), y_(0){}

	//二维向量叉乘, 叉乘的结果其实是向量，方向垂直于两个向量组成的平面，这里我们只需要其大小和方向
	double CrossProduct(const Vector2d vec)
	{
		return x_*vec.y_ - y_*vec.x_;
	}

	//二维向量点积
	double DotProduct(const Vector2d vec)
	{
		return x_ * vec.x_ + y_ * vec.y_;
	}

	//二维向量减法
	Vector2d Minus(const Vector2d vec) const
	{
		return Vector2d(x_ - vec.x_, y_ - vec.y_);
	}

	//判断点M,N是否在直线AB的同一侧
	static bool IsPointAtSameSideOfLine(const Vector2d &pointM, const Vector2d &pointN,
		const Vector2d &pointA, const Vector2d &pointB)
	{
		Vector2d AB = pointB.Minus(pointA);
		Vector2d AM = pointM.Minus(pointA);
		Vector2d AN = pointN.Minus(pointA);

		//等于0时表示某个点在直线上
		return AB.CrossProduct(AM) * AB.CrossProduct(AN) >= 0;
	}
};

//三角形类
class Triangle
{
private:
	Vector2d pointA_, pointB_, pointC_;

public:
	Triangle(Vector2d point1, Vector2d point2, Vector2d point3)
		:pointA_(point1), pointB_(point2), pointC_(point3)
	{
		//todo 判断三点是否共线
	}

	//计算三角形面积
	double ComputeTriangleArea()
	{
		//依据两个向量的叉乘来计算，可参考http://blog.csdn.net/zxj1988/article/details/6260576
		Vector2d AB = pointB_.Minus(pointA_);
		Vector2d BC = pointC_.Minus(pointB_);
		return fabs(AB.CrossProduct(BC) / 2.0);
	}

	bool IsPointInTriangle1(const Vector2d pointP)
	{
		double area_ABC = ComputeTriangleArea();
		double area_PAB = Triangle(pointP, pointA_, pointB_).ComputeTriangleArea();
		double area_PAC = Triangle(pointP, pointA_, pointC_).ComputeTriangleArea();
		double area_PBC = Triangle(pointP, pointB_, pointC_).ComputeTriangleArea();

		if (fabs(area_PAB + area_PBC + area_PAC - area_ABC) < 0.000001)
			return true;
		else return false;
	}

	bool IsPointInTriangle2(const Vector2d pointP)
	{
		return Vector2d::IsPointAtSameSideOfLine(pointP, pointA_, pointB_, pointC_) &&
			Vector2d::IsPointAtSameSideOfLine(pointP, pointB_, pointA_, pointC_) &&
			Vector2d::IsPointAtSameSideOfLine(pointP, pointC_, pointA_, pointB_);
	}

	bool IsPointInTriangle3(const Vector2d pointP)
	{
		Vector2d AB = pointB_.Minus(pointA_);
		Vector2d AC = pointC_.Minus(pointA_);
		Vector2d AP = pointP.Minus(pointA_);
		double dot_ac_ac = AC.DotProduct(AC);
		double dot_ac_ab = AC.DotProduct(AB);
		double dot_ac_ap = AC.DotProduct(AP);
		double dot_ab_ab = AB.DotProduct(AB);
		double dot_ab_ap = AB.DotProduct(AP);

		double tmp = 1.0 / (dot_ac_ac * dot_ab_ab - dot_ac_ab * dot_ac_ab);

		double u = (dot_ab_ab * dot_ac_ap - dot_ac_ab * dot_ab_ap) * tmp;
		if (u < 0 || u > 1)
			return false;
		double v = (dot_ac_ac * dot_ab_ap - dot_ac_ab * dot_ac_ap) * tmp;
		if (v < 0 || v > 1)
			return false;

		return u + v <= 1;
	}

	bool IsPointInTriangle4(const Vector2d pointP)
	{
		Vector2d PA = pointA_.Minus(pointP);
		Vector2d PB = pointB_.Minus(pointP);
		Vector2d PC = pointC_.Minus(pointP);
		double t1 = PA.CrossProduct(PB);
		double t2 = PB.CrossProduct(PC);
		double t3 = PC.CrossProduct(PA);
		return t1*t2 >= 0 && t1*t3 >= 0;
	}
};


int main()
{
	float x1, y1, x2, y2, x3, y3, dx, dy;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> dx >> dy){
		Triangle tri(Vector2d(x1, y1), Vector2d(x2, y2), Vector2d(x3, y3));
		Vector2d point(dx, dy);
		//cout << tri.IsPointInTriangle1(point) << " ";
		if (tri.IsPointInTriangle1(point) == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	/*Triangle tri(Vector2d(1.2, 3.235), Vector2d(6.234, 6.235235), Vector2d(12.23, 0.23));
	srand(time(0));
	for (int i = 0; i < 20; ++i)
	{
		Vector2d point((rand()*1.0 / RAND_MAX) * 12, (rand()*1.0 / RAND_MAX) * 6);
		cout << point.x_ << " " << point.y_ << ":     ";
		cout << tri.IsPointInTriangle1(point) << " ";
		cout << tri.IsPointInTriangle2(point) << " ";
		cout << tri.IsPointInTriangle3(point) << " ";
		cout << tri.IsPointInTriangle4(point) << endl;

	}*/
}
#endif

/*
#include<string>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<algorithm>
#include<ctime>
#include<unordered_map>
#include<map>
#include<typeinfo>
#include<cmath>
#include<ctime>
#include<climits>

using namespace std;

class Vector2d
{
public:
	double x_;
	double y_;

public:
	Vector2d(double x, double y) :x_(x), y_(y){}

	Vector2d() :x_(0), y_(0){}

	double CrossProduct(const Vector2d vec){
		return x_*vec.y_ - y_*vec.x_;
	}

	double DotProduct(const Vector2d vec){
		return x_ * vec.x_ + y_ * vec.y_;
	}

	Vector2d Minus(const Vector2d vec) const
	{
		return Vector2d(x_ - vec.x_, y_ - vec.y_);
	}

	static bool IsPointAtSameSideOfLine(const Vector2d &pointM, const Vector2d &pointN,
		const Vector2d &pointA, const Vector2d &pointB)
	{
		Vector2d AB = pointB.Minus(pointA);
		Vector2d AM = pointM.Minus(pointA);
		Vector2d AN = pointN.Minus(pointA);

		return AB.CrossProduct(AM) * AB.CrossProduct(AN) >= 0;
	}
};


class Triangle
{
private:
	Vector2d pointA_, pointB_, pointC_;

public:
	Triangle(Vector2d point1, Vector2d point2, Vector2d point3)
		:pointA_(point1), pointB_(point2), pointC_(point3)
	{

	}


	double ComputeTriangleArea()
	{

		Vector2d AB = pointB_.Minus(pointA_);
		Vector2d BC = pointC_.Minus(pointB_);
		return fabs(AB.CrossProduct(BC) / 2.0);
	}

	bool IsPointInTriangle1(const Vector2d pointP)
	{
		double area_ABC = ComputeTriangleArea();
		double area_PAB = Triangle(pointP, pointA_, pointB_).ComputeTriangleArea();
		double area_PAC = Triangle(pointP, pointA_, pointC_).ComputeTriangleArea();
		double area_PBC = Triangle(pointP, pointB_, pointC_).ComputeTriangleArea();

		if (fabs(area_PAB + area_PBC + area_PAC - area_ABC) < 0.000001)
			return true;
		else return false;
	}
};


int main()
{
	float x1, y1, x2, y2, x3, y3, dx, dy;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> dx >> dy){
		Triangle tri(Vector2d(x1, y1), Vector2d(x2, y2), Vector2d(x3, y3));
		Vector2d point(dx, dy);
		//cout << tri.IsPointInTriangle1(point) << " ";
		if (tri.IsPointInTriangle1(point) == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}

*/