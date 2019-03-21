#include "LongestSubstrWithoutRepeatingChars.h"
#include <unordered_set>
using namespace std;
std::size_t LongestSubstrWithoutRepeatingChars(const std::string & str)
{
	unordered_set<char> seqMap;
	size_t curSeqCount = 0;
	size_t maxSeqLen = 0;

	for (const char x : str)
	{		
		if (seqMap.find(x) == seqMap.end())
		{
			curSeqCount++;
			seqMap.insert(x);
		}
		else
		{
			if (curSeqCount > maxSeqLen)
				maxSeqLen = curSeqCount;

			seqMap.clear();
			curSeqCount = 1;
			seqMap.insert(x);

		}
	}

	return (maxSeqLen > curSeqCount) ? maxSeqLen : curSeqCount;
}
