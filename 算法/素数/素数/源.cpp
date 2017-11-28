/*找出100-200间的全部素数
算法：
让m被  2 至 根号下m  除，如果m不能被该区间上任意数整除，则为素数*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int m, i, k, n = 0;
	bool prime;
	for (m = 101; m <= 200; m=m+2)//限定范围，增量为2，因为偶数一定不是素数
	{
		prime = true;//先设为真，即为素数
		k = int(sqrt(m));//k代表sqrt(m)的整数部分
		for (i = 2; i <= k; i++)//检查m在2到sqrt(m)范围内，能否被整除
			if (m%i == 0)
			{
				prime = false;//如果能整除，不是素数
				break;
			}
			if (prime)//如果为素数
			{
				cout << setw(5) << m;//输出m,字段宽度5
				n = n + 1;//累计个数
			}
			if (n % 10 == 0) cout << endl;//输出10个数 换行		
	}
	cout << endl;//最后一次执行换行
	return 0;
}

