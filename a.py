"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin


def palindrome(s):
    n = len(s)
    for i in range(n//2):
        if s[i] != s[n-i-1]:
            return False

    return True

if __name__ == '__main__':

    n = int(input())
    for _ in range(n):
        c = 0
        p = input()
        pal = True
        while not palindrome(p):
            pr = p[::-1]
            p = str(int(p) + int(pr))
            c += 1

        print(str(c) + " " + p)
