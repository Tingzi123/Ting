/*公式：Π/4≈1-1/3+1/5-1/7+... 直到最后一项的绝对值小于10的-7次方为止*/
#include<iostream>
#include<iomanip>//控制格式头文件
#include<cmath>//c++中要用c的数学函数或其他东西时，应加头文件 并声明例为cmath等形式
using namespace std;
int mian()
{
	int s = 1;//s 分子
	double n = 1, t = 1, pi = 0;// n分母 t项数 pi为和
	while ((fabs(t)) > 1e-7)//fabs 绝对值
	{
		pi = pi + t;
		n = n + 2;
		s = -s;
		t = s / n;
	}
	pi = pi * 4;
	cout << "pi= " << setiosflags(ios::fixed) << setprecision(6) << pi << endl;//设置浮点数以固定小数位数显示，精度为6
	return 0;
}