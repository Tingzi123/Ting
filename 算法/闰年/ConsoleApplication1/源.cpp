/*判断是否为闰年，算法：
1.能被4整除，但不能被一百整除
或者 2.能被100整除，又能被400整除（例2100年 不是闰年）
则为闰年
表达式：（year %4 == 0 && year %100 != 0 || year %400 == 0) 可以直接写这个表达式 下面程序用了很蠢的方法   */
#include<iostream>
using namespace std;
int main()
{
	int year;
	bool leap;
	cout << "Input a year:";
	cin >> year;
	if (year % 4 == 0)             //year能被4整除
	{
		if (year % 100 == 0)       //year能被4和100整除
		{


			if (year % 400 == 0)   //year能被4,100和400整除
			{
				leap = true;       //闰年 为真
			}
			else
			{
				leap = false;     //否则为假
			}

			        
		 }
		else
		{
			leap = true;         //year能4整除,但不能被100整除，一定是闰年 为真
		}


	}
	else
	{
		leap = false;			//不能被4整除，一定不是闰年，为假
	}

	if (leap)					//为真 输出是闰年
	{
		cout << year << " is ";
	}
	else
	{
		cout << year << " is not ";
	}
	cout << "a leap year." << endl;
	return 0;
}