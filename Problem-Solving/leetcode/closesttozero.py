def findClosestNumber(nums):
    closest: int = nums[0]
    for num in nums:
        if abs(num) == abs(closest):
            closest = max(num, closest)
        elif abs(num) < abs(closest):
            closest = num
    return closest


print(findClosestNumber([-4, -2, 1, 4, 8]))
print(findClosestNumber([-2, 1, -1]))
