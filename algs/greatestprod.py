# An algorithm to find the subarray producing the greatest product

def greatestProduct(array: list[int]):
    max_prodct =
    product = 1
    product_array = list()
    start = 0
    end = 0
    for i in range(len(array)):
        current = array[i]
        if product * current > product:
            product *= current
            product_array.append(current)
            continue
