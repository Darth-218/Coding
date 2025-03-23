def maxProfit(prices: list[int]) -> int:
    maxprof: int = 0
    for x in range(len(prices)):
        for y in range(x + 1, len(prices)):
            if prices[y] < prices[x]:
                continue
            daily: int = prices[y] - prices[x]
            maxprof = max(maxprof, daily)
    return maxprof


print(maxProfit([7, 1, 5, 3, 6, 4]))
print(maxProfit([7, 6, 4, 3, 1]))
print(maxProfit([3, 2, 6, 5, 0, 3]))
