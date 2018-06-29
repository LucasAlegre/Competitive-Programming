"""
Lucas Alegre - 00274693
Computer Science - UFRGS

Python 3 Competitive Programming Template

"""

from sys import stdin
from collections import deque

if __name__ == '__main__':
    
    n = int(input())
    l = deque([int(i) for i in input().split()])
    counter = 0
    arestas = 0
    arco = sum(l)/3
    
    ini = -1
    soma = 0
    while soma < arco and ini < n:
        ini += 1
        soma += l[ini]
 
    fim = ini
    soma = 0
    while soma < arco and fim < n:
        fim +=1
        soma += l[fim]

    n = fim

    for _ in range(ini):
        l.rotate(-1)
        arestas = 0
        i = 0
        while i < n and arestas != 2:
            s = l[i]
            j = i+1
            while j < n:
                if s + l[j] > arco:
                    break
                if s + l[j] == arco:
                    arestas += 1
                    i = j
                    break
                s = s + l[j]
                j += 1
            i += 1
        if arestas == 2:
            counter += 1

    print(counter)
