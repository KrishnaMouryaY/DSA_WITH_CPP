### [Compare Versions](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1382159)
```
Problem Statement
You are given two versions numbers A and B as a string. 
Your task is to compare them and find out which one of them is a newer version.

Sample Input 1:
2
1.2.4
1.2.3
10.2.2
10.2.2
Sample Output 1:
1
0
Explanation For Sample Input 1:
For the first test case, 
the first two parts of both the strings are the same but the third part of the 1st version is bigger than the 2nd version. 
Hence our answer is 1

For the second test case, both the versions are identical here, so the answer will be 0.

// Solution

int compareVersions(string a, string b) 
{
    // Write your code here
    int n1 = a.length();
    int n2 = b.length();
    int start1 = 0;
  	int start2 = 0;
    int end1 = 0;
    int end2 = 0;
    while (true) {
        while (end1 < n1 && a[end1] != '.') {
            end1++;
        }
        while (end2 < n2 && b[end2] != '.') {
            end2++;
        }
        int subA = end1 - start1;
        int subB = end2 - start2;
        if (subB > subA)
            return -1;
        if (subA > subB)
            return 1;
        if (subA == subB) {
            int i = start1;
            int j = start2;
            while (i < end1 && j < end2) {
                if (a[i] < b[j])
                    return -1;
                else if (a[i] > b[j])
                    return 1;
                i++;
                j++;
            }
        }
        if (end1 == n1 || end2 == n2)
            break;
        end1++;
        end2++;
        start1 = end1;
        start2 = end2;
    }
    while (end1 < n1 && end2 == n2) {
        if (a[end1] == '.' || a[end1] == '0') {
            end1++;
            continue;
        }
        return 1;      
    }
    while (end1 == n1 && end2 < n2) {
        if (b[end2] == '.' || b[end2] == '0') {
            end2++;
            continue;
        }
        return -1;      
    }
    if (end1 == n1 && end2 == n2)
        return 0;
    
}
```
