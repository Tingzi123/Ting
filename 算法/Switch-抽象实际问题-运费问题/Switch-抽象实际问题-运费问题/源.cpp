/*运输公司计算运费：路程（s/km）越远，每公里运费越低，标准：
实际：						抽象：
s<250           没有折扣	c<1			c代表250的倍数
250 <= s <500   2%折扣		1<=c<2
500 <= s <1000  5%折扣		2<=c<4
1000 <=s <2000  8%折扣		4<=c<8
2000 <=s <3000  10%折扣		8<=c<12
3000 <= 3000    15%折扣	    12<=c      */
#include<iostream>
using namespace std;
int main()
{
	int c, s;
	float p, w, d, f;//p每吨运费，w货物重量，d折扣，f总运费
	cout << "Please enter p,w,s:";
	cin >> p >> w >> s;
	if (s >= 3000) c = 12;
	else c = s / 250;//s为整形变量，则C也为整形变量
	switch (c)
	{
	case 0:d = 0; break;
	case 1:d = 2; break;
	case 2:
	case 3:d = 5; break;
	case 4:
	case 5:
	case 6:
	case 7:d = 8; break;
	case 8:
	case 9:
	case 10:
	case 11:d = 10; break;
	case 12:d = 15; break;
	}
	f = p*w*s*(1 - d / 100.0);//f为浮点型
	cout << "freight= " << f << endl;
	return 0;
}