
def heightChecker(heights):
    count = 0
    expected = sorted(heights[:])
    for i in range(len(heights)):
        if heights[i] != expected[i]:
            count += 1
    return count

print(heightChecker([1, 1, 4, 2, 1, 3]))
