"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

import copy

if __name__ == '__main__':

    while True:
        n, r, c, k = [int(x) for x in input().split()]
        odeia = [i for i in range(1, n)] + [0]
        if n+r+c+k==0:
            break

        terra = []
        for _ in range(r):
            terra.append([int(x) for x in input().split()])

        for _ in range(k):
            nterra = copy.deepcopy(terra)

            for i in range(r):
                for j in range(c):
                    herdeiro = terra[i][j]
                    for v in [(i,j+1), (i+1,j), (i,j-1), (i-1,j)]:
                        if v[0] >= 0 and v[0] < r and v[1] >= 0 and v[1] < c:
                            if odeia[herdeiro] == terra[v[0]][v[1]]:
                                nterra[v[0]][v[1]] = herdeiro
            terra = nterra

        for row in terra:
            print(' '.join([str(x) for x in row]))
