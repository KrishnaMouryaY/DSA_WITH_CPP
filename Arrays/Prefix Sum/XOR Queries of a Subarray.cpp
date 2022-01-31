/*
You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].

For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).

Return an array answer where answer[i] is the answer to the ith query.

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> px(arr.size());
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == 0)
                px[i] = arr[i];
            else
                px[i] = px[i - 1] ^ arr[i];
        }
        // for (int i = 0; i < queries.size(); i++)
        for (auto i : queries)
        {
            int l = i[0];
            int r = i[1];
            int res = px[r];
            
            if (l != 0)
                res = res ^ px[l - 1];
            
            ans.push_back(res);     
            
        }
        return ans;
        
    }
};
