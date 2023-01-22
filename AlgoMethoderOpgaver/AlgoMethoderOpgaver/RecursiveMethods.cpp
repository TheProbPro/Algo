#include "RecursiveMethods.h"
#include <cmath>

RecursiveMethods::RecursiveMethods()
{
}

int RecursiveMethods::sum(int n)
{
	if (n < 1)
		return 0;
	return n + sum(n - 1);
}

int RecursiveMethods::evenSquares(int n)
{
	if (n < 1)
		return 0;
	return pow((n * 2), 2) + evenSquares(n - 1);
}

int RecursiveMethods::oddSquares(int n)
{
	//Checks if an even number has been entered
	if (n < 1) { //Makes sure that the recursive function doesnt continue forever
		return 0;
	}
	else if (n % 2 == 0) { //If N is even
		//Gives the next uneven number
		int NUneven = n - 1;
		//returns the sum of the uneven numbers squared
		return pow(NUneven, 2) + oddSquares(NUneven - 1);
	}
	else if (n % 2 == 1) { //If N is uneven
		return pow(n, 2) + oddSquares(n - 1);
	}
}

int RecursiveMethods::fib(int n)
{
	if (n < 1)
		return 0;
	else if (n == 1 || n == 2)
		return 1;
	return fib(n - 1) + fib(n - 2);
}

bool RecursiveMethods::linear(std::string s, char c, int l)
{
	if (l < 0)
		return false;
	else if (s[l] == c)
		return true;
	return linear(s, c, l - 1);
}

bool RecursiveMethods::binarySearch(int arr[], int value, int low, int high)
{
	int mid = 0;
	if (low <= high) {
		if (low == high) {
			mid = 0;
		}
		else {
			mid = (high + low) / 2;
		}
		if (arr[mid] == value) {
			return true;
		}
		else if (arr[mid] < value) {
			return binarySearch(arr, value, mid + 1, high);
		}
		else {
			return binarySearch(arr, value, low, mid + 1);
		}
	}
	else {
		return false;
	}
	return false;
}

bool RecursiveMethods::additive(std::string s)
{
	//Makes sure the recursive function doesnt continue forever
	if (s.length() == 2) {
		return false;
	}
	//Converts the first characters in the string to integer numbers
	int x = s[0] - 48;
	int y = s[1] - 48;
	int z = s[2] - 48;
	//Checks if the two first numbers equals the thrid number
	if (x + y == z) {
		return true;
	}
	else { //If the two first numbers doesnt equal the third number then we run the function again without the first number in the string
		return additive(s.substr(1, s.length()));
	}
	return false;
}

int RecursiveMethods::sumDivisibleBy3(int n)
{
	//Makes sure the recursive function doesnt continue forever
	if (n < 3) {
		return 0;
	}
	//Avoids unnessesary recursive calls
	while (n % 3 != 0) {
		n = n - 1;
	}
	//When N is divisible by 3 then I do the recursive call and add to N
	if (n % 3 == 0) {
		return n + sumDivisibleBy3(n - 1);
	}
}

long RecursiveMethods::logTo(int N)
{
	//Makes sure the recursive function doesnt continue forever
	if (N <= 1) {
		return 0;
	}
	//Calculates the logartihm_2 to N
	return 1 + logTo(N / 2);
}

int RecursiveMethods::getNumberEqual(int x[], int n, int val)
{
	if (n < 1)
		return 0;
	if (x[n] == val) {
		return 1 + getNumberEqual(x, n-1, val);
	}
	else
		return getNumberEqual(x, n - 1, val);
}
