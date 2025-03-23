def minCostClimbingStairs(cost):
    costs = []
    i = 0
    while i < 2:
        sum = cost[i]
        j = i
        while j < len(cost) - 2:
            if cost[j + 1] < cost[j + 2]:
                sum += cost[j + 1]
                j += 1
                continue
            sum += cost[j + 2]
            j += 2
        costs.append(sum)
        i += 1
    return min(costs)

print(minCostClimbingStairs([10, 15, 20]))
print(minCostClimbingStairs([1,100,1,1,1,100,1,1,100,1]))
