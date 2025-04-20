def check(seta, setb) -> bool:
    for c in range(26):
        if seta[c] == setb[c] and seta[c] == 1:
            return False
    return True

def maxProduct(words: list[str]) -> int:
    max_product = 0
    chars = dict()
    for i in range(len(words)):
        chars[i] = [0] * 26
        for a in words[i]:
            chars[i][ord(a) - ord("a")] = 1
        for j in range(i):
            if check(chars[i], chars[j]):
                product = len(words[i]) * len(words[j])
                max_product = product if product > max_product else max_product
    return max_product


print(maxProduct(["abcw","baz","foo","bar","xtfn","abcdef"]))
