def longestCommonPrefix(strs: list[str]) -> str:
    longestpre: str = min(strs)
    for string in strs:
        if string == longestpre:
            continue
        p: int = 0
        while p < len(longestpre):
            if longestpre[p] != string[p]:
                longestpre = longestpre[:p]
                break
            p += 1
    return longestpre


print(longestCommonPrefix(["flour", "flower", "flos"]))
print(longestCommonPrefix(["ab", "a"]))
