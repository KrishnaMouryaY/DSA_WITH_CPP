// Problem Statement
// You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.
// Note:
// Each pair should be sorted i.e the first value should be less than or equals to the second value. 

// Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.
// Input Format:
// The first line of input contains two space-separated integers 'N' and 'S', denoting the size of the input array and the value of 'S'.

// The second and last line of input contains 'N' space-separated integers, denoting the elements of the input array: ARR[i] where 0 <= i < 'N'.
// Output Format:
// Print 'C' lines, each line contains one pair i.e two space-separated integers, where 'C' denotes the count of pairs having sum equals to given value 'S'.
// Note:
// You are not required to print the output, it has already been taken care of. Just implement the function.
// Constraints:
// 1 <= N <= 10^3
// -10^5 <= ARR[i] <= 10^5
// -2 * 10^5 <= S <= 2 * 10^5

// Time Limit: 1 sec
// Sample Input 1:
// 5 5
// 1 2 3 4 5
// Sample Output 1:
// 1 4
// 2 3
// Explaination For Sample Output 1:
// Here, 1 + 4 = 5
//       2 + 3 = 5
// Hence the output will be, (1,4) , (2,3).
  
// Sample Input 2:
// 5 0
// 2 -3 3 3 -2
// Sample Output 2:
// -3 3
// -3 3
// -2 2

//My solution
#include<bits/stdc++.h>
void makePairs(vector<vector<int>> &pairs, int a, int b, int n) {
    vector<int> v{a, b};
    for (int i = 0; i < n; i++)
        pairs.push_back(v);  
}
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    unordered_map<int, int> mp;
   	vector<vector<int>> pairs;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (mp.find(s - arr[i]) != mp.end()) {
            int a = min(arr[i], s - arr[i]);
            int b = max(arr[i], s - arr[i]);
            makePairs(pairs, a, b, mp[s - arr[i]]);
        }
        if (mp.find(arr[i]) == mp.end()) {
            mp[arr[i]] = 1;
        }
        else
            mp[arr[i]]++;
    }
    sort(pairs.begin(), pairs.end());
    return pairs;
    
}

//using two pointers approach
/*

    Time Complexity: O(N ^ 2)
    Space Complexity: O(N)

    where 'N' is the total number of elements
    i.e the size of the input array.

*/

#include<map>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Used to store result.
    vector<vector<int>> ans;

    map<int, int> mp;
    vector<int> keyArray;
    for (int num : arr) {

        if(!mp.count(num)){
            keyArray.push_back(num);
        }

        // Store frequency of each unique element.
        mp[num] += 1;
    }
    
    sort(keyArray.begin(), keyArray.end());
    
    for (int key : keyArray) {

        if (key + key == s) {

            int freq = mp[key];

            // Total number of such pairs will be 'FREQ*(FREQ-1)/2'.
            for (int j = 0; j < freq * (freq - 1) / 2; j++) {

                ans.push_back({ key, key });
            }
        }
    }

    // Maintain two pointers.
    int low = 0;
    int high = keyArray.size() - 1;

    while (low < high) {

        int currSum = keyArray[low] + keyArray[high];

        // If the current sum is equal to the target sum.
        if (currSum == s) {

            int freq = mp[keyArray[low]] * mp[keyArray[high]];

            // Total number of such pairs will be 'FREQ'.
            for (int j = 0; j < freq; j++) {

                ans.push_back({ keyArray[low], keyArray[high] });
            }

            low++;
            high--;

        }
        else if (currSum < s) {

            low++;
        }
        else {

            high--;
        }

    }

    for (int i = 0; i < ans.size(); i++) {

        int a = ans[i][0], b = ans[i][1];
        ans[i][0] = min(a, b);
        ans[i][1] = max(a, b);
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}
