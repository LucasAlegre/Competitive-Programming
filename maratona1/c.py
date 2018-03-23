"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin
from collections import deque

if __name__ == '__main__':

    while True:
        n = int(stdin.readline())
        if n == 0:
            break;

        l = deque([int(x) for x in stdin.readline().split()])

        a = 0
        ce = False
        while l[0] == 0:
            l.rotate(1)
            a += 1
            if a >= n:
                ce = True
                break
        
        c = 0
        r = 0
        for i in range(n):
            if l[i] == 0:
                c+=1

            else:
                if c > 1:
                    r += c//2
                c = 0
        r += c//2
        if ce and n % 2 != 0:
            r += 1

        print(r)
