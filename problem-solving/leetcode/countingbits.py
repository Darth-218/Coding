def countBits(n):
    res = []
    for i in range(n + 1):
        sub_bit = str(bin(i)).count("1")
        res.append(sub_bit)
    return res

print(countBits(50000))
