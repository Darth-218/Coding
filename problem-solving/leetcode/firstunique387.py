def _firstUniqChar(s):
    map = {}
    for v, k in enumerate(s):
        map[k] = (map[k][0] + 1, v) if k in map else (1, v)
    for char in s:
        if map[char][0] == 1:
            return map[char][1]
    return -1


def firstUniqChar(s):
    lindex = 0
    rindex = len(s)
    counted = []
    for i in range(len(s)):
        if s[i] in counted: continue
        for j in range(len(s) - 1, -1, -1):
            if s[i] == s[j]:
                lindex, rindex = i, j
                counted.append(s[i])
                break
        if lindex == rindex:
            return i
    return -1


print(firstUniqChar("leetcode"))
print(firstUniqChar("loveleetcode"))
print(firstUniqChar("aabb"))
