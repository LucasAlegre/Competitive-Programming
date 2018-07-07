"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin

if __name__ == '__main__':

    for line in stdin:
        try:
            N, M, K = [int(x) for x in line.split()]
        except:
            break
        man = dict()
        woman = dict()
        man[0] = 0
        woman[0] = 0
        for a in [int(x) for x in input().split()]:
            if a % K in man:
                man[a % K] += 1
            else:
                man[a % K] = 1
        for a in [int(x) for x in input().split()]:
            if a % K in woman:
                woman[a % K] += 1
            else:
                woman[a % K] = 1
        r = 0
        zero = 0
        for key in man.keys():
            if key != 0:
                for key2 in woman.keys():
                    if key2 != 0:
                        if key + key2 == K:
                            r += man[key]*woman[key2]

        zero = man[0] * woman[0]
        r = r + zero
        print(r)
