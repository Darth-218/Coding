
def mergeNodes(head):
    sum = 0
    modhead = []
    for i in range(1, len(head)):
        sum += head[i]
        if head[i] == 0:
            modhead.append(sum)
            sum = 0
            continue
    return modhead

print(mergeNodes([0, 3, 1, 0, 4, 5, 2, 0]))
print(mergeNodes([0, 1, 0, 3, 0, 2, 2, 0]))
