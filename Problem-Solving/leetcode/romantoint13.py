def romanToInt(s: str) -> int:
    num: int = 0
    vals = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
    for index in range(1, len(s)):
        num += (
            vals[s[index - 1]]
            if vals[s[index - 1]] >= vals[s[index]]
            else -vals[s[index - 1]]
        )
    num += vals[s[len(s) - 1]]
    return num


print(romanToInt("III"))
print(romanToInt("LVIII"))
print(romanToInt("MCMXCIV"))
