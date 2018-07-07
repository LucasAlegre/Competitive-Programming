"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin
import heapq

if __name__ == '__main__':

    case = 1
    while True:
        try:
            n = int(input())
        except:
            break

        g = {}
        order = []
        ind = {}
        name = {}
        degree = {}
        pq = []
        c = 0
        for _ in range(n):
            s = input()
            g[c] = []
            ind[s] = c
            name[c] = s
            degree[c] = 0
            c += 1

        m = int(input())

        for _ in range(m):
            i, j = [x for x in input().split()]
            g[ind[i]].append(ind[j])
            degree[ind[j]] += 1

        for i in sorted(g.keys()):
            if degree[i] == 0:
                heapq.heappush(pq, i)

        while pq:
            node = heapq.heappop(pq)
            order.append(node)
            for i in sorted(g[node]):
                degree[i] -= 1
                if degree[i] == 0:
                    heapq.heappush(pq, i)


        print('Case #{}: Dilbert should drink beverages in this order: {}.'.format(case, ' '.join(name[i] for i in order)))
        case += 1
        try:
            input()
        except:
            break
