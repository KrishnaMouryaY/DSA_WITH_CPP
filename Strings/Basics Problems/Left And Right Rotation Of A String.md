### [Left And Right Rotation Of A String](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377979)
```
Problem Statement
You are given a string 'str' and an integer 'D'. Your task is to rotate the given string left (anticlockwise) and right (clockwise) by 'D' units from the starting index. You are required to return the rotated string.
Sample Input 1 :
1
codingninjas
3
Sample Output 1 :
ingninjascod jascodingnin
Explanation For The Sample Output 1 :
In string “codingninjas” the substring of length 'D' = 3, starting from the beginning is “cod”, in the left rotation this substring is removed from the beginning and attached to the end of the string (i.e. anti-clockwise).

Similarly, in the right rotation, the substring of length 'D'  = 3 from the end is “jas”, this substring is removed from the end and attached to the beginning of the string(i.e. clockwise).

// Solution

#include <bits/stdc++.h>
void reverseString(string &str, int i, int j) {
    while (i < j) {
        swap(str[i], str[j]);
        i++;
        j--;     
    }     
}

string leftRotate(string str, int d) {
    // Write your code here.
    int n = str.size();
    d = d % n;
    if (d == 0)
        return str;
    int i = 0;
    int j = n - 1;
   	reverseString(str, i, i + d - 1);
    reverseString(str, i + d, j);
    reverseString(str, i, j);
    return str;
}

string rightRotate(string str, int d) {
    // Write your code here.
   
    int n = str.size();
    d = d % n;
    if (d == 0)
        return str;
    int i = 0;
    int j = n - 1;
   	reverseString(str, i, j - d);
    reverseString(str, j - d + 1, j);
    reverseString(str, i, j);
    return str;
    
}
```
