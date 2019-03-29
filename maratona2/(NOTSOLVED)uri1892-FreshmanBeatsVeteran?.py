"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin

if __name__ == '__main__':

    while True:
        try:    
            n = int(input())
            s = []
            c=0
            for i in range(n):
                a,b  = [int(x) for x in input().split('/')]
                s.append((a,b))
            for i in range(n):
                for j in range(i,n):
                    if s[i] > s[j]:
                        c+=1

            print(c)

        except:
            break
