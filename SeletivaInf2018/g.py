"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin
from copy import deepcopy

def f(g, v, i, j, x, y, n, m):
    if(i == n-1 and j == m-1):
        return g[i][j]
    d = []
    for a, b in [(i+1,j), (i,j+1),(i,j-1)]:
        if a >= 0 and b >= 0 and a < n and b < m and (not v[a][b]):
            v[a][b] = True
            v2 = deepcopy(v)
            if(g[a][b] == 0):
                if(x > 0):
                    d.append( f(g,v2,a,b,x-1,y,n,m) )
                else:
                    d.append(10000000)
            elif(g[a][b] < 0):
                if(y > 0):
                    d.append( f(g,v2,a,b,x,y-1,n,m) )
                else:
                    d.append(10000000)
            else:
                d.append( f(g,v2,a,b,x,y,n,m) )
    if not d:
        d.append(10000000)
    return g[i][j] + min(d)

if __name__ == '__main__':

    for line in stdin:
        n,m,x,y = [int(num) for num in line.split()]
        g = []
        v = [[False for _ in range(m)] for _ in range(n)]
        v[0][0] = True
        for _ in range(n):
            g.append([int(num) for num in input().split()])

        print(f(g,v,0,0,x,y,n,m))
