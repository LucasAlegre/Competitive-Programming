"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""
import re


bi = [[-1 for i in range(53)] for j in range(53)]
def comb(c, n, k):
    if c[n][k] != -1:
        return c[n][k]
    if k > n:
        return 0
    if k == n or k == 0:
        return 1
    c[n][k] = comb(c, n-1,k-1) + comb(c, n-1,k)
    return c[n][k]


if __name__ == '__main__':

    t = int(input())
    for case in range(1, t+1):
        m = re.match(r'\((.+)\+(.+)\)\^(\d+)', input())
        a = m.group(1)
        b = m.group(2)
        k = int(m.group(3))
        r = ''
        for i in range(0, k+1):
            c = comb(bi, k, i)
            c = str(c)+'*' if c != 1 else ''
            ea = k-i
            ea = '^'+str(ea) if ea != 1 else ''
            eb = '^'+str(i) if i != 1 else ''
            r += c
            if ea != '^0':
                r += a + ea
            if eb != '^0':
                if ea !='^0':
                    r += '*'
                r += b + eb
            r += '+'
        print('Case {}: '.format(case) + r[:-1])
