### [PROBLEM LINK HERE](https://practice.geeksforgeeks.org/problems/four-elements2452/1/#)

```
Given an array A of N integers. You have to find whether a combination of four elements in the array whose sum is equal to a given value X exists or not.

Example 1:
Input:
N = 6
A[] = {1, 5, 1, 0, 6, 0}
X = 7
Output:
1
Explantion:
1, 5, 1, 0 are the four elements which makes sum 7. 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function find4Numbers() which takes the array A[], its size N and an integer X as inputs and returns true if combination is found else false. Driver code will print 1 or 0 accordingly.
Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(1

Solution:
bool find2Numbers(int A[], int u, int v, int X) {
    while (u < v) {
        int pairSum = A[u] + A[v];
        if (pairSum == X)
            return true;
        else if (pairSum > X)
            v--;
        else if (pairSum < X)
            u++;
    }
    return false;
}


bool find4Numbers(int A[], int n, int X)  
{
    sort(A, A + n);
    bool ans = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (find2Numbers(A, j + 1, n - 1, X - A[i] - A[j]))
                return true;
        }
    }
    return false;
    
}

// SOLUTION 1:
class Solution{
    public:
    vector<vector<int>> fourSum(vector<int> &a, int k) {
    if (a.size() < 4) return {};
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 3; ++i) {
        // current element is greater than k then no quadruplet can be found
        if (a[i] > 0 && a[i] > k) break;
        // removing duplicates
        if (i > 0 && a[i] == a[i - 1]) continue;
        for (int j = i + 1; j < a.size() - 2; ++j) {
            // removing duplicates
            if (j > i + 1 && a[j] == a[j - 1]) continue;

            // taking two pointers
            int left = j + 1;
            int right = a.size() - 1;
            while (left < right) {
                int old_l = left;
                int old_r = right;
                // calculate current sum
                int sum = a[i] + a[j] + a[left] + a[right];
                if (sum == k) {
                    // add to answer
                    ans.push_back({a[i], a[j], a[left], a[right]});

                    // removing duplicates
                    while (left < right && a[left] == a[old_l]) left++;
                    while (left < right && a[right] == a[old_r]) right--;
                } else if (sum > k) {
                    right--;
                } else {
                    left++;
                }
            }
        }
    }
    return ans;
    }
};
```
