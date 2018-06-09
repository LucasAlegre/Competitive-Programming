"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin
from itertools import combinations

if __name__ == '__main__':

    T = int(input())
    for i in range(1, T+1):
        n = input()
        s = True
        if len(n) != 1:
            soma = sum(int(x) for x in n)
            numdiv3 = len([x for x in n if int(x) % 3 == 0])
            if soma % 3 == 0:
                if numdiv3 % 2 == 0:
                    s = False
            else:
                b = False
                for x in n:
                    if (soma - int(x)) % 3 == 0:
                        b = True
                if b:
                    if numdiv3 % 2 == 1:
                        s = False
                else:
                    s = False


        print('Case {}: {}'.format(i, 'S' if s else 'T'))
