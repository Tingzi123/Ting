#include<iostream>
#include<fstream>
using namespace std;

//计算应收多少钱和算出应找零钱总数的类 
class Charge{
 public:
 	void set();				//计算买了多少钱的东西 
 	int count();			//计算应该找零的总数 
 private:
 	int n;
 	int a[20];
 	int sum;
 	int pay;
 	int left;
};
 
//计算买了多少钱的东西 
void Charge::set()
{
	ofstream outfile("outfile.txt",ios::out|ios::app);				//打开一个文件 
	if(!outfile)
	{
		cerr<<"opean error!"<<endl;
		exit(1);
	}
	cout<<"购买商品件数：";
	outfile<<"购买商品件数：";
	cin>>n;
	outfile<<n<<endl;
	cout<<"各商品单价：";
	outfile<<"各商品单价：";
	sum=0;
	for(int i=0;i<n;i++)
	 { cin>>a[i];
	   outfile<<a[i]<<"	";
	   sum=sum+a[i];
	 }
	 outfile<<endl;
	cout<<"应付："<<sum<<endl; 
	outfile<<"应付："<<sum<<endl;
}
//计算应该找零的总数 
int Charge::count()
{
	cout<<"实付：";
	ofstream outfile("outfile.txt",ios::out|ios::app);
	outfile<<"实付：";
	cin>>pay;
	outfile<<pay<<endl;
	left=pay-sum;
	cout<<"应找零："<<left<<endl;
	outfile<<"应找零："<<left<<endl;
	return left; 
}
void menu() //选择操作选项
{
		cout<<endl<<endl<<endl<<endl;
        cout<<"==================★☆★☆★☆★☆★☆★☆★=================="<<endl;
        cout<<"*******************欢迎进入购物零钱找兑系统*******************"<<endl;
        cout<<"**********                请选择操作                **********"<<endl;
        cout<<"**********           计算应付总额   请按1           **********"<<endl;
        cout<<"**********           计算找零总额   请按2           **********"<<endl;
        cout<<"**********           计算具体找零   请按3           **********"<<endl;
        cout<<"**********           退出收费系统   请按4           **********"<<endl;
        cout<<"==================★☆★☆★☆★☆★☆★☆★=================="<<endl;
}

//计算一次找完一种面值的硬币后还应该找多少钱 
void compute_coins(int coin_value, int & number, int & amount_left)
{
	number=amount_left/coin_value;
	amount_left=amount_left-(coin_value*number);
}
//利用循环计算应该找各个面值的硬币多少个和找完后所剩下的钱数 
void result(int & amount_left)
{
	void compute_coins(int coin_value, int & number, int & amount_left); 
	if(amount_left<0||amount_left>=100)
	{
		cout<<"error"<<endl;
		exit(0);
	}	
	cout<<amount_left<<" cent(s) can be given as："<<endl;
	ofstream outfile("outfile.txt",ios::out|ios::app);
	outfile<<amount_left<<" cent(s) can be given as："<<endl;
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
		cout<<"要继续付款吗（继续请输入Y或y，不继续请输入N或n）";
		cin>>ch1; 	
	}while(ch1=='Y'||ch1=='y');			//实行多次付款和找零 
	return 0;
}

