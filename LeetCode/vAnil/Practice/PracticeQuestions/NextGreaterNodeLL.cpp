#include "NextGreaterNodeLL.h"
#include <stack>
using namespace std;

std::vector<int> nextLargerNodes(ListNode * head)
{
	vector<int> result;

	if (!head)
		return result;

	stack<int> st;

	while (head)
	{
		result.push_back(head->val);
		head = head->next;
	}

	for (auto riter = result.rbegin(); riter != result.rend(); riter++)
	{
		while (!st.empty() && *riter >= st.top())
		{
			st.pop();
		}

		if (st.empty())
		{
			st.push(*riter);
			*riter = 0;
		}
		else
		{
			int val = *riter;
			*riter = st.top();
			st.push(val);
		}
	}

	return result;
}
