### [Anagram Difference](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377987)
```
Problem Statement
You have been given two strings, let's say 'STR1' and 'STR2' of equal lengths. 
You are supposed to return the minimum number of manipulations required to make the two strings anagrams.

Sample Input 1:
2
except
accept
buy
bye
Sample Output 1 :
2
1
Explanation Of Sample Output 1 :
In test case 1, we can change two character of  'STR1' i.e. {'e','x'} to {'a','c'} 
or we can change two character of  'STR2' i.e. {'a','c'} to {'e','x'}, to make string anagram. 
So the minimum number of manipulations to make 'STR1' and  'STR2' to anagram string will be 2.

In test case 2, we can change one character of  'STR1' i.e. {'u'} to {'e'} 
or we can change one character of  'STR2' i.e. {'e'} to {'u'}, to make string anagram. 
So the minimum number of manipulations to make  'STR1' and 'STR2' to anagram string will be 1.

// Solution
#include <bits/stdc++.h>
int getMinimumAnagramDifference(string &str1, string &str2) {
    // Write your code here.
    int c1[26] = {0};
    int c2[26] = {0};
    for (int i = 0; str1[i] != '\0'; i++) {
        c1[str1[i] - 'a']++;
        c2[str2[i] - 'a']++;
    }
        
    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans += abs(c1[i] - c2[i]);
    return ans/2;
}

// Approach 2
#include <vector>

int getMinimumAnagramDifference(string &str1, string &str2) {
    int n = str1.size();

    // Vector for storing the frequencies.
    vector<int> freq(26, 0);

    // Store the frequencies of characters of first string.
    for (int i = 0; i < n; i++) {
        freq[str1[i] - 'a']++;
    }

    // Subtract the frequencies of characters of second string.
    for (int i = 0; i < n; i++) {
        freq[str2[i] - 'a']--;
    }

    // Variable to store the total absolute frequencies difference.
    int freqDiff = 0;

    // Iterating for all alphabets to cacluclate the total absolute frequencies difference.
    for (int i = 0; i < 26; i++) {
        freqDiff += abs(freq[i]);
    }

    // Return minimum manipulations required to make string anagram.
    return freqDiff / 2;
}
```
