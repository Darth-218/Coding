#!/usr/bin/env python

import sys

toreplace = sys.argv[1]
replacment = sys.argv[2]
file = sys.argv[3]

with open(file, "r") as toedit:
    lines = toedit.readlines()
    output = []
    for line in lines:
        words = line.split()
        for word in range(len(words)):
            if words[word] == toreplace:
                words[word] = replacment
                output.append(words)
    print(output)
    # with open(file, "w") as toedit:
    #     toedit.writelines(output)
