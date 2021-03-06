/***************************************************************************************************************
* 1. Two Sum
* 
*  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
*  You may assume that each input would have exactly one solution, and you may not use the same element twice.
* 
* Example:
* Given nums = [2, 7, 11, 15], target = 9,
* 
* Because nums[0] + nums[1] = 2 + 7 = 9,
* return[0, 1].
*****************************************************************************************************************
*
* Author:
* Jing Qi
*
* Date: 
* 5/22/2018
*/


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		// 这个问题的核心是“如何快速地通过一个数组中存在的值反推其index”
		// 因此这里使用unordered_map来做到这一点
		// http://www.cplusplus.com/reference/unordered_map/unordered_map/
		unordered_map<int, int> hash;
		vector<int> result;
		for (int i = 0; i < numbers.size(); i++) {
			int numberToFind = target - numbers[i];
			if (hash.find(numberToFind) != hash.end()) { // Complexity: constant
														 //http://www.cplusplus.com/reference/unordered_map/unordered_map/find/
				result.push_back(hash[numberToFind]);
				result.push_back(i);
				return result;
			}
			hash[numbers[i]] = i; // “反向”存储，便于之后的查找
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<int> i = { 2, 7, 11, 15 };
	vector<int> r = s.twoSum(i, 9);
	cout << r[0] << " " << r[1] << endl;
	return 0;
}