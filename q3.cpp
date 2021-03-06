/***************************************************************************************************************
* 3. Longest Substring Without Repeating Characters
*
*  Given a string, find the length of the longest substring without repeating characters.
* 
* Examples:
* Given "abcabcbb", the answer is "abc", which the length is 3.
* Given "bbbbb", the answer is "b", with the length of 1.
* Given "pwwkew", the answer is "wke", with the length of 3. 
* Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*
*****************************************************************************************************************
*
* Author:
* Jing Qi
*
* Date:
* 5/24/2018
*/
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int result = 0;
		int i = 0, j = 0;
		int length = s.size();
		int charArray[256];
		for (int p = 0; p < 256; p++) 
			charArray[p] = -1;
		while (j < length) {
			if (charArray[s[i]] != -1)	// 如果出现过
				i = (i > charArray[s[j]] + 1) ? i : charArray[s[j]] + 1;// 左边缘移动到“曾出现位置”的下一个
			charArray[s[j]] = j;
			result = (result > j - i + 1) ? result : j - i + 1;
			j++;
		}
		return result;
	}
};

int main()
{
	string input = "pwwkew";
	Solution s;
	int result = s.lengthOfLongestSubstring(input);
	cout << result << endl;
    return 0;
}

