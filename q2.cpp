/***************************************************************************************************************
* 2. Add Two Numbers
*
*  You are given two non-empty linked lists representing two non-negative integers. The digits 
*  are stored in reverse order and each of their nodes contain a single digit. Add the two numbers 
*  and return it as a linked list.
*  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*
* Example:
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
* Explanation: 342 + 465 = 807.
*
*****************************************************************************************************************
*
* Author:
* Jing Qi
*
* Date:
* 5/24/2018
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode head(0);
		ListNode *p = &head;
		int val1 = 0, val2 = 0, carry = 0, digit = 0;
		while (l1 || l2 || carry)
		{
			val1 = l1 ? l1->val : 0;		// 拷贝出数
			val2 = l2 ? l2->val : 0;
			l1 = l1 ? l1->next : nullptr;	// 移动指针
			l2 = l2 ? l2->next : nullptr;
			digit = (val1 + val2 + carry) % 10;	// 获得结果
			carry = (val1 + val2 + carry) / 10; // 获得进位数
			p->next = (new ListNode(digit));
			p = p->next;
		}
		return head.next;
	}
};
int main()
{
	ListNode *ln1 = new ListNode(2);
	ListNode *ln2 = new ListNode(4);
	ListNode *ln3 = new ListNode(3);
	ln1->next = ln2; ln2->next = ln3;
	ListNode *ln4 = new ListNode(5);
	ListNode *ln5 = new ListNode(6);
	ListNode *ln6 = new ListNode(4);
	ln4->next = ln5; ln5->next = ln6;

	ListNode *lnr;
	Solution s;
	lnr = s.addTwoNumbers(ln1, ln4);

    return 0;
}

