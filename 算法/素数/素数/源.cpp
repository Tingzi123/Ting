/*�ҳ�100-200���ȫ������
�㷨��
��m��  2 �� ������m  �������m���ܱ�����������������������Ϊ����*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int m, i, k, n = 0;
	bool prime;
	for (m = 101; m <= 200; m=m+2)//�޶���Χ������Ϊ2����Ϊż��һ����������
	{
		prime = true;//����Ϊ�棬��Ϊ����
		k = int(sqrt(m));//k����sqrt(m)����������
		for (i = 2; i <= k; i++)//���m��2��sqrt(m)��Χ�ڣ��ܷ�����
			if (m%i == 0)
			{
				prime = false;//�������������������
				break;
			}
			if (prime)//���Ϊ����
			{
				cout << setw(5) << m;//���m,�ֶο��5
				n = n + 1;//�ۼƸ���
			}
			if (n % 10 == 0) cout << endl;//���10���� ����		
	}
	cout << endl;//���һ��ִ�л���
	return 0;
}

