### [Given a string, find the next smallest palindrome](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1382156?leftPanelTab=0)
```
Problem Statement
You are given a number 'N' in the form of a string 'S'.
your task is to find the smallest number strictly greater than the given number 'N' which is a palindrome.

Sample Input 1:
1
4
1221
Sample Output 1:
1331
Explanation For Sample Input 1:
The next smaller palindrome to 1221 is 1331, as it is strictly greater than 1221 and it reads the same from the front and back both.

// Solution
string nextLargestPalindrome(string s, int length){
	// Write your code here.
    int i = 0;
    int j = length - 1;
    
    int carry = 1;
    while (i < j) {
 	if (s[i] > s[j])
            carry = 0;
        else if (s[i] < s[j])
            carry = 1;
        s[j] = s[i];
        i++;
        j--;
    }
    
    if (carry == 0)
        return s;
    if (length % 2 == 0) {
        j++;
        i--;
    }
        
    while (i >= 0 && j <= length - 1 && carry != 0) {
        if (s[i] != '9' && s[j] != '9') {
            carry = 0;
            s[i] = s[i] + 1;
        }
        else if (s[i] == '9' && s[j] == '9') {
            s[i] = '0';
        }
		s[j] = s[i];
        i--;
        j++;
    }
    if (carry == 1) {
        s = '1' + s;
        s[length] = '1';
    }
    return s;  
}
```
