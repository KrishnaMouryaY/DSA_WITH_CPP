### [Multiply Two Strings](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1382161)
```
Problem Statement
You are given two big numbers ‘A’ and ‘B’ as strings. Your task is to find the product of both the numbers.
Sample Input 1:
2
17281 
91276
123
456
Sample Output 1:
1577340556
56088    
Explanation For Sample 1:
For the first test case:
A=17281, and B=91276
The product of both numbers is 1577340556.

For the second test case:
A=123, B=456
The product of both numbers is 56088

// Solution

#include <bits/stdc++.h>
bool checkAllZeroes(string &a) {
    for (int i = 0; a[i] != '\0'; i++)
        if (a[i] != '0')
            return false;
    return true;
}
string multiplyWithChar(string &a, char c) {
    string ans = "";
    int carry = 0;
    for (int i = a.length() - 1; i >= 0; i--) {
		int u = a[i] - '0';
        int v = c - '0';
        int res = (u * v) + carry;
        carry = 0;
        if (res > 9) {
            carry = res / 10;
            res = res % 10;
        }
        ans = char('0' + res) + ans; 
    }
    
    if (carry != 0)
        ans = char(carry + '0') + ans;
	return ans;
}
string addTwoStrings(string &a, string &b, int k) {
    if (k == 0)
        return b;
    string ans = "";
    int end1 = a.length() - 1;
    int end2 = b.length() - 1;
    for (int i = 0; i < k; i++) {
        ans = a[end1--] + ans;
    }
    int carry = 0;
    while (end1 >= 0) {
        int u = a[end1] - '0';
        int v = b[end2] - '0';
        int res = u + v + carry;
        carry = 0;
        if (res > 9) {
            carry = res / 10;
            res = res % 10;
        }
        ans = char('0' + res) + ans; 
        end1--;
        end2--;
    }
    while (end2 >= 0) {
        int u = b[end2] - '0';
        int res = u + carry;
        carry = 0;
        if (res > 9) {
            carry = res / 10;
            res = res % 10;
        }
        ans = char('0' + res) + ans; 
        end2--;
    }
    if (carry != 0)
        ans = char(carry + '0') + ans;
	return ans;
        
}
string multiplyStrings(string a , string b ){
    //Write your code here
    if (b.length() > a.length())
        swap(a, b);
    string ans = "";
    int j = 0;
    for (int i = b.length() - 1; i >= 0; i--) {
        string res = multiplyWithChar(a, b[i]);
        ans = addTwoStrings(ans, res, j);
        j++; 
    }
    if (checkAllZeroes(ans))
        return "0";
	return ans;
}
```
