"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin

if __name__ == '__main__':

    n = int(input())
    for i in range(n):
        c = 0
        s = input()
        s = s.replace('.','')
        flag=True
        while flag:
            flag = False
            for k in range(len(s)-1):
                if s[k] == '<' and s[k+1] == '>':
                    s = s[:k] + s[k+2:]
                    c += 1
                    flag = True
                    break
        print(c)
