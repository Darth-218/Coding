def fib(n, map: dict = {}):
    if n in map:
        return map[n]
    if n == 0:
        return 0
    if n == 1:
        return 1;
    else:
        map[n] = fib(n - 1, map) + fib(n - 2, map)
        return map[n]

print(fib(2))
print(fib(3))
print(fib(400))
