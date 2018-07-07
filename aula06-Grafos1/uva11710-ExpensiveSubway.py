"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin
import heapq

if __name__ == '__main__':

    while True:
        s, c = [int(x) for x in input().split()]
        if s == 0 and c == 0:
            break
        connected = set()
        sumt = 0
        pq = []
        g = {}

        for _ in range(s):
            g[input()] = []
        for _ in range(c):
            a,b,w = [x for x in input().split()]
            w = int(w)
            g[a].append((w, b))
            g[b].append((w, a))
        start = input()

        connected.add(start)
        for e in g[start]:
            heapq.heappush(pq, e)

        while pq and len(connected) != len(g.keys()):
            w, b = heapq.heappop(pq)
            if b not in connected:
                sumt += w
                connected.add(b)
                for e in g[b]:
                    heapq.heappush(pq, e)
        if len(connected) == len(g.keys()):
            print(sumt)
        else:
            print("Impossible")
