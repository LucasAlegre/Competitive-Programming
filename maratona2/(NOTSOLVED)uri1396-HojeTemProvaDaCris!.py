"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin

if __name__ == '__main__':

    inst = 1
    while True:
        n, k = [int(x) for x in input().split()]
        if n == 0 and k == 0:
            break
        co = 0
        strings = [s for s in input().split()]
        while k > 0 and co != n:
            s = min(strings[co:co+k+1])
            si = strings[co:co+k+1].index(s)
            si += co
            del strings[si]
            strings.insert(co, s)
            k -= si
            co += 1

        print('Instancia ' + str(inst))
        print(' '.join(strings) + ' ')
        print()

        inst +=1
