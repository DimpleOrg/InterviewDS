#pragma once
#include<iostream>
#include<array>

template<typename E>
class Stacks
{
	int sz;
	std::unique_ptr<E[]> arr;
	void moveElementsToLeft(int, int);
	void moveElementsToRight(int, int);
	int s1top, s2top, s3top;

public:
	Stacks(): sz(6), s1top(-1), s2top(-1), s3top(-1)
	{
		arr = std::make_unique<E[]>(sz);
	}

	Stacks(int n) : sz(n), s1top(-1), s2top(-1), s3top(-1) 
	{
		arr = std::make_unique<E[]>(sz);
	}

	void s1Push(E elem);
	void s2Push(E elem);
	void s3Push(E elem);

	/*void s1Peek();
	void s2Peek();
	void s3Peek();*/
	
	void s1Pop();
	void s2Pop();
	void s3Pop();

	void print();
};


template<typename E>
inline void Stacks<E>::s1Push(E elem)
{
	if (s1top >= sz - 1 || s2top >= sz - 1 || s3top >= sz - 1)
		std::cout << "\nArray is Full\n";

	else
	{
		if (s3top < 0 && s2top >= 0)
		{
			moveElementsToRight(s1top + 1, s2top);
			++s2top;
		}
		
		if (s2top < 0 && s3top >= 0)
		{
			moveElementsToRight(s1top + 1, s3top);
			++s3top;
		}
		
		if (s2top >= 0 && s3top > 0)
		{
			moveElementsToRight(s2top + 1, s3top);
			++s3top;
			moveElementsToRight(s1top + 1, s2top);
			++s2top;
		}

		++s1top;
		arr.get()[s1top] = elem;
	}
}

template<typename E>
inline void Stacks<E>::s2Push(E elem)
{
	if (s1top >= sz - 1 || s2top >= sz - 1 || s3top >= sz - 1)
		std::cout << "\nArray is Full\n";
	
	else
	{

		if (((s1top < s2top) &&(s2top < s3top)) || (s1top < 0 && s2top < 0 && s3top >= 0))
		{
			moveElementsToRight(s2top + 1, s3top);
			++s3top;
		}

		if (s2top < 0 && s3top < 0 && s1top >= 0)
			s2top = s1top;

		if (s2top < 0 && s2top < s1top < s3top)
		{
			moveElementsToRight(s1top + 1, s3top);
			++s3top;
			s2top = s1top;
		}

		++s2top;
		arr.get()[s2top] = elem;
	}
}

template<typename E>
inline void Stacks<E>::s3Push(E elem)
{
	if (s1top >= sz - 1 || s2top >= sz - 1 || s3top >= sz - 1)
		std::cout << "\nArray is Full\n";

	else
	{
		if (s3top < 0 && s1top < s2top)
			s3top = s2top;

		if (s2top < 0 && s3top < 0 && s1top >= 0)
			s3top = s1top;

		++s3top;
		arr.get()[s3top] = elem;
	}
}

template<typename E>
inline void Stacks<E>::s1Pop()
{
	if (s1top < 0)
		std::cout << "\nArray is empty.\n";

	else
	{
		if (s1top < s2top) 
		{
			if (s2top < s3top)
			{

				moveElementsToLeft(s1top + 1, s2top);
				--s2top;
				moveElementsToLeft(s2top + 1, s3top);
				--s3top;
			}
		}
		if (s3top < 0 && s1top < s2top)
		{
			moveElementsToLeft(s1top + 1, s2top);
			--s2top;
		}

		if (s2top < 0 && s1top < s3top)
		{
			moveElementsToLeft(s1top + 1, s3top);
			--s3top;
		}

		--s1top;
	}
}

template<typename E>
inline void Stacks<E>::s2Pop()
{
	if (s2top < 0)
		std::cout << "\nArray is empty.\n";

	else
	{
		if ((s1top < s2top) && (s2top < s3top))
		{
			moveElementsToLeft(s2top + 1, s3top);
			--s3top;
		}

		--s2top;
	}
}

template<typename E>
inline void Stacks<E>::s3Pop()
{
	if (s3top < 0)
		std::cout << "\nArray is empty.\n";

	else
	{
		--s3top;
	}
}

template<typename E>
inline void Stacks<E>::print()
{
	std::cout << "\n\n**********STACK1*********";
	for (int i = 0; s1top>-1 && i <= s1top; i++)
	{
		std::cout << "\nindex: " << i << "\tval: " << arr.get()[i];
	}

	std::cout << "\n\n**********STACK2*********";
	for (int i = s1top+1; s2top>-1 && i <= s2top; i++)
	{
		std::cout << "\nindex: " << i << "\tval: " << arr.get()[i];
	}

	std::cout << "\n\n**********STACK3*********";
	if (s2top > s1top)
	{
		for (int i = s2top + 1; s3top > -1 && i <= s3top; i++)
		{
			std::cout << "\nindex: " << i << "\tval: " << arr.get()[i];
		}
	}
	if (s2top < s1top)
	{
		for (int i = s1top + 1; s3top > -1 && i <= s3top; i++)
		{
			std::cout << "\nindex: " << i << "\tval: " << arr.get()[i];
		}
	}



	/*std::cout << "\nStack 1 Top\t" << s1top;
	std::cout << "\nStack 2 Top\t" << s2top;
	std::cout << "\nStack 3 Top\t" << s3top;

	for (int i = 0; i < sz; i++)
	{
		std::cout << "\nindex: " << i << "\tval: " << arr.get()[i];
	}*/
}

template<typename E>
inline void Stacks<E>::moveElementsToLeft(int pos1, int pos2)
{
	int len = pos2 - pos1 + 1;
	for (auto i = 0; i < len; i++)
	{
		arr.get()[pos1 - 1] = arr.get()[pos1];
		++pos1;
	}
}

template<typename E>
inline void Stacks<E>:: moveElementsToRight(int pos1, int pos2)
{
	int len = pos2 - pos1 + 1;
	for (auto i = 0; i < len; i++)
	{
		arr.get()[pos2 + 1] = arr.get()[pos2];
		--pos2;
	}
}