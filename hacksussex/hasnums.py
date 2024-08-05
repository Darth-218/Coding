def Solution(matrix: list[list[int]]) -> bool:
    valids = []
    for lst in matrix:
        nums = set()
        for i in lst:
            nums.add(i)
        n = len(lst)
        valids.append(sum(nums) == n * (n + 1) / 2)
        nums.clear()
        for i in range(n):
            for j in range(n):
                nums.add(matrix[i][j])
            valids.append(sum(nums) == n * (n + 1) / 2)
            nums.clear()

    return min(valids)


print(Solution([[1, 2, 3], [1, 3, 2], [2, 3, 1]]))
print(Solution([[1, 2, 3], [3, 1, 2], [2, 3, 1]]))
