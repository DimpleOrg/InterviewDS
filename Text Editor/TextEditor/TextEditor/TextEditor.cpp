
#include"TextEditor.h"

istream& operator>>(istream& is, Document& d)
{
	char ch;
	is.get(ch);
	while (ch != '\n')
	{
		is.get(ch);
		d.line.back().push_back(ch);
		if (ch == '\n')
		{
			//using Line = vector<char>;
			//d::Line
			d.line.push_back(Line{});
		}
	}
	return is;
}

int main(int argc, char*argv[])
{
	TextEditor td;

	cin >> td;

	cout << "Testing" << endl;

	cout << td;

}