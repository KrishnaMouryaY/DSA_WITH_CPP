### [Selling Stock](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381887)

```
Problem Statement
You have been given stock values/prices for N number of days. Every i-th day signifies the price of a stock on that day. Your task is to find the maximum profit which you can make by buying and selling the stocks.
 Note :
You may make as many transactions as you want but can not have more than one transaction at a time i.e, if you have the stock, you need to sell it first, and then only you can buy it again.
Input Format :
The first line contains an integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the total number of days for which you have stock prices.

The second line contains 'N' single space-separated integers representing the price of the stock on i-th day.
Output Format :
For each test case, print the maximum profit that you can earn.

Output for every test case will be printed in a separate line.
Note :
You are not required to print anything explicitly. Just implement the function.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1 :
1
7
1 2 3 4 5 6 7
Sample Output 1 :
6
Explanation :
We can make the maximum profit by buying the stock on the first day and selling it on the last day.
Sample Input 2 :
1
7
7 6 5 4 3 2 1
Sample Output 2 :
0
Explanation :
We can make the maximum profit by not buying the stock.
// MY SOLUTION

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    long profit = 0;
    long buy = values[0];
    long sell = values[0];
    for (int i = 1; i < n; i++) {
        if (values[i] > values[i - 1]) {
            sell = values[i];
            profit += sell - buy;
            buy = values[i];
        }
        else
        {
            buy = values[i];
            sell = values[i];
        }
    }
    return profit;
    
}
// SOLUTION
// BRUTE FORCE APPROACH
/*
    Time Complexity : O(N ^ N)
    Space Complexity : O(N)

    where N is the total number of days
*/

long maxProfitHelper(long *values, int n, int currentDay)
{
    // Base case
    if (currentDay >= n)
    {
        return 0L;
    }

    long ans = 0L;

    for (int buyingDay = currentDay; buyingDay < n; buyingDay++)
    {
        long maxProfit = 0L;

        for (int sellingDay = buyingDay + 1; sellingDay < n; sellingDay++)
        {

            if (values[buyingDay] < values[sellingDay])
            {
                long profitEarned = (values[sellingDay] - values[buyingDay]) + maxProfitHelper(values, n, sellingDay + 1);
                maxProfit = max(maxProfit, profitEarned);
            }
        }

        ans = max(ans, maxProfit);
    }

    return ans;
}

long getMaximumProfit(long* values, int n)
{
    // If the data is only for one day, we simply return 0 because we can't sell if we buy on day 0
    return maxProfitHelper(values, n, 0);
}

// EFFICIENT APPROACH
/*
    Time Complexity : O(N)
    Space Complexity : O(1)
    
    where N is the total number of days.
*/

long getMaximumProfit(long *values, int n)
{
    // If the data is only for one day, we simply return 0 because we can't sell if we buy on day 0
    if (n <= 1)
    {
        return 0;
    }

    long profit = 0L;
    int buyingDay = 0, sellingDay = 1;
    int totalDays = n;

    while (sellingDay < totalDays)
    {
        // If the value of the stock is greater than the buying day, sell the stock
        if (values[sellingDay] > values[buyingDay])
        {
            // Add the profit earned by selling the stock.
            profit += (values[sellingDay] - values[buyingDay]);
        }
        buyingDay++;
        sellingDay++;
    }

    return profit;
}
```
