/*��ʽ����/4��1-1/3+1/5-1/7+... ֱ�����һ��ľ���ֵС��10��-7�η�Ϊֹ*/
#include<iostream>
#include<iomanip>//���Ƹ�ʽͷ�ļ�
#include<cmath>//c++��Ҫ��c����ѧ��������������ʱ��Ӧ��ͷ�ļ� ��������Ϊcmath����ʽ
using namespace std;
int mian()
{
	int s = 1;//s ����
	double n = 1, t = 1, pi = 0;// n��ĸ t���� piΪ��
	while ((fabs(t)) > 1e-7)//fabs ����ֵ
	{
		pi = pi + t;
		n = n + 2;
		s = -s;
		t = s / n;
	}
	pi = pi * 4;
	cout << "pi= " << setiosflags(ios::fixed) << setprecision(6) << pi << endl;//���ø������Թ̶�С��λ����ʾ������Ϊ6
	return 0;
}