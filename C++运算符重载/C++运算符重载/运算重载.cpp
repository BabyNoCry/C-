#include<iostream>
#include<windows.h>
using namespace std;
class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		int monthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && (year / 400 == 0 || (year / 100 != 0 && year / 4 == 0)))
			return 29;
		else
			return monthArray[month];
	}

	// 四个成员函数
	//构造函数
	Date(int year = 2019, int month = 1, int day = 1)
	{
		if (year > 0 &&
			month > 0 && month < 13 &&
			day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期非法" << endl;
		}

	}
	//析构函数
	~Date()
	{}
	//拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//赋值运算符的重载
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}


	bool operator==(const Date& d)
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
			return true;
		return false;
	}
	bool operator!=(const Date& d)
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
			return false;
		return true;
	}
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
				return false;
		}
		else
			return false;
	}


	bool operator<(const Date& d)
	{
		if (_year > d._year)
		{
			return false;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
			{
				return false;
			}
			else if (_month == d._month)
			{
				if (_day > d._day)
				{
					return false;
				}
				else
				{
					true;
				}
			}
			else
				return true;
		}
		else
			return true;
	}

	bool operator>=(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
				else if (_day = d._day)
				{
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}


	bool operator<=(const Date& d)
	{
		if (_year > d._year)
		{
			return false;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
			{
				return false;
			}
			else if (_month == d._month)
			{
				if (_day > d._day)
				{
					return false;
				}
				else if (_day == d._day)
				{
					return true;
				}
				else
				{
					true;
				}
			}
			else
				return true;
		}
		else
			return true;
	}

	//d1 + 10
	Date operator+(int day)
	{
		Date cur(*this);
		int add = 0;
		cur._day += day;
		if (cur._day > GetMonthDay(_year, _month))
		{
			add = 1;
			cur._day -= GetMonthDay(_year, _month);
		}
		cur._month += add;
		add = 0;
		if (cur._month > 12)
		{
			add = 1;
			cur._month =cur._month - 12;
		}
		cur._year += add;
		return cur;
	
	}
	Date operator+=(int day)
	{
		int add = 0;
		_day += day;
		if (_day > GetMonthDay(_year, _month))
		{
			add = 1;
			_day -= GetMonthDay(_year, _month);
		}
		_month += add;
		add = 0;
		if (_month > 12)
		{
			add = 1;
			_month = _month - 12;
		}
		_year += add;
		return *this;
	}

	Date operator-(int day)
	{
		Date cur(*this);
		int add = 0;
		cur._day -= day;
		if (cur._day <= 0)
		{
			add = -1;
			if (cur._month > 1)
			{
				cur._month += add;
				cur._day += GetMonthDay(_year, _month - 1);
			}
			else
			{
				cur._year -= 1;
				cur._month = 12;
				cur._day += GetMonthDay(_year, _month);

			}
			return cur;

		}
		return cur;
	}

	Date operator-=(int day)
	{
		
		int add = 0;
		_day -= day;
		if (_day <= 0)
		{
			add = -1;
			if (_month > 1)
			{
				_month += add;
				_day += GetMonthDay(_year, _month - 1);
			}
			else
			{
				_year -= 1;
				_month = 12;
				_day += GetMonthDay(_year, _month);

			}
			return *this;

		}
		return *this;
	}
	
	////前置
	Date operator++()
	{
		(*this) +=1;
		return (*this) + 1;
	}
	Date operator--()
	{
		return (*this) - 1;
	}

	//// 后置
	Date operator++(int)
	{
		Date cur(*this);
		(*this) += 1;
		return cur;
	}
	Date operator--(int)
	{
		Date cur(*this);
		(*this) -= 1;
		return cur;
	}

	// d1-d2
	int operator-(const Date& d)
	{
		int count=0;
		Date cur(*this);
		Date d1(d);
		if (cur == d)
		{
			return 0;
		}
		else if (cur > d1)
		{
			while (cur != d1)
			{
				int add = 0;
				d1._day += 1;
				if (d1._day > GetMonthDay(d1._year, d1._month))
				{
					add = 1;
					d1._day -= GetMonthDay(d1._year, d1._month);
				}
				d1._month += add;
				add = 0;
				if (d1._month > 12)
				{
					add = 1;
					d1._month = d1._month - 12;
				}
				d1._year += add;
				count++;
			}
			
		}
		else
		{
			while (cur != d1)
			{
				int add = 0;
				cur._day += 1;
				if (cur._day > GetMonthDay(cur._year, cur._month))
				{
					add = 1;
					cur._day -= GetMonthDay(cur._year, cur._month);
				}
				cur._month += add;
				add = 0;
				if (cur._month > 12)
				{
					add = 1;
					cur._month = cur._month - 12;
				}
				cur._year += add;
				count++;
			}
		}
		return count;
	}
	//int operator-(const Date& d)
	//{
	//	int count_d = 0;
	//	Date d1(d);
	//	Date cur(*this);
	//	while (d1._day>=0&& d1._month>=0&&d1._year>=0)
	//	{
	//		int add = 0;
	//		d1._day -= 1;
	//		if (d1._day <= 0)
	//		{
	//			add = -1;
	//			if (d1._month > 1)
	//			{
	//				d1._month += add;
	//			d1._day += GetMonthDay(d1._year, d1._month - 1);
	//			}
	//			else
	//			{
	//				d1._year -= 1;
	//				d1._month = 12;
	//				d1._day += GetMonthDay(d1._year, d1._month);

	//			}

	//		}
	//		count_d++;

	//	}
	//	cout << "count_d：" << count_d << endl;
	//	int count_cur = 0;
	//	while (cur._day >=0&& cur._month>=0 && cur._year>=0)
	//	{
	//		int add = 0;
	//		cur._day -= 1;
	//		if (cur._day <= 0)
	//		{
	//			add = -1;
	//			if (cur._month > 1)
	//			{
	//				cur._month += add;
	//				cur._day += GetMonthDay(cur._year, cur._month - 1);
	//			}
	//			else
	//			{
	//				cur._year -= 1;
	//				cur._month = 12;
	//				cur._day += GetMonthDay(cur._year, cur._month);

	//			}

	//		}
	//		count_cur++;
	//		
	//	}
	//	cout << "count_cur：" << count_d << endl;
	//	return  count_cur - count_d;

	//}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 1, 4);
	d1.Print();
	d1 -= 3;
	d1.Print();



	d1.Print();
	d1 += 5;
	d1.Print();
	Date d2(2019, 1, 4);
	if (d2 >= d1)
	{
		cout << "大于等于" << endl;
	}
	else
		cout << "小于" << endl;

	//Date d2(d1);
	//d2.Print();
	//d2 = d2 - 1;
	//d2.Print();
	//d2 = d2 +3;
	//d2.Print();
	Date d3(2017,1, 1);
	
	Date d4(2018,12, 31);//275
	//int j = d4.GetMonthDay(1,2);
	for (int j = 1; j < 13; j++)
	{
		int i= d4.GetMonthDay(2018, j);
		cout << i << endl;
	}
	
	int i = d3 - d4;
	cout << i << endl;

	system("pause");
	return 0;
}
