def mergeAlternately(word1: str, word2: str) -> str:
    merged: str = ""
    shortest: str = word1 if len(word1) < len(word2) else word2
    longest: str = word1 if len(word1) > len(word2) else word2
    for index in range(len(shortest)):
        merged += word1[index]
        merged += word2[index]
    merged += longest[len(shortest) :]
    return merged


print(mergeAlternately("abc", "pqr"))
print(mergeAlternately("ab", "pqrs"))
print(mergeAlternately("abcd", "pq"))
