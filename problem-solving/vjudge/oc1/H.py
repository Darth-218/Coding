def longest(bracket: str):
    brackets = [x for x in bracket]
    return max(brackets.count("("), brackets.count(")")) - abs(brackets.count("(") - brackets.count(")"))

print(longest(")((())))(()())"))
