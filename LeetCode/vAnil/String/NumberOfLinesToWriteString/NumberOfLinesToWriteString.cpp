#include "NumberOfLinesToWriteString.h"

NUMBEROFLINESTOWRITESTRING_API std::vector<size_t> numberOfLines(const std::vector<size_t>& widths, const std::string &s, size_t lineLen)
{
	try
	{
		size_t numOfChars = 26; //a--to--z
		if (widths.empty())
		{
			throw std::exception("Width vector is empty.");
		}
		else if (widths.size() != numOfChars)
		{
			throw std::exception("Width vector is not valid.");
		}

		size_t numTotalChars = 0;
		size_t numLines = 0;

		for (auto elem : s) {
			if (elem < 'a' || elem > 'z')
				throw std::exception("Invalid input string.");

			numTotalChars += widths[elem - 'a'];
			
			if (numTotalChars >= lineLen)
			{
				++numLines;
		
				if (numTotalChars > lineLen)
					numTotalChars = widths[elem - 'a'];		
				else
					numTotalChars = 0;
			}
		}

		if (numTotalChars > 0)
			++numLines;
		else if (numTotalChars == 0)
			numTotalChars = lineLen;


		return std::move(std::vector<size_t>{ numLines, numTotalChars });

	}
	catch (std::exception& e)
	{
		std::cout << "Exception occured:" << e.what() << std::endl;
		throw;
	}
}
