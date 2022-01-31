/*
Problem Statement
Assume you initially have an empty array say ‘ARR’.
You need to return the updated array provided that some ‘Q’ number of queries were performed on this array.
The queries are of two types:
1. 1 ‘VAL’, for this type of query, you need to insert the integer 'VAL' to the end of the array.
2. 2 ‘VAL’, for this type of query, you need to take the bitwise XOR of all the elements of the array with 'VAL' i.e each element of the array ‘ARR’ will be updated as ‘ARR[i]’ = ‘ARR[i]’ ^ ‘VAL’ ( ^ denotes the bitwise XOR operation).

Sample Input 1:
2
2
1 3
2 2
3
1 2
2 3
2 1
Sample Output 1:
1
0
Explanation For Sample Input 1:
For the first test case:
After the first query, 3 will be pushed into the array, so the array will be {3}, then after processing the second query the array will be changed to {3^2} i.e. {1}. So the output array will be {1}.

For the second test case:
After the first query, 2 will be pushed into the array, so the array will be {2}, then after processing the second query the array will be changed to {2^3} i.e. {1}, further the array is modified as {1^1} i.e {0}, after processing the third query. So the output array will be {0}.
*/


// Approach 1
vector<int> xorQuery(vector<vector<int>> &queries)
{
	// Write your code here
    vector<int> x(100001, 0);
    
    vector<int> ans;
     for (auto v : queries)
     {
         if (v[0] == 1)
             ans.push_back(v[1]);
         else
         {
             x[0] ^= v[1];
             x[ans.size()] ^= v[1];
         }
     }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == 0)
            ans[i] ^= x[0];
        else
        {
			x[i] = x[i] ^ x[i - 1];
            ans[i] ^= x[i];
        }
    }
    return ans;
}

// Approach 2

vector<int> xorQuery(vector<vector<int>> &queries)
{
  vector<int> ans;
  int flag = 0;
    for (auto v : queries)
   	{
       if (v[0] == 1)
          ans.push_back(v[1] ^ flag);
       else
          flag ^= v[1];
   	}
   	for (int i = 0; i < ans.size(); i++)
       ans[i] ^= flag;
    return ans;
}
   
