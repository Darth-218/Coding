def minSteps(s, t):
    sdic = {}
    tdic = {}
    size = len(s)
    for i in range(size):
        sdic[s[i]] = s.count(i)
        tdic[t[i]] = t.count(i)

