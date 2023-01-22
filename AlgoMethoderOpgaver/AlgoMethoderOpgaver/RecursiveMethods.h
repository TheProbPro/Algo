#ifndef RECURSIVE_METHODS_H
#define RECURSIVE_METHODS_H
#include <string>
class RecursiveMethods
{
public:
	RecursiveMethods();

	// Returns the sum of the first n natural nmumbers
	int sum(int n);
	// Returns the sum of the first n even numbers squares
	int evenSquares(int n);
	// Returns the sum of the first n odd numbers squares
	int oddSquares(int n);
	// Returns the n'th fibonachi number
	int fib(int n);
	// Returns true if string s with the length l contains char c, otherwise false
	bool linear(std::string s, char c, int l);
	// Returns true if value is in arr otherwise false, the elements in arr are sorted
	bool binarySearch(int arr[], int value, int low, int high);
	// The algorithm returns true if the string contains a substring of three consecutive numbers where the third character is the sum of the two previous characters.
	bool additive(std::string s);
	// Returns the sum of integers greater than 0 and smaller than or equal to N that are divisible by 3.
	int sumDivisibleBy3(int n);
	// Returns the base 2 logarithm of N, and it is a precondition that N is a positive number and a power of 2.
	long logTo(int N);
	// Returns the number of occurences of an integer (Val) in an array (x). n denotes the number of elements in the array
	int getNumberEqual(int x[], int n, int val);
};
#endif
