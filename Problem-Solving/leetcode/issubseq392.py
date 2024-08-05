def isSubsequence(s: str, t: str) -> bool:
    p1: int = 0
    p2: int = 0
    subfound = ""
    while p1 < len(s) and p2 < len(t):
        if s[p1] == t[p2]:
            subfound += t[p2]
            p1 += 1
            p2 += 1
        else:
            p2 += 1
    return subfound == s


print(isSubsequence("abc", "ahbgdc"))
print(isSubsequence("axc", "ahbgdc"))
