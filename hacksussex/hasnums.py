def Solution(matrix: list[list[int]]) -> bool:
    tracker = set()
    for x in matrix:
        for y in x:
            tracker.add(y)
    n = len(matrix[0])
    if sum(list(tracker)) == (n * (n + 1)) / 2:
        return True
    return False


print(Solution([[1, 2, 3], [1, 3, 2], [2, 3, 1]]))
