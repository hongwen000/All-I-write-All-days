mo = 1e9;
mo += 7;
s = input()
s = s.split(" ")
n = int(s[0])
q = int(s[1])
ret = 0;
d = 1;
for i in range(n-q+1, n+1):
    d *= i
dor = 1;
for i in range(1, q+1):
    dor *= i;
d = d / dor
ex = 1;
for i in range(0, n-q):
    ex *= 2;
print(int((ex * d)%(mo)))