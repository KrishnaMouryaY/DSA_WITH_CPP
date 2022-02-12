### [Find K’th Character of Decrypted String](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1382160)
```
Problem Statement
You have been given an Encrypted String where repetitions of substrings are represented as substring followed by the count of substrings.
Example: String "aabbbcdcdcd" will be encrypted as "a2b3cd3".
You need to find the 'K'th character of Decrypted String. Decrypted String would have 1-based indexing.

Sample Input 1 :
a2b3cd3
8
Sample Output 1 :
c
 Explanation to Sample Input 1 :
S = "a2b3cd3"
Decrypted String of S = "aabbbcdcdcd"
According to 1-based indexing for S, the 8th character is 'c'.

// Solution
long long stringToInteger(string &s, int start, int end) {
    long long ans = 0;
    for (int i = start; i < end; i++) {
        ans = ans * 10 + (s[i] - '0');
    }
    return ans;
    
}
char kThCharaterOfDecryptedString(string s, long long k)
{
    //  Write your code here.
    int n = s.length();
    int start1 = 0;
    int end1 = 0;
    int start2 = 0;
    int end2 = 0;
    while (true) {
	while (end1 < n) {
            if (s[end1] >= '0' && s[end1] <= '9')
                break;
            end1++;
        }

        start2 = end1;
        end2 = end1;
        while (end2 < n) {
            if (s[end2] >= 'a' && s[end2] <= 'z')
                break;
            end2++;
        }
        long long len = end1 - start1;
        long long value = stringToInteger(s, start2, end2) * len;
        
        if (value >= k) {
            k = k - 1;
            k = k % len;
            return s[start1 + k];
        }
        k = k - value;
        if (end2 == n)
            break;
        start1 = end2;
        start2 = end2;
        end1 = end2;
    }
    
}
```
