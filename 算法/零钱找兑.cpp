#include<iostream>
#include<fstream>
using namespace std;

//����Ӧ�ն���Ǯ�����Ӧ����Ǯ�������� 
class Charge{
 public:
 	void set();				//�������˶���Ǯ�Ķ��� 
 	int count();			//����Ӧ����������� 
 private:
 	int n;
 	int a[20];
 	int sum;
 	int pay;
 	int left;
};
 
//�������˶���Ǯ�Ķ��� 
void Charge::set()
{
	ofstream outfile("outfile.txt",ios::out|ios::app);				//��һ���ļ� 
	if(!outfile)
	{
		cerr<<"opean error!"<<endl;
		exit(1);
	}
	cout<<"������Ʒ������";
	outfile<<"������Ʒ������";
	cin>>n;
	outfile<<n<<endl;
	cout<<"����Ʒ���ۣ�";
	outfile<<"����Ʒ���ۣ�";
	sum=0;
	for(int i=0;i<n;i++)
	 { cin>>a[i];
	   outfile<<a[i]<<"	";
	   sum=sum+a[i];
	 }
	 outfile<<endl;
	cout<<"Ӧ����"<<sum<<endl; 
	outfile<<"Ӧ����"<<sum<<endl;
}
//����Ӧ����������� 
int Charge::count()
{
	cout<<"ʵ����";
	ofstream outfile("outfile.txt",ios::out|ios::app);
	outfile<<"ʵ����";
	cin>>pay;
	outfile<<pay<<endl;
	left=pay-sum;
	cout<<"Ӧ���㣺"<<left<<endl;
	outfile<<"Ӧ���㣺"<<left<<endl;
	return left; 
}
void menu() //ѡ�����ѡ��
{
		cout<<endl<<endl<<endl<<endl;
        cout<<"==================��������������=================="<<endl;
        cout<<"*******************��ӭ���빺����Ǯ�Ҷ�ϵͳ*******************"<<endl;
        cout<<"**********                ��ѡ�����                **********"<<endl;
        cout<<"**********           ����Ӧ���ܶ�   �밴1           **********"<<endl;
        cout<<"**********           ���������ܶ�   �밴2           **********"<<endl;
        cout<<"**********           �����������   �밴3           **********"<<endl;
        cout<<"**********           �˳��շ�ϵͳ   �밴4           **********"<<endl;
        cout<<"==================��������������=================="<<endl;
}

//����һ������һ����ֵ��Ӳ�Һ�Ӧ���Ҷ���Ǯ 
void compute_coins(int coin_value, int & number, int & amount_left)
{
	number=amount_left/coin_value;
	amount_left=amount_left-(coin_value*number);
}
//����ѭ������Ӧ���Ҹ�����ֵ��Ӳ�Ҷ��ٸ����������ʣ�µ�Ǯ�� 
void result(int & amount_left)
{
	void compute_coins(int coin_value, int & number, int & amount_left); 
	if(amount_left<0||amount_left>=100)
	{
		cout<<"error"<<endl;
		exit(0);
	}	
	cout<<amount_left<<" cent(s) can be given as��"<<endl;
	ofstream outfile("outfile.txt",ios::out|ios::app);
	outfile<<amount_left<<" cent(s) can be given as��"<<endl;
	while(amount_left>0)
	  {
	  	if(amount_left>=25&&amount_left<100)
	  	{
	  		int quarter;
	  		compute_coins(25,quarter,amount_left);
	  		cout<<quarter<<" quarter(s)   ";
	  		outfile<<quarter<<" quarter(s)   ";
		  }
	  	if(amount_left>=10&&amount_left<25)
	  	{
	  		int dime;
	  		compute_coins(10,dime,amount_left);	
	  		cout<<dime<<" dime(s)   ";
	  		outfile<<dime<<" dime(s)   ";
		  }
	  	if(amount_left>=5&&amount_left<10)
	  	{
	  		int nickel;
	  		compute_coins(5,nickel,amount_left);
			cout<<nickel<<" nickel(s)   " ;
			outfile<<nickel<<" nickel(s)   " ;
		  }
	  	if(amount_left>=1&&amount_left<5)
	  	{
	  		int penny;
	  		compute_coins(1,penny,amount_left);
	  		cout<<penny<<" penny(pennies)   "<<endl;
	  		outfile<<penny<<" penny(pennies)   "<<endl;
	  		outfile<<endl;
		  }
	  }
	  cout<<endl<<endl<<"****************************************************"<<endl<<endl;
	  outfile<<endl<<endl<<"****************************************************"<<endl<<endl;
	  outfile.close();
}


int main()
{	
	void menu();
	void result(int & amount_left);
	char ch1;
	Charge c1;
	int l1;
	int a;
	do{												
		do{
			menu();
			cin>>a;
			if(a==1)
				c1.set();
			if(a==2)
				l1=c1.count();
			if(a==3)
				result(l1);
			if(a==4)
		    exit(0);
			a=5;	
		}while(a<4);
		cout<<"Ҫ���������𣨼���������Y��y��������������N��n��";
		cin>>ch1; 	
	}while(ch1=='Y'||ch1=='y');			//ʵ�ж�θ�������� 
	return 0;
}

