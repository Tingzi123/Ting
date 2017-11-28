#include<iostream>
#include"student.h"
using namespace std;

void student::setData()
{
	cout << "Please input num,name and sex:";
	cin >> num;
	cin >> name;
	cin >> sex;
}

void student::display()

{

	cout << "num:" << num<<endl;

	cout << "name:" << name<<endl;

	cout << "sex:" << sex<<endl;

}
