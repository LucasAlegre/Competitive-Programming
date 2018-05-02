"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin

def dfs(r, v, i, tasks):
    if not v[i]:
        v[i]=True
        for j in r[i]:
            dfs(r, v, j, tasks)
        tasks.append(i)


if __name__ == '__main__':

    while True:
        n, m = [int(x) for x in input().split()]
        if n==0 and m==0:
            break
        r = {}
        tasks = []
        v = [False for _ in range(n+1)]
        for _ in range(m):
            i, j = [int(x) for x in input().split()]
            if i in r.keys():
                r[i].append(j)
            else:
                r[i] = [j]
        for i in range(1,n+1):
            if i not in r.keys():
                r[i] = []
        for i in range(1,n+1):
            if not v[i]:
                dfs(r, v, i, tasks)

        print(' '.join(str(i) for i in tasks[::-1]))
