def fib(n: int, map: dict = {}):
    if n in map:
        return map[n]
    if n <= 1:
        return 1
    map[n] = fib(n - 1, map) + fib(n - 2, map)
    return map[n]

print(fib(5))
print(fib(50))
