def twoSum(nums, target):
    table = {}
    for i, k in enumerate(nums):
        table[k] = i
    for i in range(len(nums)):
        select = target - nums[i]
        if select in table and table[select] != i:
            return [table[select], i]

# print(twoSum([3, 4, 2], 6))
print(twoSum([3, 3], 6))

