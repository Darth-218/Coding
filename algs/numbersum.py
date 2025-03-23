def add(n: int, sum = 0):
    if n < 1 and sum < 10:
        return sum
    if n < 1:
        return add(sum)
    else:
        return add(n // 10, sum + n % 10)

print(add(1235))
