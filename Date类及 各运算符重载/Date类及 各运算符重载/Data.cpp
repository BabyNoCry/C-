#include<iostream>
#include<windows.h>
using namespace std;
class Date
{
public:
	int Getmonthday(int year, int month)
	{
		static int monthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && (year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
			return 29;
		return monthday[month];
	}
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//重载赋值
	Date& operator=(Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return (*this);
	}
	bool operator==(const Date& d)
	{
		return _year == d._year&&_month == d._month&&_day == d._day;
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	//+=
	Date& operator+=(int day)
	{
		if (day > 0)
		{
			_day += day;
			while (_day > Getmonthday(_year, _month))
			{
				if (_month == 12)
				{
					_day -= Getmonthday(_year, _month);
					_year++;
					_month = 1;
				}
				else
				{
					_day -= Getmonthday(_year, _month);
					_month++;
				}
			}
			return *this;
		}
		else
		{
			(*this) -= day;
		}
		return *this;

	}
	Date& operator-=(int day)
	{
		if (day > 0)
		{
			_day -= day;
			while (_day < 1)
			{
				if (_month == 1)
				{
					_year--;
					_month = 12;
					_day += Getmonthday(_year, _month);

				}
				else
				{
					_month--;
					_day += Getmonthday(_year, _month);
				}

			}
			return *this;
		}
		else
			(*this) += (-day);
		return *this;
	}
	Date operator-(int day)
	{
		Date ret(*this); 
			ret -= day;
			return ret;
	}
	Date operator+(int day)
	{
		Date ret(*this);
		ret += day;
		return ret;

	}
	//前置++
	Date& operator++()
	{
		(*this) += 1;
		return *this;
	}
	//后置++
	Date& operator++(int)
	{
		Date ret = (*this);
		(*this) += 1;
		return ret;
	}

	//前置--
	Date& operator--()
	{
		(*this) -= 1;
		return *this;
	}
	//后置——
	Date& operator--(int)
	{
		Date ret = (*this);
		(*this) -= 1;
		return ret;
	}

	//>=
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year&&_month > d._month)
		{
			return true;
		}
		else if (_year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}
		else
			return false;
	}
	bool operator>=(const Date& d)
	{
		return ((*this) > d) || ((*this) == d);
	}
	bool operator<=(const Date& d)
	{
		return !((*this) > d) || ((*this) == d);
	}
	bool operator<(const Date& d)
	{
		return !((*this) > d || (*this) == d);
	}
	//两个日期相减
	int operator-(Date& d)
	{
		int day = 0;
		int flag = 1;
		if ((*this) < d)
		{
			while ((*this) != d)
			{
				++(*this);
				day++;
			}
			flag = -1;
		}
		while ((*this) != d)
		{
			++d;
			day++;
		}
		return day * flag;
	}
	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;

};
void Test1()
{
	Date d1(2019, 1, 15);
	d1.print();
	Date d2(d1);
	d2.print();
	int i = d1 - d2;
	cout <<"i="<< i << endl;
	d1 -= 16;
	d1.print();
	d2 += 17;
	d2.print();
	d1++;
	d1.print();

	d1--;
	d1.print();

	++d1;
	d1.print();

	--d1;
	d1.print();

}
int main()
{
	//Test1();
	Date d1(2019, 1, 1);
	Date d2(2019, 12, 31);
	cout << (d1 - d2) << endl;

	system("pause");
	return 0;
}