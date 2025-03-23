#!/bin/python

# this is a test comment

import sys, os

argv: list = sys.argv

def getCommentStyle(filetype: str) -> str:
    if filetype == "py":
        return "#"
    if filetype == "cpp" or filetype == "go":
        return "//"
    else:
        return ""

def countLines(files, root = None):
        for file in files:
            if root != None:
                file = os.path.join(root, file)
            lines = {"File Name": file.split("/")[-1], "Total Lines": 0, "Code": 0, "Comments": 0, "Blank Lines": 0}
            comment_style = getCommentStyle(file.split(".")[-1])
            try:
                with open(file, "r") as file:
                    file = file.readlines()
                    lines["Total Lines"] = len(file)
                    for x in file:
                        if x.startswith(comment_style) and not x.startswith("#!"):
                            lines["Comments"] += 1
                            continue
                        if x != "\n":
                            lines["Code"] += 1
                            continue
                        else:
                            lines["Blank Lines"] += 1
                print(lines)
            except:
                pass

def main():
    for arg in argv[1:]:
        if os.path.isdir(arg):
            for root, _, files in os.walk(arg):
                countLines(files, root)
        else:
            countLines([arg])

if __name__ == "__main__":
    main()

