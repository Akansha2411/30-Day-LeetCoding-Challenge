/*
Write an algorithm to determine if a number n is "happy".
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
Return True if n is a happy number, and False if not.

Example: 
Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

/*
Approach:
1. Keep squaring and adding the digits of the number until either the number becomes 1 (return true) or the number repeats itself (return false). 
2. Use hashmap to keep a track of numbers that have been observed so far.
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;  //O(1) solution

int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}
 
bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}


/* Questions: Why unhappy number must end with a loop?
There is a proof from wiki:
https://en.wikipedia.org/wiki/Happy_number
Numbers that are happy, follow a sequence that ends in 1. All non-happy numbers follow sequences that reach the cycle:
4, 16, 37, 58, 89, 145, 42, 20, 4, ... */
 
// method return true if n is Happy Number 
// numSquareSum method is given in below detailed code snippet 
/*
int numSquareSum(int n) 
{ 
    int squareSum = 0; 
    while (n) 
    { 
        squareSum += (n % 10) * (n % 10); 
        n /= 10; 
    } 
    return squareSum; 
}
int isHappyNumber(int n)  //O(n) space complexity.
{ 
	set<int> st; 
    
	while (1) 
	{ 
		n = numSquareSum(n); 
		if (n == 1) 
			return true; 
		if (st.find(n) != st.end()) 
			return false; 
		st.insert(n); 
	} 
} 
 */
