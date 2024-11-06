s = input()
li = s.split()


def binary_search(li, x):
    low = 0
    high = len(li) - 1
    while low <= high:
        mid = (low + high) // 2
        if li[mid] == x:
            return mid
        elif li[mid] < x:
            low = mid + 1
        else:
            high = mid - 1
    return -1


while True:
    e = input()
    if e == "#":
        break
    res = binary_search(li, e)
    if res == -1:
        print("None")
    else:
        print(e)
