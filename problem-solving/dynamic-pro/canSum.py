def canSum(target: int, numbers: list, map: dict = {}):
    if target in map:
        return map[target]
    if target == 0:
        return True
    if target < 0:
        return False
    for number in numbers:
        subtarget = target - number
        map[(subtarget)] = canSum(subtarget, numbers)
        if map[subtarget]:
            return True
    return False

print(canSum(7, [2, 4]))
print(canSum(7, [2, 4, 3]))
print(canSum(8, [6, 7, 3]))
print(canSum(900, [4, 3, 8]))
