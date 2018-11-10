#pragma once
#ifndef __SORT_STACK_H_
#define __SORT_STACK_H_

#include <stack>


template <typename T>
void sortStack(std::stack<T>& st)
{
	std::stack<T> temp;

	while (!st.empty())
	{
		T val = st.top();
		st.pop();

		while (!temp.empty()
			&& temp.top() > val)
		{
			st.push(temp.top());
			temp.pop();
		}

		temp.push(val);
	}

	while (!temp.empty()) {
		st.push(temp.top());
		temp.pop();
	}
}



#endif //__SORT_STACK_H_
