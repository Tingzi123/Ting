/*�ж��Ƿ�Ϊ���꣬�㷨��
1.�ܱ�4�����������ܱ�һ������
���� 2.�ܱ�100���������ܱ�400��������2100�� �������꣩
��Ϊ����
���ʽ����year %4 == 0 && year %100 != 0 || year %400 == 0) ����ֱ��д������ʽ ����������˺ܴ��ķ���   */
#include<iostream>
using namespace std;
int main()
{
	int year;
	bool leap;
	cout << "Input a year:";
	cin >> year;
	if (year % 4 == 0)             //year�ܱ�4����
	{
		if (year % 100 == 0)       //year�ܱ�4��100����
		{


			if (year % 400 == 0)   //year�ܱ�4,100��400����
			{
				leap = true;       //���� Ϊ��
			}
			else
			{
				leap = false;     //����Ϊ��
			}

			        
		 }
		else
		{
			leap = true;         //year��4����,�����ܱ�100������һ�������� Ϊ��
		}


	}
	else
	{
		leap = false;			//���ܱ�4������һ���������꣬Ϊ��
	}

	if (leap)					//Ϊ�� ���������
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