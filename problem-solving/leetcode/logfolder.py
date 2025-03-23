def minOperations(logs):
    steps: int = 0
    for operation in logs:
        if operation == "../":
            steps -= 1 if steps > 0 else 0
        elif operation == "./":
            continue
        else:
            steps += 1

    return steps


print(minOperations(["d1/", "../", "../", "../"]))
