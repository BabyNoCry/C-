//给定一个日期计算这一天是这一年的第几天
#include<iostream>
using namespace std;
int main()
{
	int monthdays[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
	int year, day, month;
	while (cin >> year >> month >> day)//应注意的是测试用例不知一个，故应该用循环来实现多次输入
	{
		if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			cout << monthdays[month - 1] + day + 1 << endl;
		}
		else
			cout << monthdays[month - 1] + day << endl;
	}

	return 0;
}

//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
class Solution {
public:
	class sum
	{
	public:
		sum()
		{
			_sum += _i;
			_i++;
		}
	};
	int Sum_Solution(int n) {
		//防止多次测试，做出以下初始化
		_i = 1;
		_sum = 0;
		sum* p = new sum[n];//应注意的是不定长数组的定义，测试用例的多次调用应初始化
		delete[]p;
		return _sum;
	}
private:
	static int _i;
	static int _sum;
};
int Solution::_i = 1;
int Solution::_sum = 0;