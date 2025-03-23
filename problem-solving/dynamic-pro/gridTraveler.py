def gridTraveler(m: int, n: int, map: dict = {}):
    if (n, m) in map:
        return map[(n, m)]
    if n == 0 or m == 0:
        return 0
    if n == 1 or m == 1:
        return 1
    map[(n, m)] = gridTraveler(m - 1, n) + gridTraveler(m, n - 1)
    return map[(n, m)]

print(gridTraveler(2, 3))
print(gridTraveler(3, 3))
print(gridTraveler(18, 18))
