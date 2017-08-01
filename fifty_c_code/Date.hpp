/******************************************************************************************
Date.hpp:
	Copyright (c) Bit Software, Inc.(2013), All rights reserved.

Purpose:
	声明并实现一个日期类

难度：***

Author:
	xxx

Created Time:
	2015-4-26
******************************************************************************************/

class Date
{
public:
	Date (int year = 1900, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		// 检查如果输入参数是非法时间，则初始化为1900-1-1
		if (CheckIsInvaildDate())
		{
			year = 1900;
			month = 1;
			day = 1;
		}
	}

	Date (const Date& d)
		:_year(d._year)
		,_month(d._month)
		,_day(d._day)
	{}

	Date& operator= (const Date& d)
	{
		if (this != &d)
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}

		return *this;
	}

	// 检查时间是否有效
	bool CheckIsInvaildDate ()
	{
		if (_year < 1
			|| (_month < 1 || _month > 12)
			|| (_day < 1   || _day > DateOfMonth(_year, _month)))
		{  
			return true;
		}

		return false;
	}

	void Display ()
	{
		cout<<_year<<"-"<<_month<<"-"<<_day<<endl<<endl;
	}

public:
	// 若日期非法
	static int DateOfMonth (int year, int month)
	{
		if (year < 1 || month < 1 || month > 12)
			return 0;

		static int monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

		// 瑞年的2月是29天
		monthDays[2] += IsLeapYear(year);

		return monthDays[month];
	}

	// 判断是否为瑞年。
	static bool IsLeapYear (int year)
	{
		// 请思考为什么瑞年是这样计算，而不直接是year % 4 == 0就是瑞年？
		if ((year % 4 == 0 && year % 100 != 0)
			|| year % 400 == 0)
		{
			return true;
		}

		return false;
	}
public:
	bool operator == (const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	bool operator > (const Date& d)
	{
		if(_year > d._year)
			return true;

		if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}

			if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
			}
		}

		return false;
	}

	bool operator >= (const Date& d)
	{
		return *this > d || *this == d;
	}

	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}

	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}

	// 将日期转换为正确的日期
	void _ToCrrectDate()
	{
		while(_day <= 0)
		{
			if (_month == 1)
			{
				_year--;
				_month = 12;
			}
			else
			{
				_month--;
			}

			_day += DateOfMonth (_year, _month);
		}

		while (_day > DateOfMonth(_year, _month))
		{
			_day -= DateOfMonth (_year, _month);

			if (_month == 12)
			{
				_year++;
				_month = 1;
			}
			else
			{
				_month++;
			}
		}
	}

	//
	// 计算一个日期加减一个天数以后的日期。
	//

	Date operator+(int day)
	{
		Date d(*this);
		d._day += day;
		d._ToCrrectDate();
		return d;
	}

	Date operator-(int day)
	{
		Date d(*this);
		d._day -= day;
		d._ToCrrectDate();
		return d;
	}

	Date& operator-=(int day)
	{
		this->_day -= day;
		this->_ToCrrectDate();
		return *this;
	}

	Date& operator+=(int day)
	{
		this->_day += day;
		this->_ToCrrectDate();
		return *this;
	}

	 // 前置++
	const Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// 后置++
	Date operator++(int)
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}

	// 前置--
	const Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	 // 后置--
	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	//
	// 两个日期相加没有意义
	// 计算两个日期相减以后的差的天数
	//

	int operator-(const Date& d)
	{
		int flag = 1;
		Date x1 = *this, x2 = d;
		if (x1 < x2)
		{
			flag = -1;
			x1 = d;
			x2 = *this;
		}
		
		int gapDays = 0;
		while (x1 != x2)
		{
			++x2;
			gapDays++;
		}

		return gapDays*flag;
	}

	friend istream& operator>>(istream& in, Date& d);
	friend ostream& operator<<(ostream& out, Date& d);
private:
	int _year;
	int _month;
	int _day;
};

istream& operator>>(istream& in, Date& d)
{
	cout<<"请依次输入日期的年-月-日"<<endl;
	in>>d._year;
	in>>d._month;
	in>>d._day;

	return in;
}

ostream& operator<<(ostream& out, Date& d)
{
	out<<d._year<<"-";
	out<<d._month<<"-";
	out<<d._day;

	return out;
}

void PromptInfo()
{
	cout<<"==============日期计算器================"<<endl;
	cout<<"1.推后几天的日期"<<endl;
	cout<<"2.计算日期差"<<endl;
	cout<<"0.退出"<<endl;
	cout<<"========================================"<<endl;
}

void TestDate ()
{
	Date d1, d2;
	int option, days;
	do {
		PromptInfo();
		cin>>option;

		switch(option)
		{
		case 0:
			break;
		case 1:
			cin>>d1;
			if (d1.CheckIsInvaildDate())
			{
				cout<<"输入日期非法！"<<endl;
				break;
			}
			cout<<"请出入计算推后的天数"<<endl;
			cin>>days;
			d1+=days;
			cout<<d1<<endl;
			break;
		case 2:
			cin>>d1;
			if (d1.CheckIsInvaildDate())
			{
				cout<<"输入日期非法！"<<endl;
				break;
			}
			cin>>d2;
			if (d2.CheckIsInvaildDate())
			{
				cout<<"输入日期非法！"<<endl;
				break;
			}
			days = d1 - d2;
			cout<<"相差的天数:"<<days<<endl;
			break;
		default:
			cout<<"选项错误，请重新选择"<<endl;
			break;
		}
	}while(option != 0);
}