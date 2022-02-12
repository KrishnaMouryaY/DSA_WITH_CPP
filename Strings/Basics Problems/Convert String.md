### [Convert String](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377975)
```
Problem Statement
You are given a string 'STR'. You have to convert the first alphabet of each word in a string to UPPER CASE.
For example:
If the given string 'STR' = ”I am a student of the third year” so you have to transform this string to ”I Am A Student Of The Third Year"
Note:
'STR' will contains only space and alphabets both uppercase and lowercase. The words will be separated by space.
Input Format :
The first line of input contains an integer ‘T’ denoting the number of test cases.

Then, the ‘T’ test cases follow.

The first and only line of each test case contains the string 'STR' that needs to be transformed.
Output Format :
For each test case, print the final string after transformation.

The output of each test case will be printed in a separate line.
Note:
You don’t have to print anything; it has already been taken care of. Just implement the given function. 
Constraints:
1 <= 'T' <= 10
1 <= |STR| <= 10^5

Where |STR| denotes the length of the string.

Time Limit: 1 sec
Sample Input 1 :
3
I love programming
they are playing cricket
good to see you
Sample Output 1 :
I Love Programming
They Are Playing Cricket
Good To See You
Explanation Of The Sample Input 1:
For the first test case:
Given string is “I love programming” we will convert every letter after space to uppercase to give the output as ”I Love Programming”.

For the second test case:
Given string is “they are playing cricket” we will convert every letter after space to uppercase to give the output as  “They Are Playing Cricket”. 

For the third test case:
Given string is “good to see you” we will convert every letter after space to uppercase to give the output as “Good To See You”. 


// Solution
char changeIfSmaller(char a) {
    if (a >= 'a' && a <= 'z')
        a = a - 32;
    return a;
}

string convertString(string str) 
{
	// WRITE YOUR CODE HERE
    str[0] = changeIfSmaller(str[0]);
    for (int i = 1; str[i] != '\0'; i++) {
			if (str[i - 1] == ' ')
                str[i] = changeIfSmaller(str[i]);
    }
    return str;
    
}

```
