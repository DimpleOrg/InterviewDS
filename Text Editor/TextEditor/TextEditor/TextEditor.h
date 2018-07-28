#pragma once
#ifndef __TEST_EDITOR_H_
#define __TEST_EDITOR_H_

#include<iostream>

#include<vector>
#include<list>
#include<iterator>

using namespace std;
using Line = vector<char>;

class Document
{
public:

	list<Line> line;

	Document() { line.push_back(Line{}); }

};





class TextEditor
{
public:
	list<Line> line;

	TextEditor() { line.push_back(Line{}); }
};

ostream& operator<<(ostream& os, TextEditor& td)
{
	try
	{
		list<Line>::iterator x = td.line.begin();

		for (; x != td.line.end(); x++)
		{
			vector<char>::iterator iter = (*x).begin();
			for (; iter != (*x).end(); iter++)
			{
				cout << *iter;
			}
			cout << endl;
		}
	}
	catch (...)
	{
		cout << "Operator Overloading exception occured.";
	}

	return os;
}


istream& operator>>(istream& is, TextEditor& td)
{
	try 
	{
		char inputChar;

		is.get(inputChar);

		char prevChar = '\0';

		while (inputChar != EOF)
		{
						
			if (prevChar == '\n' && inputChar == '\n') {
				td.line.push_back(Line{});
				break;
			}
			else if (inputChar == '\n') {
				td.line.push_back(Line{});
			}
			else {
				td.line.back().push_back(inputChar);
			}

			prevChar = inputChar;
			is.get(inputChar);

		}

	}
	catch (...)
	{
		cout << "Operator Overloading exception occured.";
	}

	return is;
}



#endif // __TEST_EDITOR_H_

