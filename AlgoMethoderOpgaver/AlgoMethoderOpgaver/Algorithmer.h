#ifndef ALGORITHMER_H
#define ALGORITHMER_H
#include <vector>
#include <string>
#include <algorithm>

class Algorithmer
{
public:
	Algorithmer();

	// Algorithm takes an array of unsorted, unique natural numbers as input and finds the three numbers in the array whose sum is closest to a power of 2. The same number can only be used once.
	std::vector<int> sumPower2(std::vector<int> array);//Or use array[] if u want
	// Algorithm can decide if a given natural number Z < 100,000 (the parameter of the algorithm) can be written as  Z=X^Y where X and Y are integers with X > 2 and Y > 2.
	std::vector<int> xPowY(int Z);
	// Algorithm, which called with the array ( and possibly the length of the array), can decide if any candidate got more than 50 % of the votes. In that case the number of the candidate is returned. 
	// If no candidate got more than 50 % of the vote -1 is returned.
	int majorityVote(std::vector<int> array/*, int size*/); //Or you can use array[]
	// Algorithm takes a string as input and returns the most frequently occurring word contained in the string. The string is plain text (small and capital letters), and words are separated with blanks, 
	// commas and full stops and combinations of these. Words are considered the same, even if some occurrences begin with a small letter and others with a capital letter.
	// You may assume as a precondition for your algorithm that the input parameter can only contain small letters [a-z] capital letters [A-Z], blanks, commas (,) and full stops (.).
	std::string maxOccuringWord(std::string text);
	// Lektion 4 findPattern opgave (The task is to find words in the parameter text that contains all the letters in the parameter word)
	int findPattern(std::string text, std::string word);
	// Final exercises opgave 7 longest chain
	int longestChain(int val);
	// Final exercises opgave 9 pythagoran triplets
	int pythagoranTriplets(int eq);

private:
	// For maxOccuringWord
	char lowercase(char c) {
		if (c >= 'A' && c <= 'Z') {
			return c + 32;
		}
		return c;
	};

	// For longestChain
	int findLengthOfChain(int x) {
		if (x <= 1) {
			return 1;
		}
		if (x % 2 == 0) {
			return 1 + findLengthOfChain(x / 2);
		}
		else {
			return 1 + findLengthOfChain(3 * x + 1);
		}
	}
};
#endif
