### [Match Specific Pattern](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377990?leftPanelTab=0)
```
Problem Statement
Ninja has given you a list of WORDS and a PATTERN string. 
Your task is to find all such words in the list which match the given pattern.
A valid match is found if and only if every character in the pattern is uniquely mapped to a character in a word.

Sample Input 1:
2
2
cdd pcm
foo
3
abcd km qst
pqr
Sample Output 1:
cdd 
qst 
Explanation 1:
For the first test case, the list of words is {cdd, pcm} and the pattern is 'foo'. 

For the word 'cdd': 
The letters ‘f’, ‘o’, ‘o’ of the pattern, map to letters ‘c’, ‘d’, ‘d’ of the word respectively. 
As every letter in the pattern maps uniquely to a corresponding letter in the word. Hence, it is a valid match.

For the word 'pcm': 
The letters ‘f’, ‘o’, ‘o’ of the pattern map to letters ‘p’, ‘c’, ‘m’ of the word respectively. 
As the same letter ‘o’, in the pattern, maps to two different letters ‘c’ and ‘m’ in the word. Hence, 'pcm' is not a valid match.

For the second test case, the list of words is {abcd, km, qst} and the pattern is 'pqr'.

For the word 'abcd': 
The letters ‘p’, ‘q’, ‘r’ of the pattern map to letters ‘a’, ‘b’, ‘c’ of the word respectively.
But, there is no character in the pattern which maps to the letter ‘d’ in the word. Hence, it is not a valid match.

For the word 'km':
The letters ‘p’, ‘q’ of the pattern, map to letters ‘k’, ‘m’ of the word respectively. 
But. there is no character in the word which maps to the letter ‘r’ in the pattern. Hence, it is not a valid match. 

For the word 'qst': 
The letters ‘p’, ‘q’, ‘r’ of the pattern map to letters ‘q’, ‘s’, ‘t’ of the word respectively.
As every letter in the pattern maps uniquely to a corresponding letter in the word. Hence, it is a valid match.


// Solution
bool matchHelper(string word, string pattern) {
    int n1 = word.size();
    int n2 = pattern.size();
    if (n1 == n2) {
        int p[256] = {0};
        int w[256] = {0};
        for (int i = 0; i < n1; i++) {
            if (p[pattern[i]] == 0 && w[word[i]] == 0) {
                p[pattern[i]] = word[i];
                w[word[i]] = pattern[i];
            }
            else if (p[pattern[i]] != word[i] || w[word[i]] != pattern[i])
                return false;
        }
        return true;
    }
    return false;
}

vector<string> matchSpecificPattern(vector<string> words, int n, string pattern)
{
    // Write your code here.
    vector<string> ans;
    for (auto word: words) {
        if (matchHelper(word, pattern))
            ans.push_back(word);
    }
    return ans;
   
}

// Approach 2
/*
	Time complexity: O(N * length(Pattern))
	Space Complexity: O(length(pattern))
	
	Where N is the number of words in the list.
*/

#include <unordered_map>

bool matchSpecificPatternHelper(string &word, string &pattern)
{	
	// Check if length of word is not equal to length of pattern
    if (word.length() != pattern.length())
    {
        return false;
    }
	
    // Maintain two HashMap
    unordered_map<char, char> mapPat, mapWord;
	
    // Iterate through the string pattern
    for (int i = 0; i < pattern.length(); i++)
    {
        char chW = word[i], chP = pattern[i];

        if (mapPat.find(chP) == mapPat.end() && mapWord.find(chW) == mapWord.end())
        {
            mapPat[chP] = chW;
            mapWord[chW] = chP;
        }
        else if (mapPat.find(chP) != mapPat.end() && mapPat[chP] != chW)
        {
            return false;
        }
        else if (mapWord.find(chW) != mapWord.end() && mapWord[chW] != chP)
        {
            return false;
        }
    }

    return true;
} 

vector<string> matchSpecificPattern(vector<string> words, int n, string pattern)
{	
    // Create an array to store all valid strings
    vector<string> ans;

    // Iterate over all the words.
    for (int i = 0; i < n; i++)
    {
        string word = words[i];

        bool isValid = matchSpecificPatternHelper(word, pattern);
		
        // Check if isValid is equal to true
        if (isValid)
        {
            ans.push_back(word);
        }
    }
	
    // Return the array ans
    return ans;
}
```
