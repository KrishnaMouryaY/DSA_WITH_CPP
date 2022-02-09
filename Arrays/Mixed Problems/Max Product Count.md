### [Max Product Count](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381886)
```
Problem Statement
You are given an array 'ARR' of 'N' distinct integers.
Your task is to find the product 'P' with the highest count('C') of quadruples which follow p * q = r * s where p, q, r, and s are elements of the array with different indexes.
Note:
1. Quadruple p*q = r*s is the same as r*s = p*q.

2. If 2 or more products have the same count of quadruples, print the lowest value of the product i.e if (P1, P2) are the 2 products with the same count of such quadruples(C1 = C2) then 'P' = min(P1, P2).

3. If no such quadruple exists('C' = 0), return 0.
Example:
If the given array is [3, 4, 6, 2, 1], then the answer would be 6 1. Because there are two products 'P' i.e 6 and 12 which have the highest and same count 'C' of quadruples, i.e 'C' = 1. Therefore the lowest value of the product 'P' is the answer i.e 6.
Input Format:
The first line of input contains an integer 'T' representing the number of test cases.

The first line of each test case contains integer 'N' denoting the size of the array.

The second line of each test case contains 'N' single space-separated integers representing the array elements of array 'ARR'.
Output Format:
For each test case, print two single space-separated integers 'P', and 'C', denoting the value of the product and the count of quadruples respectively. 
Note:
You don't need to print anything, it has already been taken care of. Just implement the given function.   
Constraints:
1 <= T <= 100
4 <= N <= 10^2  
1 <= ARR[i] <= 10^9

Where 'ARR[i]' denotes the element at index 'i' in the array 'ARR'.

Time Limit: 1 sec
Sample Input 1:
2
6
2 6 3 4 1 12 
6
4 1 7 2 6 5
Sample Output 1:
12 3
0
Explanation For Sample 1:
In test case 1, there are a total of 3 quadruples for product 12 in the given array as given below:

2 6 and 3 4, (p = 2, q = 6, r = 3 and s = 4).
2 6 and 1 12, (p = 2, q = 6, r = 1 and s = 12).
3 4 and 1 12, (p = 3, q = 4, r = 1 and s = 12).

Thus, product('P') = 12, Count('C') = 3. No other value has 3 or more Quadruples.

In test case 2, every pair of elements forms a different value on multiplying, and thus no Quadruple is formed by the given set of elements of the array. Hence 0 Quadruples formed.
Sample Input 2:
1
8
7 2 10 1 8 3 9 4
5
4 2 1 8 2
Sample Output 2:
8 1
8 3
Explanation For Sample Output 2:
In test case 1, there is only one quadruple in the given array i.e (p = 2, q = 4, r = 8 and s = 1). Thus, Product('P') = 8 and Count('C') = 1. No other Quadruple is possible.

In test case 2, there are a total of 3 quadruples for product 8 in the given array as given below:

1 8 and 2i 4, (p = 1, q = 8, r = 2i and s = 4).
1 8 and 2ii 4, (p = 1, q = 8, r = 2ii and s = 4).
2i 4 and 2ii 4, (p = 2i, q = 4, r = 2ii and s = 4).

Here, 2i and 2ii denote the two different occurrences of 2 in the array.

Thus, Product('P') = 8, Count('C') = 3. No other value has 3 or more Quadruples.

// MY SOLUTION

#include <bits/stdc++.h>

bool check(int a, int b,int i,int j) {
    if (a != i && a != j && b != i && b != j)
        return true;
    return false;
}
vector<long long> maxProductCount(vector<int> &arr, int n) {
    // Write your code here.
    unordered_map<long long int, vector<pair<int, int>>> mp;
    unordered_map<long long int, int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long a = arr[i];
            long long b = arr[j];
            long long product = a * b;
            if (mp.find(product) != mp.end()) {
                for (auto p: mp[product]) {
                    if (check(p.first, p.second, i, j))
                        ans[product]++;
                }
            }
            mp[product].push_back({i, j});
        }
    }
    long long int p = 0;
    long long int count = 0;
    for (auto i: ans) {
        if (i.second > count) {
            p = i.first;
            count = i.second;
        }
        else if (i.second == count)
            p = min(p, i.first);
    }
    return {p, count};
}

// Coding ninjas solution
/*

    Time Complexity: O(N ^ 2)
    Space Complexity: O(N ^ 2)

    Where N is the size of array.

*/

#include <unordered_map>

vector<long long> maxProductCount(vector<int> &arr, int n) {
    
    // To store the product of two number as Key and value as the total number of occurrence.
    unordered_map<long long, int> map;

    // To find all pair product and store it to Map with there frequencies.
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long a = arr[i];
            long long b = arr[j];
            long long pairProduct = a * b;
            map[pairProduct]++;
        }
    }

    // To store max product pair.
    long long maxProd = 0;

    // To store frequency of max product.
    int freq = 0;

    // Traverse the Map.
    for (auto prods : map) {
        if (prods.second >= freq) {
            // If frequency is same as previous max frequency then choose the one with minimum product.
            if (prods.second == freq) {
                maxProd = min(maxProd, prods.first);
            } 
            else {
                maxProd = prods.first;
            }
            freq = prods.second;
        }
    }

    // Vector to store the values of max product and Quadruples.
    vector<long long> result;

    // If there is no pair having frequency count > 1.
    if (map.find(maxProd) == map.end() || map[maxProd] == 1) {
        // Returning the array containing max product and number of Quadruples.
        result.push_back(0);
        result.push_back(0);
        return result;
    }
    else {
        // Calculating total Quadruples as all Combination a pair can have with given frequency.
        long long allCombinations = ((freq * (freq - 1))) / 2;
        result.push_back(maxProd);
        result.push_back(allCombinations);
        // Returning the pair of max product and number of Quadruples.
        return result;
    }
}
```
