# Knapsack Problem

## 0-1 Knapsack

In this approach, we can include or cannot include an item.<br>
For Example - Suppose a burgler wants to steal some items and the maximum weight he can carry is $10$ Kg and suppose he is given 6 items:<br>

| Item | Weight | Price |
| ---- | ------ | ----- |
| 1    | 1      | 15    |
| 2    | 2      | 5     |
| 3    | 3      | 20    |
| 4    | 4      | 30    |
| 5    | 6      | 60    |

Now we can include item $5$ or we exclude $5$, then we move on to item $4$ and do the same with item $5$ included and excluded.

## Unbounded Knapsack

In this approach, we can include any item unlimited amount of times.<br>
For Example (**Rod Cutting**): A merchant is getting some $x$ amount of money for cutting a rod (length $y$) upto a length of $z$ amount. Now we need to maximise his profit.

<br> Let $y = 5$

| Length | Price |
| ------ | ----- |
| 1      | 3     |
| 2      | 2     |
| 3      | 1     |
| 4      | 4     |

Now, we can choose Item of length $1$ five times and get the max Profit.

## Fractional Knapsack

In this approach, we can include a **proportion** of an item.<br>

### This is **not a DYNAMIC PROGRAMMING Problem**.
