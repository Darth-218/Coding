def minCostClimbingStairs(cost):
    i = 0 if cost[0] < cost[1] else 1
    sum = cost[i]
    while i < len(cost) - 2:
        if cost[i + 1] <= cost[i + 2]:
            sum += cost[i + 1]
            i += 1
        else:
            sum += cost[i + 2]
            i += 2
    return sum

print(minCostClimbingStairs([10, 15, 20]))
print(minCostClimbingStairs([1,100,1,1,1,100,1,1,100,1]))
