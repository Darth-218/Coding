#!/usr/bin/env python
import sys

linenumber = 0
safewords = []

try:
    safeindex = sys.argv.index("-s")
    safewords = sys.argv[safeindex + 1:]
except:
    safeindex = len(sys.argv)

files = sys.argv[1:safeindex]

for file in files:

    with open("dictionary.txt", "r") as dict:
        dictcontent = dict.read()
        with open(file, "r") as file:
            content = file.readlines()
            for line in content:
                linenumber += 1
                for word in line.split():
                    if word not in dictcontent and word not in safewords:
                        print(f"line:{linenumber}, \"{word}\" appears to be a typo")
