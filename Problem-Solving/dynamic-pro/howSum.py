def howSum(target: int, numbers: list):
    if target == 0:
        return []
    if target < 0:
        return None
    for number in numbers:
        subtarget = target - number
        subresult = howSum(subtarget, numbers)
        if subresult != None:
            return subresult + [number]
    return None;

print(howSum(7, [5, 3, 4, 7]))
print(howSum(7, [5, 3]))
