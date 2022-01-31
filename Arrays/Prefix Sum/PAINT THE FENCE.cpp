/*Problem Statement
You have a long fence in your backyard. The fence consists of 'N' sections, each of them made from a different material.
The fence is not painted yet, so you decide to hire 'Q' painters to paint it. The i-th painter will paint all the sections lying in the section range [Li, Ri].
Unfortunately, you are on a tight budget, so you decided to hire only 'Q' - 2 painters. Now, you want to maximise the number of painted sections in your fence, so you have to choose those 'Q' - 2 painters optimally.

Sample Input 1:
7 5
1 4
4 5
5 6
6 7
3 5
Sample Output 1:
7
Explanation Of Sample Output 1:
One of the best ways to choose three painters is to select 1st, 3rd and 4th painter. Together, the three can paint the whole wall.
*/


// Recursive Approch #brute force
int helper(vector<vector<int>>& ranges, vector<int> &fence, int n, int q, int Q, int i) {
    if (i + q < Q)
        return 0;
    if (i == Q)
    {
        int count = 0;
		for (int i = 1; i <= n; i++)
            if (fence[i] > 0)
                count++;
        return count;
    }
    int count = helper(ranges, fence, n, q - 1, Q, i);
    for (int i = ranges[q - 1][0]; i <= ranges[q - 1][1]; i++)
    	fence[i] = 1;
    count = max(count, helper(ranges, fence, n, q - 1, Q, i + 1));
    for (int i = ranges[q - 1][0]; i <= ranges[q - 1][1]; i++)
    	fence[i] = 0;
    return count;
    }

int paintTheFence(vector<vector<int>>& ranges, int n, int q)
{
    // Write your code here.
   vector<int> fence(n + 1, 0);
   return helper(ranges, fence, n, q, q - 2, 0);
}

// Iterative Approach #brute force

void paintFence(vector<int>& fence, int l, int r) {
    for (int i = l; i <= r; i++)
    	fence[i]++;
}
int removePaint(vector<int>& fence, int l, int r) {
    int count = 0;
    for (int i = l; i <= r; i++)
    {
        if (fence[i] == 1)
            count++;
    	fence[i]--;
    }
    return count;
}
int countPaint(vector<int>& fence, int n) {
    int count = 0;
    for (int i = 1; i <= n; i++)
    	if (fence[i] > 0)
        	count++;
    return count;
}

int paintTheFence(vector<vector<int>>& ranges, int n, int q)
{
    // Write your code here.
    vector<int> fence(n + 1, 0);
    for (int k = 0; k < q; k++)
    	paintFence(fence, ranges[k][0], ranges[k][1]);
    
    int count = countPaint(fence, n);
    
  	int mCount = 0;
    for (int i = 0; i < q - 1; i++)
    {
        int u = removePaint(fence, ranges[i][0], ranges[i][1]);
        for (int j = i + 1; j < q; j++)
        {
            int v = removePaint(fence, ranges[j][0], ranges[j][1]);
            mCount = max(count - u - v, mCount);
            paintFence(fence, ranges[j][0], ranges[j][1]);
        } 
        paintFence(fence, ranges[i][0], ranges[i][1]);
    }
    return mCount;
        
}

  
