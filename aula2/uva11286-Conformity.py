from sys import stdin

if __name__ == '__main__':

    for line in stdin:
        n = int(line)
        if n == 0:
            break
        s = {}
        for _ in range(n):
            f = [int(x) for x in input().split()]
            f = tuple(sorted(f))
            if f in s:
                s[f] += 1
            else:
                s[f] = 1
        r = max(s.values())
        c = 0
        for f in s:
            if s[f] == r:
                c += 1
    
        print(r*c)
