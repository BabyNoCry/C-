//ɾ�����������е��ظ���
//�������� nums = [1, 1, 2],
//
//����Ӧ�÷����µĳ��� 2, ����ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2��
//
//�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//ʾ�� 2:
//���� nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
//
//����Ӧ�÷����µĳ��� 5, ����ԭ���� nums ��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4��
//
//�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] == nums[j])
				{
					nums.erase(nums.begin() + j);
					--j;
				}
			}
		}
		return nums.size();
	}
};

//ֻ����һ�ε����� II
//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//˵����
//����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����
class Solution {
public:
	int singleNumber(vector<int>& nums) {

		for (int i = 0; i < nums.size(); i++)
		{
			int count = 0;
			for (int j = 0; j < nums.size(); j++)
			{
				if (nums[i] == nums[j])
				{
					count++;

				}
			}
			if (count == 1)
				return nums[i];
		}
		return NULL;
	}
};
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{ 1,2,3,2,2,2,5,4,2 }��
//��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {

		for (int i = 0; i < numbers.size(); i++)
		{
			int count = 0;
			for (int j = 0; j < numbers.size(); j++)
			{
				if (numbers[i] == numbers[j])
					count++;
			}
			if (count > numbers.size() / 2)
				return numbers[i];
		}
		return 0;
	}
};
//HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
//��������鿪����, ���ַ�����:�ڹ��ϵ�һάģʽʶ����, ������Ҫ��������������������, ������ȫΪ������ʱ��,
//����ܺý��������, ��������а�������, �Ƿ�Ӧ�ð���ĳ������, �������Աߵ��������ֲ����أ�
//���� : {6, -3, -2, 7, -15, 1, 2, 2}, ����������������Ϊ8(�ӵ�0����ʼ, ����3��Ϊֹ)��
//��һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = array[0], tmpsum = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			tmpsum = (tmpsum < 0) ? array[i] : tmpsum + array[i];
			sum = (sum > tmpsum) ? sum : tmpsum;
		}
		return sum;
	}
};
//�绰�������ĸ���
//����һ������������ 2 - 9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
//
//�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��
//ʾ�� :
//
//���룺"23"
//�����["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.empty()) return res;
		string dict[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		res.push_back("");
		for (int i = 0; i < digits.size(); ++i) {
			int n = res.size();
			string str = dict[digits[i] - '2'];
			for (int j = 0; j < n; ++j) {
				string tmp = res.front();
				res.erase(res.begin());
				for (int k = 0; k < str.size(); ++k) {
					res.push_back(tmp + str[k]);
				}
			}
		}
		return res;
	}
};
//�������
//����һ���Ǹ����� numRows������������ǵ�ǰ numRows ��
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>v;
		v.resize(numRows);
		for (int i = 0; i < v.size(); i++)
		{
			v[i].push_back(1);
			v[i].resize(i + 1);
			v[i][i] = 1;
			for (int j = 0; j < i + 1; j++)
			{
				if (v[i][j] == 0)
				{
					v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
				}
			}
		}

		return v;
	}
};