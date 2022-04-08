#include<iostream>
#include<windows.h> //延时与清屏头文件 
using namespace std;
class time
{
	public:
		//默认构造函数 
		time(){year=0;month=0;day=0;hour=0;minute=0;sec=0;}
		//构造函数重载 
		time(int y,int mo,int d,int h ,int m,int s)
			:year(y)
			,month(mo)
			,day(d)
			,hour(h)
			,minute(m)
			,sec(s)
		{}
		time operator++();//声明运算符重载成员函数 
		void display()
			{
				cout<<"*********"<<year<<"-"<<month<<"-"<<day<<"**********"<<endl;
				cout<<"********"<<hour<<" : "<<minute<<" : "<<sec<<"********"<<endl;
			}//输出时间格式 
	private:
		int year;
		int month;
		int day;
		int hour;
		int minute;
		int sec;	
};
time time::operator++()//定义运算符重载成员函数 
{
	if(++sec>=60)
	{
		sec-=60;
		++minute;
		if(minute>=60)
		{
			minute-=60;
			++hour;
			if(hour>=24)
        		{
        			hour-=24;
        			++day;
        			if(day>=30)
        			{
        				day-=30;
        				++month;
        				if(month>=12)
        				{
        					month-=12;
        					++year;
						}
					}
				}
		}
	}
	return *this;//返回当前对象值 
}
int main()
{
	int a,b,c,e,f,g,h;
	cout<<"请修改当前时间：（格式如下）\n";
	cout<<"2018 10 3 12 50 45\n";
	{
	cout<<"请输入当前年份(2018):"<<endl;
	cin>>g;
	cout<<"请输入当前月份(1~12):"<<endl; 
	cin>>e;
	cout<<"请输入当前几号(1~30):"<<endl;
	cin>>h;
	cout<<"请输入现在时间(12 30 32):"<<endl;
	cin>>a>>b>>c;
	}
	
	{
		time time1(g,e,h,a,b,c);//如何向time1中输入数据 
		for(int i=0;;i++)
		{	cout<<"*****欢迎进入家庭计时系统*****"<<endl;
			cout<<"*******假设每个月30天*******"<<endl; 
			++time1;
			time1.display() ;
			cout<<"***********designed by yuumoz.\n";
			Sleep(1000);
	     	system("CLS");
		}
	}
	return 0;
 } 

