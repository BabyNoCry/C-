//����һ�����ڼ�����һ������һ��ĵڼ���
#include<iostream>
using namespace std;
int main()
{
	int monthdays[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
	int year, day, month;
	while (cin >> year >> month >> day)//Ӧע����ǲ���������֪һ������Ӧ����ѭ����ʵ�ֶ������
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

//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
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
		//��ֹ��β��ԣ��������³�ʼ��
		_i = 1;
		_sum = 0;
		sum* p = new sum[n];//Ӧע����ǲ���������Ķ��壬���������Ķ�ε���Ӧ��ʼ��
		delete[]p;
		return _sum;
	}
private:
	static int _i;
	static int _sum;
};
int Solution::_i = 1;
int Solution::_sum = 0;