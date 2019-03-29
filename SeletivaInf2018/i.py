"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from heapq import heappush, heappop, heapify

if __name__ == '__main__':

    N, M = [int(x) for x in input().split()]
    func = [int(x) for x in input().split()]
    cli = [int(x) for x in input().split()]

    h = [(0, i) for i in range(N)]
    heapify(h)

    while cli:
        c = cli.pop(0)
        f = heappop(h)
        heappush(h, (f[0]+c*func[f[1]], f[1]))

    print(max(h, key=lambda x: x[0])[0])

