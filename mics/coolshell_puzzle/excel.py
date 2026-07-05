def str_to_int(s):
    base = 1
    res = 0
    for c in reversed(s):
        curr = ord(c) - ord("A") + 1
        res += curr * base
        base = base * 26
    return res


def int_to_str(n):
    res = ""
    while n > 0:
        n, r = divmod(n, 26)
        res = chr(ord("A") + r - 1) + res
    return res


print(int_to_str(str_to_int("COOLSHELL") // str_to_int("SHELL")))
