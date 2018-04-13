"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin

if __name__ == '__main__':

    while True:
        n, k = [int(x) for x in input().split()]
        if n == 0 and k == 0:
            break

        strings = [s for s in input().split()]
        
