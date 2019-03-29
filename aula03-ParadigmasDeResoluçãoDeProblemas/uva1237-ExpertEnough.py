"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin

if __name__ == '__main__':

    n = int(input())
    for tests in range(n):
        data = {}
        d = int(input())
        for _ in range(d):
            s, i, j = input().split()
            i, j = int(i), int(j)
            data[s] = (i, j)
        q = int(input())
        for _ in range(q):
            p = int(input())
            c = 0
            for k, v in data.items():
                if p >= v[0] and p <= v[1]:
                    marca = k
                    c += 1
                if c > 1:
                    break
            if c == 0 or c > 1:
                print('UNDETERMINED')
            else:
                print(marca)
        if tests != n-1:
            print()
