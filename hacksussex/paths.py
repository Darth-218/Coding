def Solution(paths: list[list[str]]) -> str:
    map = {}
    for path in paths:
        for i in range(2):
            if path[i] in map:
                map[path[i]] += 1
            else:
                map[path[i]] = 1
    dest = paths[0][1]
    for path in paths:
        if map[dest] > map[path[1]]:
            dest = path[1]
    return dest


print(Solution([["london", "new york"], ["new york", "lima"], ["lima", "sao"]]))
