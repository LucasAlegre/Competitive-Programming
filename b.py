"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin

if __name__ == '__main__':

    n, m = [int(x) for x in input().split()]
    r = []
    for _ in range(m):
        i, j = [int(x) for x in input().split()]
        r.append((i,j))

