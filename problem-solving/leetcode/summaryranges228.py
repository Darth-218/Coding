def summaryRanges(nums: list[int]) -> list[str]:
    output: list[str] = []
    ranges = set()
    p = 0
    while p < len(nums) - 1:
        if nums[p] + 1 == nums[p + 1]:
            ranges.add(str(nums[p]))
            ranges.add(str(nums[p + 1]))
        p += 1
        output.append("".join(ranges))
        ranges.clear()
    return output


print(summaryRanges([0, 1, 2, 4, 5, 7]))
print(summaryRanges([0, 2, 3, 5, 7]))
