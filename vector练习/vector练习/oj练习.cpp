//删除排序数组中的重复项
//给定数组 nums = [1, 1, 2],
//
//函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
//
//你不需要考虑数组中超出新长度后面的元素。
//示例 2:
//给定 nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
//
//函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
//
//你不需要考虑数组中超出新长度后面的元素。
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

//只出现一次的数字 II
//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
//说明：
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
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
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{ 1,2,3,2,2,2,5,4,2 }。
//由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
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
//HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
//今天测试组开完会后, 他又发话了:在古老的一维模式识别中, 常常需要计算连续子向量的最大和, 当向量全为正数的时候,
//问题很好解决。但是, 如果向量中包含负数, 是否应该包含某个负数, 并期望旁边的正数会弥补它呢？
//例如 : {6, -3, -2, 7, -15, 1, 2, 2}, 连续子向量的最大和为8(从第0个开始, 到第3个为止)。
//给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
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
//电话号码的字母组合
//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//示例 :
//
//输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
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
//杨辉三角
//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行
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