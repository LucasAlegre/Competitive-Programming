"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin

if __name__ == '__main__':

    n = int(input())
    for _ in range(n):
        m = int(input())
        coins = [int(x) for x in input().split()]
        total = sum(coins)
        melhor = []
        custo = [0 for _ in range(int(total/2)+1)]
        for j in range(m):
            for i in range(int(total/2)):
                if i >= coins[j]:
                    if custo[i] < custo[i - coins[j]] + coins[j]:
                        custo[i] = custo[i - coins[j]] + coins[j]
        print(custo[int(total/2)])


