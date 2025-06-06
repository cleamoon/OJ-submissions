ans = 2

nd = 10_000_000_000

i = 7830457

def calc(b, p):
    if p == 1:
        return b % nd
    elif p % 2 == 1:
        return (2 * calc(b, p-1)) % nd
    else:
        sq = calc(b, p//2)
        return sq * sq

print((calc(2, i) * 28433 +1) % nd)

