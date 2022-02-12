### [Program to validate IP address](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1382162)
```
Problem Statement
You are given the text ‘IPAddress’. Your task is to check if the given text ‘IPAddress’ is a valid ‘IPv4’ or not.
Conditions for a valid ‘IPv4’ are:
1. Text form of ‘IPAddress’ must be ‘a.b.c.d’
2. The values of a,b,c and d can vary from ‘0’ to ‘255’ and both ‘0’ and ‘255’ are inclusive.

Sample Input 1:
4
123.111.12.k
122.0.330.0
1.1.1.250
1.0.0.0.1
Sample Output 1:
False
False
True
False
Explanation Of Sample Input 1:
Test Case 1:
Given text ‘IPAddress = 123.111.12.k’, 
it is satisfying the first condition that given ‘IPAddress’ must be ‘a.b.c.d’ formed 
but it not satisfying the second condition that d must in a range of ‘0’ to ‘255’ but the value of ‘d’ is ‘k’.
Hence return ‘False’.

Test Case 2:
Given text ‘IPAddress = 122.0.330.0’,
it is satisfying the first condition that given ‘IPAddress’ must be ‘a.b.c.d’ formed 
but it not satisfying the second condition that c must in a range of ‘0’ to ‘255’ 
but the value of ‘c’ is ‘330’ and it is out of range.
Hence return ‘False’.

Test Case 3:
Given text ‘IPAddress = 1.1.1.250’, 
it is satisfying the first condition that given ‘IPAddress’ must be ‘a.b.c.d’ formed 
as well as it satisfying the second condition that a,b,c, and d must in range of ‘0’ to ‘250’.
Hence return ‘True’.

Test Case 4:
Given text ‘IPAddress = 1.0.0.0.1’,
it is not satisfying the first condition for valid ‘IPv4’, 
that text ‘IPAddress’ must be in form of ‘a.b.c.d’ but given text is a form of ‘a.b.c.d.e’
Hence return ‘False’.

//solution
bool isValidIPv4(string ipAddress) {
    // Write your code here.
    int n = ipAddress.length();
    int start = 0;
    int end = 0;
    int parts = 0;
    while (true) {
        while (end < n && ipAddress[end] != '.') {
            if (ipAddress[end] < '0' || ipAddress[end] > '9')
                return false;
            end++;
        }
        parts++;
        if (end - start > 3)
            return false;
        if (end - start == 3) {
            if (ipAddress[start] > '2')
            	return false;
            if (ipAddress[start] == '2' && ipAddress[start + 1] > '5')
                return false;
            if (ipAddress[start] == '2' && ipAddress[start + 1] == '5' && ipAddress[start + 2] > '5')
                return false;
        }
        if (end == n)
            break;
        end++;
        start = end;
    }
    
    if (parts == 4)
        return true;
    else 
        return false;
}
```
