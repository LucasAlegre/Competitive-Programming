"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from itertools import combinations


def gcd(p, q):
    if q > p:
        return gcd(q, p)
    if q == 0:
        return p
    return gcd(q, p % q)

if __name__ == '__main__':

    N = int(input())
    for _ in range(N):
        l = [int(x) for x in input().split()]
        r = max([gcd(c[0], c[1]) for c in combinations(l, 2)])
        print(r)

